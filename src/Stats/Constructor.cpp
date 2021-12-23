#include "../../include/Game/Stats.hpp"

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
void Stats::print(void) const {
    std::cout << "Stats:" << std::endl;
    std::cout << "Max HP: " << (int)this->getMaxHp() << std::endl;
    std::cout << "Max MP: " << (int)this->getMaxMp() << std::endl;
    std::cout << "Speed: " << (int)this->getSpeed() << std::endl;
    std::cout << "Strength: " << (int)this->getStrength() << std::endl;
    std::cout << "Defense: " << (int)this->getDefense() << std::endl;
}