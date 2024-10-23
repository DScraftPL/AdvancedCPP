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
  ~Array() { delete[] tablica; }
  void sort() { std::sort(tablica, tablica + rozmiar); }

  void show() {
    for (int i = 0; i < wolny; i++) {
      std::cout << tablica[i] << " ";
    }
    std::cout << std::endl;
  }
  T max() {
    T minimum = tablica[0];
    for (int i = 1; i < rozmiar; i++) {
      if (tablica[i] > minimum) {
        minimum = tablica[i];
      }
    }
    return minimum;
  }
  void add(T value) {
    tablica[wolny] = value;
    wolny++;
    // memoryleakwednesday
  }
  T pos(int index) { return tablica[index]; }
};

template <> void Array<std::string>::sort() {
  int *tablicaPom = new int[rozmiar];
  for (int i = 0; i < wolny; i++) {
    tablicaPom[i] = tablica[i].length();
  }
  for (int i = 0; i < rozmiar - 1; i++) {
    for (int j = 0; j < rozmiar - i - 1; j++) {
      if (tablicaPom[j] > tablicaPom[j + 1]) {
        std::swap(tablicaPom[j], tablicaPom[j + 1]);
        std::swap(tablica[j], tablica[j + 1]);
      }
    }
  }
  delete[] tablicaPom;
}
