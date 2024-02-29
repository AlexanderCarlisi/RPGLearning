#include "../headers/Persona.h"
#include <string>

#include <iostream>


/** Default Constructor. */
Persona::Persona() : Persona("Blank", 1, 1, 1, 1, 1, 1, { }, 0) { }

/**
 * Construct the Persona Class.
 * 
 * @param lvl   :   Level
 * @param s     :   Strength Stat
 * @param m     :   Magic Stat
 * @param e     :   Endurence Stat
 * @param a     :   Agility Stat
 * @param l     :   Luck Stat
 * @param Skills :   Skill Pointer Array
 * 
*/
Persona::Persona(std::string n, int lvl, int s, int m, int e, int a, int l, Skill const* Skills[], int size) {
    this->name = n;
    this->level = lvl;
    this->strength = s;
    this->magic = m;
    this->endurence = e;
    this->agility = a;
    this->luck = l;
    assignSkills(Skills, size);
}

/**
 * Order of Array {Strength, Magic, Endurence, Agility, Luck}
 * 
 * @return an ordered array of this Persona's stats.
 * 
*/
int* Persona::getStatsAsArray() {
    int* arr = new int[5];
    arr[0] = this->strength;
    arr[1] = this->magic;
    arr[2] = this->endurence;
    arr[3] = this->agility;
    arr[4] = this->luck;
    return arr;
}


/**
 * Set this Persona's skill array to the parameters.
 * 
 * @param Skills        :   Pointer Array to set to.
*/
void Persona::assignSkills(Skill const* Skills[], int size) {
    if (size <= 0) return;
    for (int i = 0; i < size; i++) {
        if (Skills[i] != nullptr)
            this->skills[i] = Skills[i];
    }
}