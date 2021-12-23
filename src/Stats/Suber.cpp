#include "../../include/Game/Stats.hpp"

void Stats::subHp(Uint8 hp) {
    if (this->m_Hp - hp < 0) {
        this->m_Hp = 0;
    } else {
        this->m_Hp -= hp;
    }
}
void Stats::subMp(Uint8 mp) {
    if (this->m_Mp - mp < 0) {
        this->m_Mp = 0;
    } else {
        this->m_Mp -= mp;
    }
}
void Stats::subSpeed(Uint8 speed) {
    if (this->m_Speed - speed < 0) {
        this->m_Speed = 0;
    } else {
        this->m_Speed -= speed;
    }
}
void Stats::subStrength(Uint8 strength) {
    if (this->m_Strength - strength < 0) {
        this->m_Strength = 0;
    } else {
        this->m_Strength -= strength;
    }
}
void Stats::subDefense(Uint8 defense) {
    if (this->m_Defense - defense < 0) {
        this->m_Defense = 0;
    } else {
        this->m_Defense -= defense;
    }
}