#ifndef ANIMAL
#define ANIMAL
#include <iostream>
using namespace std;

class Animal {
private:
  int limbNr;
  string name;
  bool protectedAnimal;

public:
  Animal();
  Animal(int _limbNr, string _name, bool _protectedAnimal = true);
  void setLimbNr(int _limbNr);
  void setName(string _name);
  void setProtectedAnimal(bool _protectedAnimal);
  int getLimbNr();
  string getName();
  bool getProtectedAnimal();
  void giveVoice();
  void info();
};

#endif // !ANIMAL
