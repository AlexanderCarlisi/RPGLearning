#ifndef SKILL_H
#define SKILL_H

#include <string>
#include <random>

class Skill {
public:

    enum Element {
        Almighty,
        Phys,
        Gun,
        Fire,
        Ice,
        Wind,
        Elec,
        Dark,
        Light
    };

    enum Damage {
        Weak,
        Medium,
        Heavy,
        Severe,
        Massive,
        Colossal
    };

    std::string name;
    Element element;
    Damage damage;

    Skill();
    Skill(std::string Name, Element e, Damage d, int Cost);

    static std::string elementToString(Element e);
    static std::string damageToString(Damage d);
    int calculateDamage(int userLevel, int* userStats);
    int calculateCost(int userLevel, int* userStats);


private:
    int baseDamage;
    int cost;

    bool repeats;
    bool randomRepeats;
    int minRepeat;
    int maxRepeat;

    /** Random Number Generator. */
    static std::mt19937 generator;
    
    int damageToBaseDamage();
    int getScaleStat(int strength, int magic);
};


#endif