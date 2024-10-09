#include "Developer.h"
#include "Employee.h"

int Developer::calculateSalary(int value) {
  return value + 0.2 * value * (getSalary() + getExperience());
}

Developer::Developer() : Employee() {}

Developer::Developer(std::string _surname, int _age, int _experience,
                     float _salary)
    : Employee(_surname, _age, _experience, _salary) {}
