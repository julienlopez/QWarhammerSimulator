#include "shooting.hpp"

#include "screeneventhanlderfactory.hpp"

#include "../utils.hpp"

#include "game.hpp"

#include <iostream>

#include <QPainter>

namespace QWarhammerSimulator::Gui::ScreenEventHandler
{

namespace
{
    LibGeometry::Point toPoint(const QPoint& qpoint)
    {
        return {(double)(qpoint.x()), (double)(qpoint.y())};
    }

} // namespace

bool Shooting::onClick(const LibWarhammerEngine::Game& game, const QPoint& pos, const Qt::MouseButtons buttons)
{
    std::cout << "Shooting::onClick(" << toPoint(pos) << ")" << std::endl;
    m_current_selection = unitIndex(game.army(game.currentPlayer()), pos);
    return m_current_selection
        .map([this, &game](const std::size_t unit_index) {
            std::cout << "Unit clicked : " << unit_index << std::endl;
            const auto& unit = game.army(game.currentPlayer()).m_units[unit_index];
            std::cout << unit.rectangle().topLeft() << std::endl;
            std::cout << unit.rectangle().bottomRight() << std::endl;
            return true;
        })
        .value_or_eval([this]() {
            m_current_selection = boost::none;
            return false;
        });
}

bool Shooting::drawAdditionalStates(const LibWarhammerEngine::Game& game, QPainter& p) const
{
    return m_current_selection
        .map([this, &game, &p](const std::size_t unit_index) {
            const auto& unit = game.army(game.currentPlayer()).m_units[unit_index];
            p.save();
            auto pen = p.pen();
            pen.setColor(Qt::yellow);
            pen.setWidthF(0.2);
            p.setPen(pen);
            Utils::drawRectangle(p, unit.rectangle());
            p.restore();
            return true;
        })
        .value_or(false);
}

boost::optional<std::size_t> Shooting::unitIndex(const LibWarhammerEngine::Army& army, const QPoint& pos) const
{
    for(std::size_t i = 0; i < army.m_units.size(); i++)
    {
        if(army.m_units[i].rectangle().contains(toPoint(pos))) return i;
    }
    return boost::none;
}

const bool Shooting::c_is_registered
    = ScreenEventHandlerFactory::registerHandler(LibWarhammerEngine::TurnPhase::Shooting, std::make_unique<Shooting>());

} // namespace QWarhammerSimulator::Gui::ScreenEventHandler
