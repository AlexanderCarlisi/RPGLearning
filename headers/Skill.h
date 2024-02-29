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

    enum Ailment {
        None,
        Burn,
        Freeze,
        Shock,
        Bleed,
        Silence,
        Poison,
        Fear,
        Charm
    };

    std::string name;
    Element element;
    Damage damage;

    Skill();
    Skill(std::string Name, Element e, Damage d, int Cost);

    static std::string elementToString(Element e);
    static std::string damageToString(Damage d);
    static Skill const* getSkill(int id);
    int calculateDamage(int userLevel, int* userStats);
    int calculateCost(int userLevel, int* userStats);

    /** List of Predefined Skills available to Personas. */
    static const Skill SKILLS[];


private:
    int baseDamage;
    int cost;

    bool repeats;
    bool randomRepeats;
    int minRepeat;
    int maxRepeat;

    bool inflictAilment;
    int inflictAilmentChance;
    Ailment ailmentToInflict;

    /** Random Number Generator. */
    static std::mt19937 generator;
    
    int damageToBaseDamage();
    int getScaleStat(int strength, int magic);
    void repeat(bool random, int min, int max);
    void inflict(int chance, Ailment ailment);
};


#endif