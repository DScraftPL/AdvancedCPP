#include "BufferFile.h"
#include <fstream>
#include <iostream>

using namespace std;

BufferFile::BufferFile(std::string _sciezka) {
  sciezka = _sciezka;
  cout << "Konstruktor BufferFile" << endl;
}
BufferFile::~BufferFile() { cout << "Destruktor BufferFile" << endl; }

void BufferFile::add(int a) {
  ofstream file;
  file.open(sciezka, ios_base::app);
  file << a << endl;
  file.close();
}

void BufferFile::write() {
  ifstream file;
  file.open(sciezka);
  string linia;
  while (getline(file, linia)) {
    cout << linia << " ";
  }
  cout << endl;
  file.close();
}
