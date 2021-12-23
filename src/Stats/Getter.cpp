#include "../../include/Game/Stats.hpp"

Uint8 Stats::getStrength(void) const {
    return this->m_Strength;
}

Uint8 Stats::getSpeed(void) const {
    return this->m_Speed;
}

Uint8 Stats::getMaxHp(void) const {
    return this->m_MaxHp;
}
Uint8 Stats::getHp(void) const {
    return this->m_Hp;
}
Uint8 Stats::getMaxMp(void) const {
    return this->m_MaxMp;
}
Uint8 Stats::getMp(void) const {
    return this->m_Mp;
}

Uint8 Stats::getDefense(void) const {
    return this->m_Defense;
}