#include "Animal.h"

Animal::Animal() {}
Animal::Animal(int _limbNr, string _name, bool _protectedAnimal) {
  limbNr = _limbNr;
  name = _name;
  protectedAnimal = _protectedAnimal;
}
void Animal::setLimbNr(int _limbNr) { limbNr = _limbNr; }
void Animal::setName(string _name) { name = _name; }
void Animal::setProtectedAnimal(bool _protectedAnimal) {
  protectedAnimal = _protectedAnimal;
}
int Animal::getLimbNr() { return limbNr; }
string Animal::getName() { return name; }
bool Animal::getProtectedAnimal() { return protectedAnimal; }
void Animal::giveVoice() { cout << "Chrum, miau, hau, piiiii"; }
void Animal::info() {
  cout << limbNr << " " << name << " " << protectedAnimal << endl;
}
