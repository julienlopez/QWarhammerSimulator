#pragma once

#include <cstdint>

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
};

} // namespace QWarhammerSimulator::LibWarhammerEngine
