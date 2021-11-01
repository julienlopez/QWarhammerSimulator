#include "screen.hpp"

#include "screen_event_handler/iscreeneventhanlder.hpp"
#include "screen_event_handler/screeneventhanlderfactory.hpp"

#include "game.hpp"
#include "utils.hpp"

#include <QMouseEvent>
#include <QPainter>
#include <QResizeEvent>

using std::placeholders::_1;

namespace QWarhammerSimulator::Gui
{

using ScreenEventHandler::IScreenEventHandler;

Screen::Screen(const LibWarhammerEngine::Game& game, QWidget* parent)
    : QWidget(parent)
    , m_game(game)
    , m_offset(0, 0)
    , m_resolution_factor(-1.)
{
}

void Screen::paintEvent(QPaintEvent* evt)
{
    QPainter p{this};
    drawBackground(p);
    p.translate(m_offset);
    p.scale(m_resolution_factor, m_resolution_factor);
    drawBoard(p);
    for(std::size_t i = 0; i < 2; i++)
    {
        const auto& army = m_game.army(i);
        for(const auto& unit : army.m_units)
        {
            drawUnit(p, unit);
        }
    }
    auto event_handler = ScreenEventHandler::ScreenEventHandlerFactory::get(m_game.currentPhase());
    event_handler.map(
        std::bind(std::mem_fn(&IScreenEventHandler::drawAdditionalStates), _1, std::cref(m_game), std::ref(p)));
}

void Screen::resizeEvent(QResizeEvent* evt)
{
    const auto map_size = m_game.board().size;
    const auto screen_size = evt->size() - m_minimum_margin;
    m_resolution_factor = std::min((double)screen_size.width() / map_size.x, (double)screen_size.height() / map_size.y);
    const auto sized_map = map_size * m_resolution_factor;
    m_offset = QPoint{(int)(evt->size().width() - sized_map.x), (int)(evt->size().height() - sized_map.y)} / 2;
}

void Screen::mouseReleaseEvent(QMouseEvent* evt)
{
    auto event_handler = ScreenEventHandler::ScreenEventHandlerFactory::get(m_game.currentPhase());
    event_handler
        .map(std::bind(std::mem_fn(&IScreenEventHandler::onClick), _1, m_game, screenToBoard(evt->pos()), evt->buttons()))
        .map([this, &evt](const bool has_acted) {
            if(has_acted) evt->accept();
            update();
            return has_acted;
        });
}

void Screen::drawUnit(QPainter& p, const LibWarhammerEngine::Unit& unit) const
{
    p.save();
    auto pen = p.pen();
    pen.setColor(Qt::black);
    pen.setWidthF(0.1);
    p.setPen(pen);
    
    const auto& rect = unit.rectangle();
    Utils::drawRectangle(p, rect);

    for(std::size_t i = 0; i < unit.numberOfModels(); i++)
        Utils::drawRectangle(p, unit.modelRectangle(i));

    p.restore();
}

void Screen::drawBoard(QPainter& p) const
{
    p.save();
    p.setPen(Qt::green);
    p.setBrush(Qt::green);
    p.drawRect(0, 0, m_game.board().size.x, m_game.board().size.y);
    p.restore();
}

void Screen::drawBackground(QPainter& p) const
{
    p.save();
    p.setPen(Qt::black);
    p.setBrush(Qt::black);
    p.drawRect(rect());
    p.restore();
}

QPoint Screen::screenToBoard(const QPoint& screen_pos) const
{
    const auto res = screen_pos - m_offset;
    return {(int)(res.x() / m_resolution_factor), (int)(res.y() / m_resolution_factor)};
}

} // namespace QWarhammerSimulator::Gui
