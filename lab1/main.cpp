#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"

#include <iostream>

using namespace std;

int howManyProtectedAnimals(Animal tablica[], int rozmiar) {
  int counter = 0;
  for (int i = 0; i < rozmiar; i++) {
    if (tablica[i].getProtectedAnimal()) {
      counter++;
    }
  }
  return counter;
}

int howManyTrackerDogs(Dog tablica[], int rozmiar) {
  int counter = 0;
  for (int i = 0; i < rozmiar; i++) {
    if (tablica[i].getSkillLevel(1) > tablica[i].getSkillLevel(0)) {
      counter++;
    }
  }
  return counter;
}

int howManyCats(Cat tablica[], int rozmiar) {
  int counter = 0;
  for (int i = 0; i < rozmiar; i++) {
    for (int j = 0; j < 5; j++) {
      counter += tablica[i].getMice(j);
    }
  }
  return counter;
}

int main() {
  cout << endl << "Obiekty klasy Person" << endl;
  Person o1("Grazyna", "Nowak", 45);
  o1.showInfoPerson();
  cout << "Czy pelnoletnia?: " << o1.is_18() << endl;
  o1.setAge(16);
  cout << endl << "Obiekty klasy Teacher" << endl;
  Teacher n1("Barbara", "Kowalska", 56, 30, "Phd");
  n1.showInfoTeacher();
  cout << "Czy ma Phd?: " << n1.is_Phd() << endl;
  n1.setAge(34);
  Person p1[3];
  Person *p2;
  Person *p3[3];
  Person **p4;
  for (int i = 0; i < 3; i++) {
    p1[i].init("Anna", "Nowak", 20 + i);
    p1[i].showInfoPerson();
  }
  p2 = new Person[3];
  for (int i = 0; i < 3; i++) {
    p2[i].init("Ola", "Adamek", 20 + i);
    p2[i].showInfoPerson();
  }
  for (int i = 0; i < 3; i++) {
    p3[i] = new Person("Kasia", "Kowalska", 20 + i);
    p3[i]->showInfoPerson();
  }
  p4 = new Person *[3];
  for (int i = 0; i < 3; i++) {
    p4[i] = new Person("Pawel", "Wojcik", 20 + i);
    p4[i]->showInfoPerson();
  }
  for (int i = 0; i < 3; i++) {
    delete p3[i];
  }
  for (int i = 0; i < 3; i++) {
    delete p4[i];
  }
  delete[] p4;
  cout << "////////////////////////////////////////////////////////////////////"
       << endl;
  Student tablicaStatycznaStatycznych[10];
  Student *tablicaDynamicznaStatycznych;
  tablicaDynamicznaStatycznych = new Student[10];
  Student *tablicaStatycznaDynamicznych[10];
  Student **tablicaDynamicznaDynamincznych;
  tablicaDynamicznaDynamincznych = new Student *[10];
  for (int i = 0; i < 10; i++) {
    tablicaStatycznaStatycznych[i].init("tak", "nie", 10 + i);
    tablicaStatycznaStatycznych[i].setIndex("99733");
    tablicaDynamicznaStatycznych[i].init("nie", "tak", 20 + i);
    tablicaDynamicznaStatycznych[i].setIndex("99999");
    tablicaStatycznaDynamicznych[i] =
        new Student("00000", "tak", "tak", 30 + i);
    tablicaDynamicznaDynamincznych[i] =
        new Student("88888", "nie", "nie", 40 + i);
  }
  for (int i = 0; i < 10; i++) {
    tablicaStatycznaStatycznych[i].showInfoStudent();
    tablicaDynamicznaStatycznych[i].showInfoStudent();
    tablicaStatycznaDynamicznych[i]->showInfoStudent();
    tablicaDynamicznaDynamincznych[i]->showInfoStudent();
  }
  for (int i = 0; i < 10; i++) {
    delete tablicaStatycznaDynamicznych[i];
    delete tablicaDynamicznaDynamincznych[i];
  }
  delete[] tablicaDynamicznaStatycznych;

  Animal tablicaA[3];

  cout << "/////////////////////////////////" << endl;
  cout << howManyProtectedAnimals(tablicaA, 3) << endl;

  Dog tablicaD[3];

  tablicaD[1].setSkillLevel(1, 9);
  tablicaD[1].setSkillLevel(0, 9);

  cout << howManyTrackerDogs(tablicaD, 3) << endl;
  return 0;
}
