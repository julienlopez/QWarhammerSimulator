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

    auto drawSelection(const LibWarhammerEngine::Game& game, QPainter& p)
    {
        return [&](const SelectionWithColor& selection) -> bool
        {
            Utils::paintSelection(p, game, selection);
            return true;
        };
    }

    auto addColor(const QColor& color, const double width)
    {
        return [=](const Selection& selection) { return SelectionWithColor{selection, color, width}; };
    }

    auto paintOrClear(boost::optional<SelectionWithColor>& variable)
    {
        return [&variable](const boost::optional<SelectionWithColor>& selection)
        {
            const auto res = variable.has_value() == selection.has_value();
            variable = selection;
            return res;
        };
    }

} // namespace

bool Shooting::reset()
{
    m_current_selection = boost::none;
    m_current_target = boost::none;
    m_current_hover = boost::none;
    return true;
}

bool Shooting::onMouseClick(const LibWarhammerEngine::Game& game, const QPoint& pos, const Qt::MouseButtons buttons)
{
    if(m_current_selection)
        return selectTarget(game, pos);
    else
        return selectShooter(game, pos);
}

bool Shooting::onMouseMove(const LibWarhammerEngine::Game& game, const QPoint& pos)
{
    if(m_current_selection && m_current_target) return false;
    const QColor color{m_current_selection ? Qt::red : Qt::yellow};
    const auto player{m_current_selection ? game.otherPlayer() : game.currentPlayer()};
    return paintOrClear(m_current_hover)(unitIndex(game, player, pos).map(addColor(color, 0.1)));
}

bool Shooting::drawAdditionalStates(const LibWarhammerEngine::Game& game, QPainter& p) const
{
    m_current_hover.map(drawSelection(game, p));
    m_current_selection.map(drawSelection(game, p));
    m_current_target.map(drawSelection(game, p));
    return true;
}

boost::optional<UnitIndex> Shooting::unitIndex(const LibWarhammerEngine::Game& game, const std::size_t player,
                                               const QPoint& pos) const
{
    const auto& army = game.army(player);
    for(std::size_t i = 0; i < army.m_units.size(); i++)
    {
        if(army.m_units[i].rectangle().contains(toPoint(pos))) return UnitIndex{player, i};
    }
    return boost::none;
}

const bool Shooting::c_is_registered
    = ScreenEventHandlerFactory::registerHandler(LibWarhammerEngine::TurnPhase::Shooting, std::make_unique<Shooting>());

bool Shooting::selectShooter(const LibWarhammerEngine::Game& game, const QPoint& pos)
{
    const auto shooter = unitIndex(game, game.currentPlayer(), pos);
    return paintOrClear(m_current_selection)(shooter.map(addColor(Qt::yellow, 0.2)));
}

bool Shooting::selectTarget(const LibWarhammerEngine::Game& game, const QPoint& pos)
{
    Expects(m_current_selection.has_value());
    const auto target = unitIndex(game, game.otherPlayer(), pos);
    return paintOrClear(m_current_target)(target.map(addColor(Qt::red, 0.2)));
}

} // namespace QWarhammerSimulator::Gui::ScreenEventHandler
