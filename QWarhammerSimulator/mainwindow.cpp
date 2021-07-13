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

    auto* m_header = new Header{*m_game};
    vl->addWidget(m_header);

    auto* hl = new QHBoxLayout;
    hl->addWidget(new Screen{*m_game});
    auto* command_panel = new CommandPanel;
    connect(command_panel, &CommandPanel::endPhasePressed, [this, m_header]() {
        m_game->endCurrentPhase();
        m_header->updateGame();
    });
    hl->addWidget(command_panel);
    vl->addLayout(hl);

    w->setLayout(vl);
    setCentralWidget(w);
}

MainWindow::~MainWindow() = default;

} // namespace QWarhammerSimulator::Gui
