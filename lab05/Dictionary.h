#pragma once
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Dictionary {
private:
  std::map<std::string, std::string> words;

public:
  Dictionary() {}
  void add(std::string slowo, std::string definicja) {
    auto it = words.find(slowo);
    if (it != words.end()) {
      std::cout << "jest juz w slowniku" << std::endl;
    } else {
    }
    words.insert({slowo, definicja});
  }
  void del(std::string slowo) { words.erase(slowo); }
  void show() {
    for (auto slowo : words) {
      std::cout << slowo.first << " " << slowo.second << std::endl;
    }
  }
  void show(std::string slowo) {
    std::cout << slowo << " " << words[slowo] << std::endl;
  }
  void show_z_a() {
    std::vector<std::pair<std::string, std::string>> temp;
    for (auto slowo : words) {
      temp.push_back(std::pair(slowo.first, slowo.second));
    }
    std::sort(temp.begin(), temp.end(),
              [](std::pair<std::string, std::string> a,
                 std::pair<std::string, std::string> b) {
                return a.second[0] > b.second[0];
              });
    for (auto t : temp) {
      std::cout << t.first << " " << t.second << std::endl;
    }
  }
};
