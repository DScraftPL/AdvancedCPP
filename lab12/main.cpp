#include "Car.h"
#include <algorithm>
#include <ctime>
#include <iostream>
#include <list>
#include <random>
#include <tuple>
#include <vector>

using namespace std;

void zad1() {
  vector<int> wektor;
  for (int i = 0; i < 10; i++) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(-10, 10);

    int randomNum = distrib(gen);
    wektor.push_back(randomNum);
  }
  float suma = 0, ilosc = 0;

  cout << "przed sortowaniem: " << endl;
  for_each(wektor.begin(), wektor.end(), [](int a) { cout << a << "|"; });
  cout << endl;
  sort(wektor.begin(), wektor.end(), [](int a, int b) { return a < b; });

  cout << "po sortowaniu:" << endl;
  for_each(wektor.begin(), wektor.end(), [](int a) { cout << a << "|"; });
  cout << endl;

  for_each(wektor.begin(), wektor.end(), [&suma, &ilosc](int a) {
    suma += a;
    ilosc++;
  });
  cout << "średnia: " << suma / ilosc << endl;
  cout << "liczba parzystych: "
       << count_if(wektor.begin(), wektor.end(),
                   [](int a) { return a % 2 == 0; });
  cout << endl;

  vector<int> wektor_lepszy;
  for_each(wektor.begin(), wektor.end(), [&wektor_lepszy](int a) {
    if (a > 0) {
      wektor_lepszy.push_back(a);
    }
  });
  cout << "wieksze od 0:" << endl;
  for_each(wektor_lepszy.begin(), wektor_lepszy.end(),
           [](int a) { cout << a << "|"; });
  cout << endl;

  vector<int> parzyste;
  for_each(wektor.begin(), wektor.end(), [&parzyste](int a) {
    if (a % 2 == 0) {
      parzyste.push_back(a);
    }
  });
  cout << "parzyste:" << endl;
  for_each(parzyste.begin(), parzyste.end(), [](int a) { cout << a << "|"; });
  cout << endl;

  transform(wektor.begin(), wektor.end(), wektor.begin(),
            [](int a) { return -a; });
  cout << "zanegowane: " << endl;
  for_each(wektor.begin(), wektor.end(), [](int a) { cout << a << "|"; });
  cout << endl;

  list<int> temp;
  for_each(wektor.begin(), wektor.end(), [&temp](int a) {
    if (a % 2 == 0) {
      temp.push_front(a);
    } else {
      temp.push_back(a);
    }
  });
  cout << "'wektor': " << endl;
  for_each(temp.begin(), temp.end(), [](int a) { cout << a << "|"; });
  cout << endl;
}

void zad2() {
  vector<tuple<int, Car *>> lista;
  lista.push_back(make_tuple(0, new Car("polonez", 1998, 2000)));
  lista.push_back(make_tuple(1, new Car("fabia", 2002, 3000)));
  lista.push_back(make_tuple(2, new Car("mały fiat", 1999, 1000)));
  sort(lista.begin(), lista.end(),
       [](tuple<int, Car *> a, tuple<int, Car *> b) {
         return get<1>(a)->getRok() < get<1>(b)->getRok();
       });
  cout << "Sortowanie po roku:" << endl;
  for_each(lista.begin(), lista.end(), [](tuple<int, Car *> a) {
    cout << get<0>(a) << ": ";
    get<1>(a)->show();
  });
  cout << endl;
  sort(lista.begin(), lista.end(), [](auto a, tuple<int, Car *> b) {
    return get<1>(a)->getPoj() < get<1>(b)->getPoj();
  });
  cout << "Sortowanie po pojemnosci:" << endl;
  for_each(lista.begin(), lista.end(), [](tuple<int, Car *> a) {
    cout << get<0>(a) << ": ";
    get<1>(a)->show();
  });
  cout << endl;
}

void zad3(vector<string> vec) {
  double sum;
  int size;
  size = vec.size();
  vector<size_t> dlugosci(size);
  transform(vec.begin(), vec.end(), dlugosci.begin(),
            [](string a) { return a.length(); });
  for_each(dlugosci.begin(), dlugosci.end(), [&sum](int a) { sum += a; });
  cout << "minimum: " << *min_element(dlugosci.begin(), dlugosci.end()) << endl;
  cout << "srednia: " << (double)((double)sum / (double)size) << endl;
  cout << "maximum: " << *max_element(dlugosci.begin(), dlugosci.end()) << endl;
}

void test3() {
  vector<string> vek;
  vek.push_back("Witam");
  vek.push_back("halo");
  vek.push_back("papapa");
  vek.push_back("bonjour");
  vek.push_back("tak tak to ja");
  zad3(vek);
}

int main() {
  int n;
  cout << "1 - zad1, 2 - zad2, 3 - zad3" << endl;
  cin >> n;
  switch (n) {
  case 1:
    zad1();
    break;
  case 2:
    zad2();
    break;
  case 3:
    test3();
    break;
  }
  return 0;
}
