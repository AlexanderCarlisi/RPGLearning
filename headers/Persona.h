#ifndef PERSONA_H
#define PERSONA_H

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

    Persona();
    Persona(std::string n, int lvl, int s, int m, int e, int a, int l);
    int* getStatsAsArray();

};

#endif