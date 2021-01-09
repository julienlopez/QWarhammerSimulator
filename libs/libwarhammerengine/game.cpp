#include "game.hpp"

namespace QWarhammerSimulator::LibWarhammerEngine
{

const GameBoard& Game::board() const
{
    return m_board;
}

Army& Game::army(const std::size_t index)
{
    return m_armies[index];
}

const Army& Game::army(const std::size_t index) const
{
    return m_armies[index];
}

std::size_t Game::currentPlayer() const
{
    return m_current_player;
}

void Game::switchToNextPlayer()
{
    m_current_player = m_current_player + 1 % m_armies.size();
}

} // namespace QWarhammerSimulator::LibWarhammerEngine
