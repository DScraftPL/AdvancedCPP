#pragma once
#include <iostream>

class Citizen {
private:
  std::string name, surname, postal_code;
  int age;
  char sex;

public:
  Citizen() : name(""), surname(""), postal_code(""), age(0), sex('N') {};
  Citizen(std::string _name, std::string _surname, std::string _postal_code,
          int _age, char _sex)
      : name(_name), surname(_surname), postal_code(_postal_code), age(_age),
        sex(_sex) {}
  void show() {
    std::cout << name << " " << surname << " " << postal_code << " " << age
              << " " << sex << std::endl;
  }
  std::string getName() { return name; }
  std::string getSurname() { return surname; }
  std::string getPostalcode() { return postal_code; }
  int getAge() { return age; }
  char getSex() { return sex; }
};
