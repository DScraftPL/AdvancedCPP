#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <set>
#include <string>
#include <vector>

using namespace std;

void sprawdz(vector<string> vec, string rege) {
  cout << "Regex: " << rege << endl;
  regex reg(rege);
  for (auto s : vec) {
    cout << s << " ";
    if (regex_search(s, reg)) {
      cout << "zgadza się!";
    } else {
      cout << "nie zgadza się";
    }
    cout << endl;
  }
  cout << "----------------------------------------" << endl;
}

void zad1() {
  vector<string> vec = {"5.15", "-55.51251", "aaa", "+5", "+5.0", "."};
  string liczba("[+-]?\\d+\\.\\d+");
  sprawdz(vec, liczba);
}
void zad2() {
  string data("^([01]\\d|2[0-3]):[0-5]\\d(:[0-5]\\d)?$");
  vector<string> daty = {"12:12:34", "21:37", "23:59:00", "25:00:00",
                         "01,01,01", "aaa",   "01:01:61", "23:70:59"};
  sprawdz(daty, data);
}
void zad3() {
  vector<string> adresy = {
      "szafirowa", "20-200", "bursztynowa", "hutniczna", "meczennikow majdanka",
      "20-999",    "abacki", "a123a",       "28",        "28B",
      "15",        "73"};
  string ulica("^[A-Za-z\\s]+$");
  string kod("^\\d{2}-\\d{3}$");
  string dom("^\\d+[A-Za-z]?$");
  string mieszkanie("^\\d+$");
  sprawdz(adresy, ulica);
  sprawdz(adresy, kod);
  sprawdz(adresy, dom);
  sprawdz(adresy, mieszkanie);
}

void zad4() {
  regex imie("^[A-Za-z]+$");
  regex nazwisko("^[A-Za-z]+(-[A-Za-z]+)?$");
  regex wiek("^([1-9]?\\d|99)$");
  regex telefon("^[1-9]\\d{8}$");
  regex email("^[A-Za-z][A-Za-z0-9._-]*@[A-Za-z0-9]+\\.[A-Za-z0-9]+$");
  string _imie, _nazwisko, _wiek, _telefon, _email;
  cout << "podaj po spacji imie, nazwisko, wiek, telefon, email" << endl;
  cin >> _imie >> _nazwisko >> _wiek >> _telefon >> _email;
  if (regex_match(_imie, imie) && regex_match(_nazwisko, nazwisko) &&
      regex_match(_wiek, wiek) && regex_match(_telefon, telefon) &&
      regex_match(_email, email)) {
    cout << "zwalidowano poprawnie" << endl;
    string do_zapisu = _imie + ";" + _nazwisko + ";" + _wiek + ";" + _telefon +
                       ";" + _email + "\n";
    ofstream plik("dane.txt", ios_base::app);
    if (plik.is_open()) {
      plik << do_zapisu;
    } else {
      cerr << "błąd otwarcia" << endl;
    }
    plik.close();
  } else {
    cout << "wystąpił błąd" << endl;
  }
}

void zad5() {
  ifstream pliczek("dane.txt");
  if (pliczek.is_open()) {
    int parzyste = 0;
    int nazwiska = 0;
    map<string, int> imiona;
    set<string> domeny;
    string linia;
    vector<string> result;
    while (getline(pliczek, linia)) {
      boost::split(result, linia, boost::is_any_of(";"));
      auto pos1 = result[4].find("@");
      string domena = result[4].substr(pos1);
      // cout << domena << endl;
      domeny.insert(domena);
      char ostatni = result[3].back();
      if ((ostatni - '0') % 2 == 0) {
        parzyste++;
      }
      if (count(result[1].begin(), result[1].end(), '-')) {
        nazwiska++;
      }
      imiona[result[0]]++;
    }
    cout << "imiona: " << endl;
    for (auto m : imiona) {
      cout << m.first << " " << m.second << endl;
    }
    cout << "parzyste: " << parzyste << " nazwiska: " << nazwiska << endl;
    cout << "unikalne domeny: " << domeny.size() << endl;
  }
  pliczek.close();
}

int main() {
  int n;
  do {
    cout << "podaj zadanie: ";
    cin >> n;
    cout << endl;
    switch (n) {
    case 1:
      zad1();
      break;
    case 2:
      zad2();
      break;
    case 3:
      zad3();
      break;
    case 4:
      zad4();
      break;
    case 5:
      zad5();
      break;
    }
  } while (n <= 5);
}
