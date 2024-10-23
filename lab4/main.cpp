#include "Citizen.h"
#include "City.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

void showCities(vector<City> c) {
  for (City cities : c) {
    cities.show_city();
    cities.show_citizens();
  }
}

void the_most(vector<City> c, int mode) {
  if (mode == 1) {
    int max = c.at(0).postal_codes();
    int max_i = 0;
    for (int i = 0; i < c.size(); i++) {
      if (c.at(i).postal_codes() > max) {
        max = c.at(i).postal_codes();
        max_i = i;
      }
    }
    c.at(max_i).show_city();
  } else if (mode == 2) {
    int mini = c.at(0).city_citizens();
    int mini_i = 0;
    for (int i = 0; i < c.size(); i++) {
      if (c.at(i).city_citizens() > mini) {
        mini = c.at(i).city_citizens();
        mini_i = i;
      }
    }
    c.at(mini_i).show_city();
  } else {
    cout << "zly mode";
  }
}

void statatistic(vector<City> c) {
  for (City citi : c) {
    citi.show_city();
    cout << citi.woman() << " " << citi.adults() << " "
         << citi.city_citizens() - citi.woman() << " " << citi.adults() << " "
         << citi.city_citizens() - citi.adults() << " " << endl;
  }
}

void sort_cities(vector<City> &c) {
  int n = c.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (c[j].city_citizens() > c[j + 1].city_citizens())
        swap(c[j], c[j + 1]);
    }
  }
}

int main(int argc, char *argv[]) {
  srand(time(0));
  list<int> lista;
  int n, suma = 0, iloscLosowan;
  iloscLosowan = random() % 1000;
  for (int i = 0; i < iloscLosowan; i++) {
    n = random() % 201 - 100;
    suma += n;
    if (n >= 0) {
      lista.push_front(n);
    } else {
      lista.push_back(n);
    }
  }
  for (int element : lista) {
    cout << element << " ";
  }
  cout << endl << "ilosc losowan: " << iloscLosowan;
  cout << endl << "srednia: " << suma / iloscLosowan << endl;
  City temp = City("Lublin");
  Citizen wiacker1 = Citizen("kacper", "wiacek", "00000", 20, 'M');
  Citizen wiacker2 = Citizen("kacper", "wiacek", "00001", 20, 'M');
  Citizen wiacker3 = Citizen("kacper", "wiacek", "00002", 20, 'M');
  Citizen wiacker4 = Citizen("kacper", "wiacek", "00001", 20, 'M');
  Citizen wiacker5 = Citizen("kacper", "wiacek", "00002", 20, 'M');
  temp.addCitizen(wiacker1);
  temp.addCitizen(wiacker2);
  temp.addCitizen(wiacker3);
  temp.addCitizen(wiacker4);
  temp.addCitizen(wiacker5);
  temp.show_city();
  temp.show_citizens();
  temp.postal_codes();
  vector<City> tempVec;
  tempVec.push_back(temp);
  statatistic(tempVec);
  vector<int> inty;
  inty.push_back(0);
  inty.push_back(45);
  inty.push_back(13);
  inty.push_back(83);
  inty.push_back(76);
  inty.push_back(111);
  inty.push_back(2222);
  for (auto c : inty) {
    cout << c << " ";
  }
  cout << endl;
  int it = inty.size();
  for (int i = 0; i < it - 1; i++) {
    for (int j = 0; j < it - i - 1; j++) {
      string ciag1 = to_string(inty[j]);
      string ciag2 = to_string(inty[j + 1]);
      int suma1 = 0;
      for (int k = 0; k < ciag1.size(); k++) {
        suma1 += ciag1[k] - '0';
      }
      int suma2 = 0;
      for (int k = 0; k < ciag2.size(); k++) {
        suma2 += ciag2[k] - '0';
      }
      if (suma1 > suma2) {
        swap(inty[j], inty[j + 1]);
      }
    }
  }
  for (auto c : inty) {
    cout << c << " ";
  }
  cout << endl;
  for (int i = 0; i < it - 1; i++) {
    for (int j = 0; j < it - i - 1; j++) {
      string ciag3 = to_string(inty[j]);
      string ciag4 = to_string(inty[j + 1]);
      if (ciag3.size() > ciag4.size()) {
        swap(inty[j], inty[j + 1]);
      }
    }
  }
  for_each(inty.begin(), inty.end(), [](int a) { cout << a << " "; });
  cout << endl;
  return 0;
}
