#include "City.h"
#include "Citizen.h"
#include <map>
#include <vector>

void City::deleteCitizen(std::string surname) {
  std::vector<Citizen> new_citizens;
  for (Citizen citizen : citizens) {
    if (citizen.getSurname() != surname) {
      new_citizens.push_back(citizen);
    }
  }
  citizens = new_citizens;
}
void City::show_citizens() {
  for (Citizen citizen : citizens) {
    citizen.show();
  }
}
void City::show_city() {
  std::cout << city_name << std::endl;
  show_citizens();
}
int City::woman() {
  int sum = 0;
  for (Citizen citizen : citizens) {
    if (citizen.getSex() == 'F') {
      sum++;
    }
  }
  return sum;
}
int City::city_citizens() { return citizens.size(); }
int City::adults() {
  int sum = 0;
  for (Citizen citizen : citizens) {
    if (citizen.getAge() >= 18) {
      sum++;
    }
  }
  return sum;
}
int City::postal_codes() {
  std::map<std::string, int> postals;
  for (Citizen citizen : citizens) {
    std::string temp = citizen.getPostalcode();
    auto it = postals.find(temp);
    if (it != postals.end()) {
      postals[temp]++;
    } else {
      postals.insert({temp, 1});
    }
  }
  for (auto cos : postals) {
    std::cout << cos.first << " " << cos.second << " ";
  }
  std::cout << std::endl << postals.size() << std::endl;
  return postals.size();
}
