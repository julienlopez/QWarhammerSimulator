#include "mainwindow.hpp"

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
    if(!game) m_game = std::make_unique<LibWarhammerEngine::Game>();

    auto* w = new QWidget;
    auto* vl = new QVBoxLayout;

    vl->addWidget(new Header);

    auto* hl = new QHBoxLayout;
    hl->addWidget(new Screen);
    hl->addWidget(new CommandPanel);
    vl->addLayout(hl);

    w->setLayout(vl);
    setCentralWidget(w);
}

} // namespace QWarhammerSimulator::Gui
