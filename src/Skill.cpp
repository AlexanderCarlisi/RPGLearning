#include "../headers/Skill.h"
#include <string>
#include <random>


/** Initialize static Random Number Generator. */
std::mt19937 Skill::generator(std::random_device{}());

/** Default Constructor. */
Skill::Skill() : Skill("Blank", Element::Almighty, Damage::Weak, 0) { }

/**
 * Constructs the Skill Class.
 * 
 * @param Name      :   Name of the Skill
 * @param e         :   Enum Element
 * @param d         :   Enum Damage
 * @param Cost      :   Base Cost of the Skill
*/
Skill::Skill(std::string Name, Element e, Damage d, int Cost) {
    this->name = Name;
    this->element = e;
    this->damage = d;
    this->cost = Cost;
    this->baseDamage = damageToBaseDamage();
}

/**
 * Converts Element to a String.
 * 
 * @param e     :   Element to convert
 * @return Element as a String.
*/
std::string Skill::elementToString(Element e) {
    switch(e) {
        case Element::Almighty : return "Almighty";
        case Element::Phys : return "Physical";
        case Element::Gun : return "Pierce";
        case Element::Fire : return "Fire";
        case Element::Ice : return "Ice";
        case Element::Wind : return "Wind";
        case Element::Elec : return "Electric";
        case Element::Dark : return "Dark";
        case Element::Light : return "Light";
        default : return "Almighty";
    }
}

/**
 * Converts Damage to a String.
 * 
 * @param d     :   Damage to convert
 * @return Damage as a String.
*/
std::string Skill::damageToString(Damage d) {
    switch(d) {
        case Damage::Weak : return "Weak";
        case Damage::Medium : return "Medium";
        case Damage::Heavy : return "Heavy";
        case Damage::Severe : return "Severe";
        case Damage::Massive : return "Massive";
        case Damage::Colossal : return "Colossal";
    }
}

/**
 * Calculates Damage based on Skill and User of the Skills Stats.
 * 
 * @param userLevel     :   Level of the Skill User
 * @param userStats     :   Integer pointer of the User of the Skills Stats
 * @return Calculated Damage as Integer.
*/
int Skill::calculateDamage(int userLevel, int* userStats) {
    // Stat Declaration
    int scaleStat = getScaleStat(userStats[0], userStats[1]);
    int luckStat = userStats[4];

    // Percent Damage
    int minPercent = (luckStat / 10) + 90;
    int maxPercent = (luckStat / 3) + 100;
    std::uniform_int_distribution<int> dist(minPercent, maxPercent);
    int rngPercent = dist(generator);

    return (userLevel * scaleStat) / this->baseDamage * rngPercent;
}

/**
 * Calculates Skill Cost based on the Skill and User of the Skills stats.
 * 
 * @param userLevel     :   Level of the Skill User
 * @param userStats     :   Integer pointer of the User of the Skills stats.
 * @return Calculated Skill Cost as an Integer.
*/
int Skill::calculateCost(int userLevel, int* userStats) {
    int scaleStat = getScaleStat(userStats[0], userStats[1]);
    return (userLevel * scaleStat) / this->cost;
}

/**
 * Get Stat to Scale Calculations off.
 * 
 * @param strength      :   Strength stat of the Skill User
 * @param magic         :   Magic stat of the Skill User
 * @return Strength stat if Physical Skill, and Magic stat if Magical Skill.
*/
int Skill::getScaleStat(int strength, int magic) {
    // Physical Skills scales off Strength, Magical Skills scales off Magic.
    return (this->element == Element::Phys || this->element == Element::Gun) ? strength : magic;
}

/**
 * Get baseDamage based on Damage enum of this Skill.
 * 
 * @return Integer baseDamage.
*/
int Skill::damageToBaseDamage() {
    switch(this->damage) {
        case Damage::Weak : return 5;
        case Damage::Medium : return 10;
        case Damage::Heavy : return 15;
        case Damage::Severe : return 20;
        case Damage::Massive : return 23;
        case Damage::Colossal : return 25;
    }
}

/** 
 * Sets this Skill as a skill that Repeats.
 * 
 * @param random    :   Randomizes between min and max
 * @param min       :   Minimum number to be Randomed to
 * @param max       :   Maximum number to be Randomed to %default repeat time if random is false%
*/
void Skill::repeat(bool random, int min, int max) {
    this->repeats = true;
    this->randomRepeats = random;
    this->minRepeat = min;
    this->maxRepeat = max;
}

/**
 * Sets this Skill as a skill that can inflict Ailments.
 * 
 * @param chance    :   Chance 0-100 to inflict Ailment
 * @param Ailment   :   Ailment to afflict.
*/
void Skill::inflict(int chance, Ailment ailment) {
    this->inflictAilment = true;
    this->inflictAilmentChance = chance;
    this->ailmentToInflict = ailment;
}


/** Initialize Skills. */
const Skill Skill::SKILLS[] = {
    Skill("Slash", Element::Phys, Damage::Weak, 5),
    Skill("Shot", Element::Gun, Damage::Weak, 5),
    Skill("Flame", Element::Fire, Damage::Weak, 5).inflict(10, Ailment::Burn),
    Skill("Freeze", Element::Ice, Damage::Weak, 5).inflict(10, Ailment::Freeze),
    Skill("Myriad Slashes", Element::Phys, Damage::Medium, 10).repeat(true, 1, 2),
    Skill("Lightning", Element::Elec, Damage::Weak, 5).inflict(10, Ailment::Shock)
};

/**
 * Get the Pointer to a Skill.
 * 
 * @param id    :   Index of the Desired Skill.
 * @return Skill Pointer of the Element.
*/
Skill const* Skill::getSkill(int id) {
    return &Skill::SKILLS[id];
}