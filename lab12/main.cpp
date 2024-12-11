#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> wektor;
  for (int i = 0; i < 10; i++) {
    wektor.push_back(i + i * i + 5);
    wektor.push_back(2 * i + 4);
    wektor.push_back(-i);
  }
  float suma = 0, ilosc = 0;
  cout << "przed sortowaniem: " << endl;
  for_each(wektor.begin(), wektor.end(), [](int a) { cout << a << "|"; });
  cout << endl;
  cout << "po sortowaniu:" << endl;
  sort(wektor.begin(), wektor.end(), [](int a, int b) { return a < b; });
  for_each(wektor.begin(), wektor.end(), [](int a) { cout << a << "|"; });
  cout << endl;
  for_each(wektor.begin(), wektor.end(), [&suma, &ilosc](int a) {
    suma += a;
    ilosc++;
  });
  cout << suma << endl;
  cout << suma / ilosc << endl;
  cout << count_if(wektor.begin(), wektor.end(),
                   [](int a) { return a % 2 == 0; });
  cout << endl;
  vector<int> wektor_lepszy;
  for_each(wektor.begin(), wektor.end(), [&wektor_lepszy](int a) {
    if (a > 0) {
      wektor_lepszy.push_back(a);
    }
  });
  for_each(wektor_lepszy.begin(), wektor_lepszy.end(),
           [](int a) { cout << a << "|"; });
  vector<int> parzyste;
  for_each(wektor.begin(), wektor.end(), [&parzyste](int a) {
    if (a % 2 == 0) {
      parzyste.push_back(a);
    }
  });
  cout << endl;
  for_each(parzyste.begin(), parzyste.end(), [](int a) { cout << a << "|"; });
  cout << endl;
  transform(wektor.begin(), wektor.end(), wektor.begin(),
            [](int a) { return -a; });
  for_each(wektor.begin(), wektor.end(), [](int a) { cout << a << "|"; });
  cout << endl;
  return 0;
}
