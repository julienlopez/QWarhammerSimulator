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

    class Header : public QWidget
    {
        Q_OBJECT

    public:
        explicit Header(const LibWarhammerEngine::Game& game, QWidget* parent = nullptr);

        virtual ~Header() = default;

    private:
        const LibWarhammerEngine::Game& m_game;
    };

} // namespace Gui

} // namespace QWarhammerSimulator
