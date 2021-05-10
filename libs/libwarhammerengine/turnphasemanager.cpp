#include "turnphasemanager.hpp"

namespace QWarhammerSimulator::LibWarhammerEngine
{

TurnPhase TurnPhaseManager::currentPhase() const
{
    return m_current_phase;
}

std::size_t TurnPhaseManager::currentPlayer() const
{
    return m_current_player;
}

std::size_t TurnPhaseManager::currentTurnNumber() const
{
    return m_current_turn_number;
}

void TurnPhaseManager::endCurrentPhase()
{
    if(m_current_phase == TurnPhase::CloseCombat)
    {
        m_current_phase = TurnPhase::Movement;
        m_current_player++;
        if(m_current_player == 2)
        {
            m_current_player = 0;
            m_current_turn_number++;
        }
    }
    else
    {
        m_current_phase = TurnPhase{static_cast<std::underlying_type<TurnPhase>::type>(m_current_phase)+1};
    }
}

} // namespace QWarhammerSimulator::LibWarhammerEngine
