#pragma once

#include "army.hpp"
#include "gameboard.hpp"
#include "turnphasemanager.hpp"

#include <array>

namespace QWarhammerSimulator::LibWarhammerEngine
{

class Game
{
public:
    Game() = delete;

    Game(GameBoard board);

    const GameBoard& board() const;

    /**
     * @pre index < 2
     */
    Army& army(const std::size_t index);

    /**
     * @pre index < 2
     */
    const Army& army(const std::size_t index) const;

    std::size_t currentPlayer() const;

    std::size_t otherPlayer() const;

    TurnPhase currentPhase() const;

    std::size_t currentTurnNumber() const;

    void endCurrentPhase();

private:
    GameBoard m_board;
    std::array<Army, 2> m_armies;
    TurnPhaseManager m_turn_phase;
};

} // namespace QWarhammerSimulator::LibWarhammerEngine
