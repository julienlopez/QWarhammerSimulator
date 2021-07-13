#pragma once

#include <utility>

namespace QWarhammerSimulator::LibWarhammerEngine
{

enum class TurnPhase
{
    Movement = 0,
    Magic,
    Shooting,
    CloseCombat
};

class TurnPhaseManager
{
public:
    TurnPhaseManager() = default;
    ~TurnPhaseManager() = default;

    TurnPhase currentPhase() const;

    std::size_t currentPlayer() const;

    std::size_t currentTurnNumber() const;

    void endCurrentPhase();

private:
    TurnPhase m_current_phase = TurnPhase::Movement;
    std::size_t m_current_player = 0;
    std::size_t m_current_turn_number = 0;
};

} // namespace QWarhammerSimulator::LibWarhammerEngine
