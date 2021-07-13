#include "header.hpp"

#include "playerheader.hpp"

#include "game.hpp"

#include <QHBoxLayout>

namespace QWarhammerSimulator::Gui
{

Header::Header(const LibWarhammerEngine::Game& game, QWidget* parent)
    : QWidget(parent)
    , m_game(game)
{
    setFixedHeight(100);

    auto* lay = new QHBoxLayout;
    lay->setSpacing(0);
    lay->setContentsMargins(0, 0, 0, 0);
    for(std::size_t i = 0; i < m_widgets.size(); i++)
    {
        m_widgets[i] = setupPlayerWidget(i);
        lay->addWidget(m_widgets[i]);
    }
    setLayout(lay);
    updateGame();
}

void Header::updateGame()
{
    for(std::size_t i = 0; i < m_widgets.size(); i++)
        m_widgets[i]->setIsHighlighted(m_game.currentPlayer() != i);
    m_widgets[m_game.currentPlayer()]->setCurrentPhase(m_game.currentPhase());
}

PlayerHeader* Header::setupPlayerWidget(const std::size_t player_index)
{
    return new PlayerHeader(QString::fromStdString(m_game.army(player_index).name));
}

} // namespace QWarhammerSimulator::Gui
