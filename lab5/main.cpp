#include "Dictionary.h"
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int duplikat(vector<int> vec) {
  set<int> temp;
  for (auto elem : vec) {
    auto it = temp.find(elem);
    if (it != temp.end()) {
      return elem;
    }
    temp.insert(elem);
  }
  return -1;
}

template <typename T> void wykluczajaca(set<T> s1, set<T> s2) {
  set<T> wynikowy;
  for (T temp : s1) {
    wynikowy.insert(temp);
  }
  for (T temp : s2) {
    wynikowy.insert(temp);
  }
  for (T temp : wynikowy) {
    cout << temp << " ";
  }
  cout << endl;
}

char roznica(string s1, string s2) {
  map<char, int> temp1;
  map<char, int> temp2;
  for (char c : s1) {
    auto it = temp1.find(c);
    if (it != temp1.end()) {
      temp1[c]++;
    } else {
      temp1.insert({c, 1});
    }
  }
  for (char c : s2) {
    auto it = temp2.find(c);
    if (it != temp2.end()) {
      temp2[c]++;
    } else {
      temp2.insert({c, 1});
    }
  }
  for (auto c : temp2) {
    auto temp = c.first;
    if (temp1[temp] != temp2[temp]) {
      return temp;
    }
  }
  return '#';
}

int main() {
  vector<int> v;
  for (int i = 0; i < 10; i++) {
    v.push_back(i);
  }
  v.push_back(7);
  cout << duplikat(v) << endl;
  set<int> s1, s2;
  for (int i = 0; i < 10; i++) {
    s1.insert(i);
    s2.insert(i + 6);
  }
  for (auto x : s1) {
    cout << x << " ";
  }
  cout << endl;
  for (auto x : s2) {
    cout << x << " ";
  }
  cout << endl;
  wykluczajaca(s1, s2);
  string str1 = "hello";
  string str2 = "hepllo";
  cout << roznica(str1, str2) << endl;
  Dictionary slownik;
  slownik.add("hello", "powitanie");
  slownik.add("goodbye", "zegnam");
  slownik.add("async", "asynchroniczny");
  slownik.show();
  slownik.show_z_a();
  return 0;
}

// ostatnie z labow
//
