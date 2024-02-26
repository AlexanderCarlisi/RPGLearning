#ifndef UNIT_H
#define UNIT_H

#include "Persona.h"

class Unit {
public:
    std::string name;

    int health;
    int maxHealth;
    int mana;
    int maxMana;

    Persona persona;

    Unit();
    Unit(std::string Name, int Health, int Mana, Persona P);
};

#endif