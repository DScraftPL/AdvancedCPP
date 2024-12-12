#include "Contacts.h"
#include <algorithm>
#include <boost/bind.hpp>
#include <boost/fusion/container.hpp>
#include <boost/fusion/container/vector.hpp>
#include <boost/fusion/container/vector/vector.hpp>
#include <boost/fusion/sequence.hpp>
#include <boost/mpl/int.hpp>
#include <iostream>
#include <map>

using namespace std;

template <typename T> void check_range(T wartosc, T dol, T gora) {
  if (dol > gora) {
    swap(dol, gora);
  }
  if (wartosc > dol && wartosc < gora) {
    cout << wartosc << " ";
  }
}

template <typename T> void greater_2(T wartosc, T dol) {
  if (wartosc >= dol) {
    cout << wartosc << " ";
  }
}

template <typename T> void less_2(T wartosc, T gora) {
  if (wartosc < gora) {
    cout << wartosc << " ";
  }
}

template <typename T> void statystyka(vector<T> wektor) {
  T suma = 0;
  for (auto el : wektor) {
    suma += el;
  }
  sort(wektor.begin(), wektor.end());
  T mediana;
  if (wektor.size() % 2 == 0) {
    mediana = (wektor[wektor.size() / 2] + wektor[wektor.size() / 2 - 1]) / 2;
  } else {
    mediana = wektor[wektor.size() / 2];
  }
  T srednia = suma / wektor.size();
  auto bind_less_srednia = boost::bind(less_2<T>, _1, srednia);
  auto bind_dodatnie = boost::bind(greater_2<T>, _1, 0);
  auto bind_miedzy_1 = boost::bind(check_range<T>, _1, srednia, mediana);
  cout << "średnia: " << srednia << endl;
  cout << "mediana: " << mediana << endl;
  for_each(wektor.begin(), wektor.end(), bind_less_srednia);
  cout << endl;
  for_each(wektor.begin(), wektor.end(), bind_miedzy_1);
  cout << endl;
  for_each(wektor.begin(), wektor.end(), bind_dodatnie);
  cout << endl;
}

template <typename FVector> void mix(FVector wektor) {
  std::map<string, int> mapka;
  boost::fusion::for_each(wektor,
                          [&mapka](auto val) { mapka[typeid(val).name()]++; });
  for (auto el : mapka) {
    cout << el.first << " " << el.second << endl;
  }
}

int main() {
  Contacts ksiazka;
  ksiazka.add({"kacper0", "wiacek0", 20, "szafirowa0", "999999999"});
  ksiazka.add({"kacper1", "wiacek1", 19, "szafirowa1", "999999998"});
  ksiazka.add({"kacper2", "wiacek2", 18, "szafirowa1", "999999997"});
  ksiazka.add({"kacper3", "wiacek3", 17, "szafirowa3", "999999996"});
  ksiazka.add({"kacper4", "wiacek3", 16, "szafirowa4", "999999995"});
  ksiazka.add({"kacper5", "wiacek5", 19, "szafirowa5", "999999999"});
  ksiazka.show();
  cout << "////////////////////////////////" << endl;
  ksiazka.find_age(17, 20);
  cout << "////////////////////////////////" << endl;
  ksiazka.change_street("szafirowa0", "szafirowa9");
  ksiazka.show();
  cout << "////////////////////////////////" << endl;
  ksiazka.find_phone("999999999");
  cout << "////////////////////////////////" << endl;
  ksiazka.count_18();
  cout << endl;
  cout << "////////////////////////////////" << endl;
  ksiazka.find_street("szafirowa1");
  cout << "////////////////////////////////" << endl;
  ksiazka.count_unique_surname();
  cout << "////////////////////////////////" << endl;
  vector<float> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  statystyka(vec);
  boost::fusion::vector<int, double, float, bool, char, int, int, float> vek{
      10, 3.14, 3.14, true, 'c', 0, -5, 7.777};
  mix(vek);
  cout << typeid(vek).name();
}
