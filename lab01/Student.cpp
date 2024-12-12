#include "Student.h"
#include "Person.h"
#include <iostream>

Student::Student(string _index, string _name, string _surname, int _age)
    : Person(_name, _surname, _age) {
  index = _index;
}

Student::Student() {}

void Student::setIndex(string _index) { index = _index; }

string Student::getIndex() { return index; }

void Student::showInfoStudent() {
  showInfoPerson();
  cout << index;
}
