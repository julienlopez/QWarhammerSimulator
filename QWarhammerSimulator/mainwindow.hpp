#pragma once

#include "game.hpp"

#include <QMainWindow>

namespace QWarhammerSimulator::Gui
{

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(std::unique_ptr<LibWarhammerEngine::Game> game, QWidget* parent = nullptr);

    virtual ~MainWindow() = default;

private:
    std::unique_ptr<LibWarhammerEngine::Game> m_game;
};

} // namespace QWarhammerSimulator::Gui
