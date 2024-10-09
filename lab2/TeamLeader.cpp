#include "TeamLeader.h"

int TeamLeader::calculateSalary(int value) {
  return value * (1 + getSalary() + getExperience());
}
void TeamLeader::show() {
  std::cout << "Jestem Team Leader z " << getExperience()
            << " letnim doświadczeniem" << std::endl;
}

TeamLeader::TeamLeader() : Employee() {}

TeamLeader::TeamLeader(std::string _surname, int _age, int _experience,
                       float _salary)
    : Employee(_surname, _age, _experience, _salary) {}
