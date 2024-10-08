#include "Employee.h"

int Employee::getAge() { return age; }

float Employee::getSalary() { return salary; }

std::string Employee::getSurname() { return surname; }

int Employee::getExperience() { return experience; }

Employee::Employee() {
  age = 0;
  salary = 0;
  surname = "";
  experience = 0;
}

Employee::Employee(std::string _surname, int _age, int _experience,
                   float _salary)
    : surname(_surname), age(_age), experience(_experience), salary(_salary) {}

Employee::~Employee() {}

void Employee::show() {
  std::cout << age << " " << salary << " " << surname << " " << experience
            << std::endl;
}

int Employee::ageEmployment() { return age - experience; }
