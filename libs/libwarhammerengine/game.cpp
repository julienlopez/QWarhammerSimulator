#include "game.hpp"

namespace QWarhammerSimulator::LibWarhammerEngine
{

Game::Game(GameBoard board)
    : m_board(std::move(board))
{
}

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
    return m_turn_phase.currentPlayer();
}

std::size_t Game::otherPlayer() const
{
    return m_turn_phase.otherPlayer();
}

TurnPhase Game::currentPhase() const
{
    return m_turn_phase.currentPhase();
}

std::size_t Game::currentTurnNumber() const
{
    return m_turn_phase.currentTurnNumber();
}

void Game::endCurrentPhase()
{
    m_turn_phase.endCurrentPhase();
}

} // namespace QWarhammerSimulator::LibWarhammerEngine
