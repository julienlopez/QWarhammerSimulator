#include "game.hpp"

#include "mainwindow.hpp"

#include <QApplication>

namespace
{

const double pi = std::acos(-1);

auto setupEmpireArmy()
{
    using namespace QWarhammerSimulator::LibWarhammerEngine;
    using namespace QWarhammerSimulator::LibGeometry;

    Army army;
    army.name = "The Empire";

    Model empire_halberdier{"empire halberdier", Point{1, 1}, Characteristics{4, 3, 3, 3, 3, 1, 3, 1, 7}};

    army.m_units.push_back({empire_halberdier, 20,  5, {20., 10.}, -pi/2});
    army.m_units.push_back({empire_halberdier, 20, 5, {40., 10.}, -pi / 2});
    army.m_units.push_back({empire_halberdier, 20, 5, {60., 10.}, -pi / 2});

    return army;
}

auto setupOrcArmy()
{
    using namespace QWarhammerSimulator::LibWarhammerEngine;
    using namespace QWarhammerSimulator::LibGeometry;

    Army army;
    army.name = "The Skaven horde";

    Model orc_boyz{"Skaven clanrat", Point{1, 1}, Characteristics{5, 3, 3, 3, 3, 1, 4, 1, 5}};

    army.m_units.push_back({orc_boyz, 20, 5, {20., 40.}, pi / 2});
    army.m_units.push_back({orc_boyz, 20, 5, {40., 40.}, pi / 2});
    army.m_units.push_back({orc_boyz, 20, 5, {60., 40.}, pi / 2});

    return army;
}

auto setupGame()
{
    using namespace QWarhammerSimulator::LibWarhammerEngine;
    using namespace QWarhammerSimulator::LibGeometry;

    auto game = std::make_unique<Game>(GameBoard{80, 50});
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
