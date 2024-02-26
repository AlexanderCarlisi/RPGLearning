#include "../headers/Unit.h"
#include <string>


/** Default Constructor. */
Unit::Unit() : Unit("Blank", 1, 1, Persona()) { }

/**
 * Construct the Unit Class.
 * 
 * @param Name      :   Name
 * @param Health    :   Max/Current Health
 * @param Mana      :   Max/Current Mana
 * @param P         :   Persona
 * 
 */
Unit::Unit(std::string Name, int Health, int Mana, Persona P) {
    this->name = Name;
    this->health = Health;
    this->maxHealth = Health;
    this->mana = Mana;
    this->maxMana = Mana;
    this->persona = P;
}