#include "screen.hpp"

#include "screen_event_handler/iscreeneventhanlder.hpp"
#include "screen_event_handler/screeneventhanlderfactory.hpp"

#include "game.hpp"

#include <QMouseEvent>
#include <QPainter>
#include <QResizeEvent>

namespace QWarhammerSimulator::Gui
{

Screen::Screen(const LibWarhammerEngine::Game& game, QWidget* parent)
    : QWidget(parent)
    , m_game(game)
{
}

void Screen::paintEvent(QPaintEvent* evt)
{
    QPainter p{this};
    drawBoard(p);
    for(std::size_t i = 0; i < 2; i++)
    {
        const auto& army = m_game.army(i);
        for(const auto& unit : army.m_units)
        {
            drawUnit(p, unit);
        }
    }
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
    auto* event_handler = ScreenEventHandler::ScreenEventHandlerFactory::get(m_game.currentPhase());
    if(event_handler)
    {
        event_handler->onClick(evt->pos(), evt->buttons());
        evt->accept();
    }
}

void Screen::drawUnit(QPainter& p, const LibWarhammerEngine::Unit& unit) const
{
    p.save();
    auto pen = p.pen();
    pen.setColor(Qt::black);
    pen.setWidthF(0.1);
    p.setPen(pen);
    const auto& rect = unit.rectangle();
    p.drawRect(rect.topLeft().x, rect.topLeft().y, rect.width(), rect.height());
    p.restore();
}

void Screen::drawBoard(QPainter& p) const
{
    p.save();
    p.setPen(Qt::black);
    p.setBrush(Qt::black);
    p.drawRect(rect());
    p.restore();

    p.translate(m_offset);
    p.scale(m_resolution_factor, m_resolution_factor);

    p.save();
    p.setPen(Qt::green);
    p.setBrush(Qt::green);
    p.drawRect(0, 0, m_game.board().size.x, m_game.board().size.y);
    p.restore();
}

} // namespace QWarhammerSimulator::Gui
