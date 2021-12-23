#include "../../include/Game/Stats.hpp"

void Stats::addHp(Uint8 hp) {
    if (this->m_Hp + hp > this->m_MaxHp) {
        this->m_Hp = this->m_MaxHp;
    } else {
        this->m_Hp += hp;
    }
}
void Stats::addMp(Uint8 mp) {
    if (this->m_Mp + mp > this->m_MaxMp) {
        this->m_Mp = this->m_MaxMp;
    } else {
        this->m_Mp += mp;
    }
}
void Stats::addSpeed(Uint8 speed) {
    this->m_Speed += speed;
}
void Stats::addStrength(Uint8 strength) {
    this->m_Strength += strength;
}
void Stats::addDefense(Uint8 defense) {
    this->m_Defense += defense;
}