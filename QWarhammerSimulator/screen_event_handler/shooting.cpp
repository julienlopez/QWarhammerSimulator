#include "shooting.hpp"

#include "screeneventhanlderfactory.hpp"

#include "../utils.hpp"

#include "game.hpp"

#include <iostream>

#include <gsl/gsl_assert>

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

bool Shooting::onMouseClick(const LibWarhammerEngine::Game& game, const QPoint& pos, const Qt::MouseButtons buttons)
{
    std::cout << "Shooting::onClick(" << toPoint(pos) << ")" << std::endl;
    if(m_current_selection)
        return selectTarget(game, pos);
    else
        return selectShooter(game, pos);
}

bool Shooting::onMouseMove(const LibWarhammerEngine::Game& game, const QPoint& pos)
{
    return false;
}

bool Shooting::drawAdditionalStates(const LibWarhammerEngine::Game& game, QPainter& p) const
{
    return m_current_selection
        .map([this, &game, &p](const Selection selection) {
            Utils::paintSelection(p, game, selection, Qt::yellow);
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

bool Shooting::selectShooter(const LibWarhammerEngine::Game& game, const QPoint& pos)
{
    m_current_selection = unitIndex(game.army(game.currentPlayer()), pos);
    return m_current_selection
        .map([this, &game](const Selection selection) {
            std::cout << "Unit clicked : " << selection.unit_index << std::endl;
            const auto& unit = game.army(game.currentPlayer()).m_units[selection.unit_index];
            std::cout << unit.rectangle().topLeft() << std::endl;
            std::cout << unit.rectangle().bottomRight() << std::endl;
            return true;
        })
        .value_or_eval([this]() {
            m_current_selection = boost::none;
            return false;
        });
}

bool Shooting::selectTarget(const LibWarhammerEngine::Game& game, const QPoint& pos)
{
    Expects(m_current_selection.has_value());
    const auto target = unitIndex(game.army(game.currentPlayer() + 1 % 2), pos);
}

} // namespace QWarhammerSimulator::Gui::ScreenEventHandler
