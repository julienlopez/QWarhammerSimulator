#include <catch2/catch.hpp>

#include "turnphasemanager.hpp"

using QWarhammerSimulator::LibWarhammerEngine::TurnPhase;
using QWarhammerSimulator::LibWarhammerEngine::TurnPhaseManager;

namespace
{

struct IsInStateMatcher : Catch::MatcherBase<TurnPhaseManager>
{
    IsInStateMatcher(const TurnPhase phase, const std::size_t player, const std::size_t turn)
        : m_phase{phase}
        , m_player{player}
        , m_turn{turn}
    {
    }

    bool match(const TurnPhaseManager& current) const
    {
        return current.currentPhase() == m_phase && current.currentPlayer() == m_player
               && current.currentTurnNumber() == m_turn;
    }

    std::string describe() const override
    {
        return "IsInState: " + std::to_string(static_cast<int>(m_phase)) + ", " + std::to_string(m_player) + ", "
               + std::to_string(m_turn);
    }

private:
    const TurnPhase m_phase;
    const std::size_t m_player;
    const std::size_t m_turn;
};

IsInStateMatcher IsInState(const TurnPhase phase, const std::size_t player, const std::size_t turn)
{
    return {phase, player, turn};
}

} // namespace

TEST_CASE("Basic Turn Phase Cycling", "[LibWarhammerEngine]")
{

    SECTION("the default turn order")
    {
        TurnPhaseManager m;
        CHECK_THAT(m, IsInState(TurnPhase::Movement, 0, 0));

        m.endCurrentPhase();
        CHECK_THAT(m, IsInState(TurnPhase::Magic, 0, 0));

        m.endCurrentPhase();
        CHECK_THAT(m, IsInState(TurnPhase::Shooting, 0, 0));

        m.endCurrentPhase();
        CHECK_THAT(m, IsInState(TurnPhase::CloseCombat, 0, 0));

        m.endCurrentPhase();
        CHECK_THAT(m, IsInState(TurnPhase::Movement, 1, 0));

        m.endCurrentPhase();
        CHECK_THAT(m, IsInState(TurnPhase::Magic, 1, 0));

        m.endCurrentPhase();
        CHECK_THAT(m, IsInState(TurnPhase::Shooting, 1, 0));

        m.endCurrentPhase();
        CHECK_THAT(m, IsInState(TurnPhase::CloseCombat, 1, 0));

        m.endCurrentPhase();
        CHECK_THAT(m, IsInState(TurnPhase::Movement, 0, 1));
    }
}
