#include "Developer.h"
#include "Employee.h"

float Developer::calculateBonus(int value) {
  int salary = calculateSalary(value);
  return value + 0.2 * value * (salary + getExperience());
}

int Developer::calculateSalary(int value) { return value; }

Developer::Developer() : Employee() {}

Developer::Developer(std::string _surname, int _age, int _experience,
                     float _salary)
    : Employee(_surname, _age, _experience, _salary) {}
