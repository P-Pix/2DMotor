#include "../../include/Stats.hpp"

Stats::Stats(void) {

}

Stats::Stats(Uint8 maxHp, Uint8 maxMp, Uint8 speed, Uint8 strength, Uint8 defense) {
    this->setMaxHp(maxHp);
    this->setMaxMp(maxMp);
    this->setSpeed(speed);
    this->setStrength(strength);
    this->setDefense(defense);
}

Stats::~Stats(void) {

}