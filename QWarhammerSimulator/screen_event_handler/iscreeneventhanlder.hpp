#pragma once

#include <QPoint>

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
    protected:
        explicit IScreenEventHandler() = default;

    public:
        virtual ~IScreenEventHandler() = default;

        virtual bool onMouseClick(const LibWarhammerEngine::Game& game, const QPoint& pos,
                                  const Qt::MouseButtons buttons)
            = 0;

        virtual bool onMouseMove(const LibWarhammerEngine::Game& game, const QPoint& pos)
        {
            return false;
        }

        virtual bool drawAdditionalStates(const LibWarhammerEngine::Game& game, QPainter& p) const = 0;
    };

} // namespace Gui::ScreenEventHandler

} // namespace QWarhammerSimulator
