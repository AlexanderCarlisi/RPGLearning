#include <iostream>
#include <string>

#include "src/Unit.cpp"
#include "src/Persona.cpp"

int main() {

  Skill const* skills[] = {Skill::getSkill(0), Skill::getSkill(1)};
  Unit unit = Unit("Name", 10, 5, Persona("PersonaName", 10, 1, 2, 3, 4, 5, skills));

  std::cout << "\n\n\n" << unit.persona.name << std::endl;

  int* stats = unit.persona.getStatsAsArray();
  for (int i = 0; i < 5; i++) {
    std::cout << stats[i] << std::endl;
  }
  delete[] stats;

  std::cout << "\n\n\n" << unit.persona.skills[0]->name;

  return 0;
}