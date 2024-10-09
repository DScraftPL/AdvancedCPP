#include "Adding.h"
#include "Array.h"
#include "Student.h"
using namespace std;

template <typename T> void showAll(T *tab[], int n) {
  for (int i = 0; i < n; i++)
    tab[i]->show();
}

template <typename T> T findMinimum(T *tab, int n) {
  T minimum = tab[0];
  for (int i = 1; i < n; i++) {
    if (tab[i] < minimum) {
      minimum = tab[i];
    }
  }
  return minimum;
}

int main() {
  Adding<int> a1(5);
  a1.add(6);
  a1.show();
  Adding<string> a2("Pro");
  a2.add("gramowanie");
  a2.show();
  Student<float> s(5, "Ala");
  s.showMark();
  Student<int> s1(5, "Ala");
  s1.showMark();
  Student<string> s2(5, "Ala");
  s2.showMark();
  Adding<int> *arrAdd[3];
  for (int i = 0; i < 3; i++) {
    arrAdd[i] = new Adding<int>(i);
  }
  showAll(arrAdd, 3);
  Student<string> *arrStu[2];
  for (int i = 0; i < 3; i++) {
    arrStu[i] = new Student<string>(i + 2, "Ala");
  }
  showAll(arrStu, 3);
  for (int i = 0; i < 3; i++)
    delete arrAdd[i];
  for (int i = 0; i < 2; i++)
    delete arrStu[i];
  float tablica1[6] = {1.5, 1.4, 3.33, 4.4, 8.6, 7.7};
  cout << findMinimum(tablica1, 6) << " ";
  int tablica2[6] = {2, 3, 4, -1, 2, -99};
  cout << findMinimum(tablica2, 6) << endl;
  Array<std::string> hello(4);
  hello.add("hello");
  hello.add("there");
  hello.add("general");
  hello.add("kenobi");
  hello.show();
  hello.sort();
  hello.show();
  return 0;
}
