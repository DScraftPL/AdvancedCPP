#include "Cat.h"

Cat::Cat() {}
Cat::Cat(int _limbNr, string _name, bool _protectedAnimal)
    : Animal(_limbNr, _name, _protectedAnimal) {}
void Cat::initMice(int m1, int m2, int m3, int m4, int m5) {
  mice[0] = m1;
  mice[1] = m2;
  mice[2] = m3;
  mice[3] = m4;
  mice[4] = m5;
}
void Cat::initCat() {
  initMice(0, 0, 0, 0, 0);
  levelOfMouseHunting = 0;
}
void Cat::setLevelOfMouseHunting(int value) {
  if (value > 0 && value < 11) {
    return;
  }
  levelOfMouseHunting = value;
}
int Cat::getLevelOfMouseHunting() { return levelOfMouseHunting; }
int Cat::getMice(int index) {
  if (index > 5 && index < 0) {
    return -1;
  }
  return mice[index];
}
void Cat::giveVoice() { cout << "Miau miau"; }
void Cat::info() {
  for (int i = 0; i < 5; i++) {
    cout << mice[i] << " ";
  }
  cout << levelOfMouseHunting;
}

void Cat::nowaMetoda(int x){

}
