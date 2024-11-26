#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <exception>
#include <fstream>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <vector>

using namespace std;

void zad1() {
  ifstream file;
  try {
    file.open("plik.txt");
    if (!file.is_open()) {
      throw runtime_error("nie ma takiego pliku!");
    }
    string line1;
    while (getline(file, line1)) {
      if (line1.find("//") < line1.length()) {
        if (line1.find("//") == 0) {
          continue;
        }
        string nline = line1.substr(0, line1.find("//"));
        cout << nline << endl;
      } else {
        cout << line1 << endl;
      }
    }
    file.close();
  } catch (exception &e) {
    cout << e.what() << endl;
  } catch (...) {
    cout << "nie wiem" << endl;
  }
}

void zad2() {
  int suma = 0;
  int liczba;
  int proby = 0;
  do {
    try {
      while (true) {
        proby++;
        if ((cin >> liczba) && liczba > 0) {
          break;
        } else {
          cin.clear();
          cin.ignore();
          cerr << "zly typ" << endl;
        }
      }
      suma += liczba;
    } catch (...) {
      cout << "Blad!" << endl;
    }
  } while (suma < 21);
  cout << suma << endl;
  cout << proby << endl;
}

struct dane {
  string imie;
  string nazwisko;
  char plec;
  float ocena;
  string email;
};

void zad3_1(vector<dane> odczyt) {
  for (auto o : odczyt) {
    cout << o.imie << " " << o.nazwisko << " " << o.plec << " " << o.ocena
         << " " << o.email << endl;
  }
}
void zad3_2(vector<dane> &odczyt) {
  string imie;
  string nazwisko;
  char plec;
  float ocena;
  string email;
  cout << "Podaj imie: ";
  cin >> imie;
  cout << "Podaj nazwisko: ";
  cin >> nazwisko;
  cout << "Podaj plec: ";
  cin >> plec;
  cout << "Podaj ocene: ";
  cin >> ocena;
  cout << "Podaj email: ";
  cin >> email;
  dane d;
  d.imie = imie;
  d.nazwisko = nazwisko;
  d.plec = plec;
  d.ocena = ocena;
  d.email = email;
  odczyt.push_back(d);
}
void zad3_3(vector<dane> odczyt, string nazwisko) {
  for (auto o : odczyt) {
    if (o.nazwisko == nazwisko) {
      cout << o.imie << " " << o.nazwisko << " " << o.plec << " " << o.ocena
           << " " << o.email << endl;
    }
  }
}
void zad3_4(vector<dane> odczyt) {
  ofstream plikM, plikK;
  plikM.open("m.csv");
  plikK.open("k.csv");
  if (plikK.is_open() && plikM.is_open()) {
    for (auto o : odczyt) {
      if (o.plec == 'm') {
        plikM << o.imie << ";" << o.nazwisko << ";" << o.plec << ";" << o.ocena
              << ";" << o.email << endl;
      } else if (o.plec == 'k') {
        plikK << o.imie << ";" << o.nazwisko << ";" << o.plec << ";" << o.ocena
              << ";" << o.email << endl;
      }
    }
  }
  plikM.close();
  plikK.close();
}
void zad3_5(vector<dane> odczyt, int X) {
  for (int i = 0; i < X; i++) {
    dane o = odczyt[i];
    cout << o.imie << " " << o.nazwisko << " " << o.plec << " " << o.ocena
         << " " << o.email << endl;
  }
}
void zad3_6(vector<dane> &odczyt) {
  int n = odczyt.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (odczyt[j].ocena > odczyt[j + 1].ocena)
        swap(odczyt[j], odczyt[j + 1]);
    }
  }
}

void zad3() {
  int opcja = 0;
  int x;
  ifstream file;
  string sciezka;
  string linia;
  string nazw;
  vector<dane> odczyt;
  try {
    cout << "Podaj sciezke: ";
    cin >> sciezka;
    file.open(sciezka);
    if (!file.is_open()) {
      throw runtime_error("nie ma takiego pliku");
    }
    getline(file, linia);
    while (getline(file, linia)) {
      dane odczytD;
      vector<string> result;
      boost::split(result, linia, boost::is_any_of(";"));
      odczytD.imie = result[0];
      odczytD.nazwisko = result[1];
      odczytD.plec = result[2][0];
      odczytD.ocena = stof(result[3]);
      odczytD.email = result[4];
      odczyt.push_back(odczytD);
    }
    file.close();
  } catch (...) {
    cerr << "Blad" << endl;
  }
  while (opcja != 7) {
    cout << "Opcje: " << endl
         << "1 - wyswietl" << endl
         << "2 - zapisz osobe" << endl
         << "3 - wyswietl nazwisko" << endl
         << "4 - k & m" << endl
         << "5 - X studentow" << endl
         << "6 - sortuj rosnaco ocena" << endl
         << "7 - wyjdz" << endl;
    cin >> opcja;
    switch (opcja) {
    case 1:
      zad3_1(odczyt);
      break;
    case 2:
      zad3_2(odczyt);
      break;
    case 3:
      cin >> nazw;
      zad3_3(odczyt, nazw);
      break;
    case 4:
      zad3_4(odczyt);
      break;
    case 5:
      cin >> x;
      zad3_5(odczyt, x);
      break;
    case 6:
      zad3_6(odczyt);
      break;
    }
  }

  ofstream plikOUT;
  plikOUT.open(sciezka);
  if (plikOUT.is_open()) {
    for (auto o : odczyt) {
      plikOUT << o.imie << ";" << o.nazwisko << ";" << o.plec << ";" << o.ocena
              << ";" << o.email << endl;
    }
  }
  plikOUT.close();
}

int main() {
  // zad1();
  // zad2();
  zad3();
}
