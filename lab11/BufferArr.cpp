#include "BufferArr.h"
#include <iostream>

using namespace std;

BufferArr::BufferArr(int _rozmiar) {
  rozmiar = _rozmiar;
  tab = new int[rozmiar];
  last = 0;
  cout << "Konstruktor klasy BufferArr" << endl;
}

BufferArr::~BufferArr() {
  delete[] tab;
  cout << "Destuktor klasy BufferArr" << endl;
}

int BufferArr::getRozmiar() { return rozmiar; }

void BufferArr::setRozmiar(int _rozmiar) { rozmiar = _rozmiar; }

void BufferArr::add(int a) {
  if (last >= rozmiar) {
    cout << "Brak miejsca" << endl;
    return;
  }
  tab[last] = a;
  last++;
}

void BufferArr::write() {
  for (int i = 0; i < last; i++) {
    cout << tab[i] << " ";
  }
  cout << endl;
}
