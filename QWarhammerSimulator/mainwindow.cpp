#include "mainwindow.hpp"

#include "game.hpp"

#include "commandpanel.hpp"
#include "header.hpp"
#include "screen.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>

namespace QWarhammerSimulator::Gui
{

MainWindow::MainWindow(std::unique_ptr<LibWarhammerEngine::Game> game, QWidget* parent)
    : QMainWindow(parent)
    , m_game(std::move(game))
{
    auto* w = new QWidget;
    auto* vl = new QVBoxLayout;

    vl->addWidget(new Header{*m_game});

    auto* hl = new QHBoxLayout;
    hl->addWidget(new Screen{*m_game});
    hl->addWidget(new CommandPanel);
    vl->addLayout(hl);

    w->setLayout(vl);
    setCentralWidget(w);
}

MainWindow::~MainWindow() = default;

} // namespace QWarhammerSimulator::Gui
