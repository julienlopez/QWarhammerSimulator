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

    public slots:
        void updateGame();

    private:
        const LibWarhammerEngine::Game& m_game;
        std::array<QWidget*, 2> m_widgets;

        QWidget* setupPlayerWidget(const std::size_t player_index);
    };

} // namespace Gui

} // namespace QWarhammerSimulator
