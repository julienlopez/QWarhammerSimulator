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

        virtual bool onMouseClick(const LibWarhammerEngine::Game& game, const QPoint& pos,
                                  const Qt::MouseButtons buttons) override;

        virtual bool onMouseMove(const LibWarhammerEngine::Game& game, const QPoint& pos) override;

        virtual bool drawAdditionalStates(const LibWarhammerEngine::Game& game, QPainter& p) const override;

    private:
        boost::optional<std::size_t> unitIndex(const LibWarhammerEngine::Army& army, const QPoint& pos) const;

        static const bool c_is_registered;

        boost::optional<Selection> m_current_selection;
        boost::optional<Selection> m_current_target;

        bool selectShooter(const LibWarhammerEngine::Game& game, const QPoint& pos);

        /**
         * @pre m_current_selection.has_value()
         */
        bool selectTarget(const LibWarhammerEngine::Game& game, const QPoint& pos);
    };

} // namespace Gui::ScreenEventHandler

} // namespace QWarhammerSimulator
