#include "shooting.hpp"

#include "screeneventhanlderfactory.hpp"

#include "game.hpp"

#include <iostream>

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
    const auto unit_index = unitIndex(game.army(game.currentPlayer()), pos);
    if(unit_index)
    {
        std::cout << "Unit clicked : " << *unit_index << std::endl;
        const auto& unit = game.army(game.currentPlayer()).m_units[*unit_index];
        std::cout << unit.rectangle().topLeft() << std::endl;
        std::cout << unit.rectangle().bottomRight() << std::endl;
    }
    return false;
}

std::optional<std::size_t> Shooting::unitIndex(const LibWarhammerEngine::Army& army, const QPoint& pos) const
{
    for(std::size_t i = 0; i < army.m_units.size(); i++)
    {
        if(army.m_units[i].rectangle().contains(toPoint(pos))) return i;
    }
    return std::nullopt;
}

const bool Shooting::c_is_registered
    = ScreenEventHandlerFactory::registerHandler(LibWarhammerEngine::TurnPhase::Shooting, std::make_unique<Shooting>());

} // namespace QWarhammerSimulator::Gui::ScreenEventHandler
