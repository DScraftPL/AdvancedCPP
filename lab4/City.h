#pragma once
#include "Citizen.h"
#include <iostream>
#include <vector>

class City {
private:
  std::vector<Citizen> citizens;
  std::string city_name;

public:
  City(std::string _city_name) : city_name(_city_name) {}
  void addCitizen(Citizen c) { citizens.push_back(c); }
  void deleteCitizen(std::string surname);
  void show_citizens();
  void show_city();
  int woman();
  int city_citizens();
  int adults();
  int postal_codes();
};
