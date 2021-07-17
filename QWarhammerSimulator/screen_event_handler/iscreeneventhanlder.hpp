#pragma once

#include <QPoint>

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

        virtual bool onClick(const LibWarhammerEngine::Game& game, const QPoint& pos, const Qt::MouseButtons buttons)
            = 0;
    };

} // namespace Gui::ScreenEventHandler

} // namespace QWarhammerSimulator
