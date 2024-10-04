#ifndef CAT
#define CAT
#include "Animal.h"

class Cat : public Animal {
private:
  int levelOfMouseHunting;
  int mice[5];

public:
  Cat();
  Cat(int _limbNr, string _name, bool _protectedAnimal);
  void initMice(int m1, int m2, int m3, int m4, int m5);
  void initCat();
  void setLevelOfMouseHunting(int value);
  int getLevelOfMouseHunting();
  int getMice(int index);
  void giveVoice();
  void info();
  void nowaMetoda(int x);
};

#endif
