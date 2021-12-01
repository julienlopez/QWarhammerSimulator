#pragma once

#include <QPoint>

#include <boost/signals2/signal.hpp>

class QPainter;

namespace QWarhammerSimulator
{

namespace LibWarhammerEngine
{
    class Game;
}

namespace Gui::ScreenEventHandler
{

    class IScreenEventHandler
    {
    public:
        using VoidSignal_t = boost::signals2::signal<void()>;

    protected:
        explicit IScreenEventHandler() = default;

        VoidSignal_t m_update_signal;

    public:
        virtual ~IScreenEventHandler() = default;

        virtual bool reset() = 0;

        virtual bool onMouseClick(const LibWarhammerEngine::Game& game, const QPoint& pos,
                                  const Qt::MouseButtons buttons)
            = 0;

        virtual bool onMouseMove(const LibWarhammerEngine::Game& game, const QPoint& pos)
        {
            return false;
        }

        virtual bool drawAdditionalStates(const LibWarhammerEngine::Game& game, QPainter& p) const = 0;

        auto onUpdate(const VoidSignal_t::slot_type& slot)
        {
            return m_update_signal.connect(slot);
        }
    };

} // namespace Gui::ScreenEventHandler

} // namespace QWarhammerSimulator
