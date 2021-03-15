#pragma once

#include <QMainWindow>

namespace QWarhammerSimulator
{

namespace LibWarhammerEngine
{
    class Game;
}

namespace Gui
{

    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit MainWindow(std::unique_ptr<LibWarhammerEngine::Game> game, QWidget* parent = nullptr);

        virtual ~MainWindow();

    private:
        std::unique_ptr<LibWarhammerEngine::Game> m_game;
    };

} // namespace Gui

} // namespace QWarhammerSimulator
