#ifndef PERSONA_H
#define PERSONA_H

#include "Skill.h"

class Persona {
public:

    std::string name;

    /** Affects everything. */
    int level;
    /** Affects damage of Physical Skills (Phys & Gun). */
    int strength;
    /** Affects damage of Magical Skills (All Elements except Phys & Gun). */
    int magic;
    /** Reduces Damage recieved. */
    int endurence;
    /** Affects place in Turn Order, getting hit and landing hit chances. */
    int agility;
    /** Affects all RNG; Status Ailments, Critical Hits, Hit Chances(both ways), and Damage Radius. */
    int luck;

    Skill const* skills[6];

    Persona();
    Persona(std::string n, int lvl, int s, int m, int e, int a, int l, Skill const* Skills[], int size);
    int* getStatsAsArray();


private:

    void assignSkills(Skill const* Skills[], int size);

};

#endif