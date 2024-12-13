#include "Car.h"
#include <algorithm>
#include <ctime>
#include <iostream>
#include <list>
#include <random>
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
  vector<Car *> lista;
  int k = 1;
  lista.push_back(new Car("polonez", 1998, 2000));
  lista.push_back(new Car("fabia", 2002, 3000));
  lista.push_back(new Car("mały fiat", 1999, 1000));
  sort(lista.begin(), lista.end(),
       [](Car *a, Car *b) { return a->getRok() < b->getRok(); });
  cout << "Sortowanie po roku:" << endl;
  for_each(lista.begin(), lista.end(), [&k](Car *a) {
    cout << k << " ";
    k++;
    a->show();
  });
  cout << endl;
  k = 1;
  sort(lista.begin(), lista.end(),
       [](Car *a, Car *b) { return a->getPoj() < b->getPoj(); });
  cout << "Sortowanie po pojemnosci:" << endl;
  for_each(lista.begin(), lista.end(), [&k](Car *a) {
    cout << k << " ";
    k++;
    a->show();
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

int main() {
  vector<string> vek;
  vek.push_back("Witam");
  vek.push_back("halo");
  vek.push_back("papapa");
  vek.push_back("bonjour");
  vek.push_back("tak tak to ja");
  zad3(vek);
  return 0;
}
