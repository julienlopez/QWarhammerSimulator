#pragma once

#include "army.hpp"
#include "gameboard.hpp"

#include <array>

namespace QWarhammerSimulator::LibWarhammerEngine
{

class Game
{
public:
    Game() = default;

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

    void switchToNextPlayer();

private:
    GameBoard m_board;
    std::array<Army, 2> m_armies;
    std::size_t m_current_player;
};

} // namespace QWarhammerSimulator::LibWarhammerEngine
