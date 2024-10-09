#pragma once
#include <algorithm>
#include <iostream>

template <typename T> class Array {
private:
  T *tablica;
  int rozmiar;
  int wolny;

public:
  Array(int _rozmiar = 10) {
    rozmiar = _rozmiar;
    tablica = new T[rozmiar];
    wolny = 0;
  }
  ~Array() { delete tablica; }
  void sort() { std::sort(tablica, tablica + rozmiar); }
  void show() {
    for (int i = 0; i < wolny; i++) {
      std::cout << tablica[i] << " ";
    }
    std::cout << std::endl;
  }
  void add(T value) {
    tablica[wolny] = value;
    wolny++;
    // memoryleakwednesday
  }
  T pos(int index) { return tablica[index]; }
};
