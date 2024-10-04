#include "Dog.h"

Dog::Dog(string _breed, int _levelOfGuideSkills, int _levelOfTrackerSkills,
         int _limbNr, string _name, bool _protectedAnimal)
    : Animal(_limbNr, _name, _protectedAnimal) {
  breed = _breed;
  levelOfGuideSkills = _levelOfGuideSkills;
  levelOfTrackerSkills = _levelOfTrackerSkills;
}
Dog::Dog(int _limbNr, string _name, bool _protectedAnimal)
    : Animal(_limbNr, _name, _protectedAnimal) {}
Dog::Dog() {}
void Dog::setSkillLevel(int type, int value) {
  if (value > 0 && value < 11) {
    return;
  }
  if (type == 0) {
    levelOfGuideSkills = value;
  } else if (type == 1) {
    levelOfTrackerSkills = value;
  }
}
int Dog::getSkillLevel(int type) {
  if (type == 0) {
    return levelOfGuideSkills;
  } else if (type == 1) {
    return levelOfTrackerSkills;
  } else {
    return -1;
  }
}
void Dog::giveVoice() { cout << "Hau, hau" << endl; }
void Dog::info() {
  cout << breed << " " << levelOfGuideSkills << " " << levelOfTrackerSkills
       << endl;
}

void Dog::hello() { cout << "hi, how are you!"; }
