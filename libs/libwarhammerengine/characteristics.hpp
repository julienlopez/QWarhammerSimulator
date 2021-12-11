#pragma once

#include <cstdint>

#include <gsl/gsl_assert>

namespace QWarhammerSimulator::LibWarhammerEngine
{

struct Characteristics
{
    using Type = std::int8_t;

    // Movement (M)
    Type m;

    // Weapon Skill (WS)
    Type ws;

    // Ballistic Skill (BS)
    Type bs;

    // Strength (S)
    Type s;

    // Toughness (T)
    Type t;

    // Wounds (W)
    Type w;

    // INITIATIVE (I)
    Type i;

    // ATTACKS (A)
    Type a;

    // LEADERSHIP (Ld)
    Type ld;

    constexpr static std::size_t number_of_stats()
    {
        return 9;
    }

    /**
     * @pre index < number_of_stats()
     */
    Type value(const std::size_t index) const
    {
        Expects(index < number_of_stats());
        switch(index)
        {
        case 0:
            return m;
        case 1:
            return ws;
        case 2:
            return bs;
        case 3:
            return s;
        case 4:
            return t;
        case 5:
            return w;
        case 6:
            return i;
        case 7:
            return a;
        case 8:
            return ld;
        }
    }
};

} // namespace QWarhammerSimulator::LibWarhammerEngine
