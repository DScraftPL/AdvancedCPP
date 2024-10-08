#include "TeamLeader.h"

float TeamLeader::calculateBonus(int value) {
  int salary = calculateSalary(value);
  return value * (1 + salary + getExperience());
}
int TeamLeader::calculateSalary(int value) { return value; }
void TeamLeader::show() {
  std::cout << "Jestem Team Leader z " << getExperience()
            << " letnim doświadczeniem" << std::endl;
}

TeamLeader::TeamLeader() : Employee() {}

TeamLeader::TeamLeader(std::string _surname, int _age, int _experience,
                       float _salary)
    : Employee(_surname, _age, _experience, _salary) {}
