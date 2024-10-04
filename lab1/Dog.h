#ifndef DOG
#define DOG
#include "Animal.h"

class Dog : public Animal {
private:
  string breed;
  int levelOfGuideSkills;
  int levelOfTrackerSkills;

public:
  Dog(string _breed, int _levelOfGuideSkills, int _levelOfTrackerSkills,
      int _limbNr, string _name, bool _protectedAnimal);
  Dog(int _limbNr, string _name, bool _protectedAnimal);
  Dog();
  void setSkillLevel(int type, int value);
  int getSkillLevel(int type);
  void giveVoice();
  void info();
  void hello();
};

#endif // !DOG
