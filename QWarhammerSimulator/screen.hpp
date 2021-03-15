#pragma once

#include <QWidget>

namespace QWarhammerSimulator
{

namespace LibWarhammerEngine
{
    class Game;
}

namespace Gui
{

    class Screen : public QWidget
    {
        Q_OBJECT

    public:
        explicit Screen(const LibWarhammerEngine::Game& game, QWidget* parent = nullptr);

        virtual ~Screen() = default;

    private:
        const LibWarhammerEngine::Game& m_game;
    };

} // namespace Gui

} // namespace QWarhammerSimulator
