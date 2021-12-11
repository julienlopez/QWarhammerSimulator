#include "mainwindow.hpp"

#include "game.hpp"

#include "commandpanel.hpp"
#include "header.hpp"
#include "screen.hpp"

#include "screen_event_handler/iscreeneventhanlder.hpp"
#include "screen_event_handler/screeneventhanlderfactory.hpp"

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

    m_header = new Header{*m_game};
    vl->addWidget(m_header);

    auto* hl = new QHBoxLayout;
    m_screen = new Screen{*m_game};
    hl->addWidget(m_screen);
    auto* command_panel = new CommandPanel{*m_game};
    connect(command_panel, &CommandPanel::endPhasePressed, this, &MainWindow::switchToNextPhase);
    hl->addWidget(command_panel);
    vl->addLayout(hl);

    w->setLayout(vl);
    setCentralWidget(w);
}

MainWindow::~MainWindow() = default;

void MainWindow::switchToNextPhase()
{
    if(!m_game) return;
    m_game->endCurrentPhase();
    ScreenEventHandler::ScreenEventHandlerFactory::get(m_game->currentPhase())
        .map(std::mem_fn(&ScreenEventHandler::IScreenEventHandler::reset));
    m_header->updateGame();
    m_screen->update();
}

} // namespace QWarhammerSimulator::Gui
