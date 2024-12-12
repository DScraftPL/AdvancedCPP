#ifndef STUDENT
#define STUDENT
#include "Person.h"

class Student : public Person {
private:
  string index;

public:
  Student(string _index, string _name, string _surname, int _age);
  Student();
  void setIndex(string _index);
  string getIndex();
  void showInfoStudent();
};

#endif
