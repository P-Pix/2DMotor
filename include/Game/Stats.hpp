#pragma once

#include <iostream>
#include <SDL2/SDL.h>

class Stats {
private:
    Uint8 m_MaxHp = 0;
    Uint8 m_Hp = 0;
    Uint8 m_MaxMp = 0;
    Uint8 m_Mp = 0;
    Uint8 m_Speed = 0;
    Uint8 m_Strength = 0;
    Uint8 m_Defense = 0;

protected:
    void setMaxHp(Uint8 hp);
    void setHp(Uint8 hp);
    void setMaxMp(Uint8 mp);
    void setMp(Uint8 mp);
    void setSpeed(Uint8 speed);
    void setStrength(Uint8 strength);
    void setDefense(Uint8 defense);

public:
    Stats(void);
    Stats(Uint8 maxHp, Uint8 maxMp, Uint8 speed, Uint8 strength, Uint8 defense);
    ~Stats(void);

    Uint8 getMaxHp(void) const;
    Uint8 getHp(void) const;
    Uint8 getMaxMp(void) const;
    Uint8 getMp(void) const;
    Uint8 getSpeed(void) const;
    Uint8 getStrength(void) const;
    Uint8 getDefense(void) const;

    void addHp(Uint8 hp);
    void addMp(Uint8 mp);
    void addSpeed(Uint8 speed);
    void addStrength(Uint8 strength);
    void addDefense(Uint8 defense);

    void subHp(Uint8 hp);
    void subMp(Uint8 mp);
    void subSpeed(Uint8 speed);
    void subStrength(Uint8 strength);
    void subDefense(Uint8 defense);

    void print(void) const;
};