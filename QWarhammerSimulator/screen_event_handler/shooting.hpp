#pragma once

#include "iscreeneventhanlder.hpp"

#include "../selection.hpp"

#include <boost/optional.hpp>

namespace QWarhammerSimulator
{

namespace LibWarhammerEngine
{
    class Army;
}

namespace Gui::ScreenEventHandler
{

    class Shooting : public IScreenEventHandler
    {
    public:
        explicit Shooting() = default;

        virtual ~Shooting() = default;

        virtual bool reset() override;

        virtual bool onMouseClick(const LibWarhammerEngine::Game& game, const QPoint& pos,
                                  const Qt::MouseButtons buttons) override;

        virtual bool onMouseMove(const LibWarhammerEngine::Game& game, const QPoint& pos) override;

        virtual bool drawAdditionalStates(const LibWarhammerEngine::Game& game, QPainter& p) const override;

    private:
        boost::optional<UnitIndex> unitIndex(const LibWarhammerEngine::Game& game, const std::size_t player, const QPoint& pos) const;

        static const bool c_is_registered;

        boost::optional<SelectionWithColor> m_current_selection;
        boost::optional<SelectionWithColor> m_current_target;
        boost::optional<SelectionWithColor> m_current_hover;

        bool selectShooter(const LibWarhammerEngine::Game& game, const QPoint& pos);

        /**
         * @pre m_current_selection.has_value()
         */
        bool selectTarget(const LibWarhammerEngine::Game& game, const QPoint& pos);

    };

} // namespace Gui::ScreenEventHandler

} // namespace QWarhammerSimulator
