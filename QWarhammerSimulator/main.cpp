#include "game.hpp"

#include "mainwindow.hpp"

#include <QApplication>

namespace
{
auto setupEmpireArmy()
{
    using namespace QWarhammerSimulator::LibWarhammerEngine;
    using namespace QWarhammerSimulator::LibGeometry;

    Army army;
    army.name = "The Empire";

    Model empire_halberdier{"empire halberdier", Point{1, 1}, Characteristics{4, 3, 3, 3, 3, 1, 3, 1, 7}};

    army.m_units.push_back({empire_halberdier, 20, 5, {10., 10.}});
    army.m_units.push_back({empire_halberdier, 20, 5, {30., 10.}});

    return army;
}

auto setupOrcArmy()
{
    using namespace QWarhammerSimulator::LibWarhammerEngine;
    using namespace QWarhammerSimulator::LibGeometry;

    Army army;
    army.name = "The Orc horde";

    return army;
}

auto setupGame()
{
    using namespace QWarhammerSimulator::LibWarhammerEngine;
    using namespace QWarhammerSimulator::LibGeometry;

    auto game = std::make_unique<Game>(GameBoard{75, 50});
    game->army(0) = setupEmpireArmy();
    game->army(1) = setupOrcArmy();

    return game;
}

}

int main(int argc, char* argv[])
{
    QApplication app{argc, argv};
    QWarhammerSimulator::Gui::MainWindow m{setupGame()};
    m.showMaximized();
    return app.exec();
}
