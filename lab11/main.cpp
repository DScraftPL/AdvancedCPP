#include "Buffer.h"
#include "BufferArr.h"
#include "BufferFile.h"
#include "List.h"
#include "Shop.h"
#include "Warehouse.h"
#include <iostream>
#include <memory>

using namespace std;

void zad1() {
  Buffer **tab = new Buffer *[6];
  tab[0] = new BufferArr(9);
  tab[1] = new BufferFile("dane1.txt");
  tab[2] = new BufferArr(10);
  tab[3] = new BufferFile("dane2.txt");
  tab[4] = new BufferArr(8);
  tab[5] = new BufferFile("dane1.txt");
  for (int i = 0; i < 10; i++) {
    tab[0]->add(i * i);
    tab[1]->add(i + 2);
    tab[2]->add(i + 3);
    tab[3]->add(100 * i);
    tab[4]->add(0 - i);
    tab[5]->add(2 * i + 5);
  }
  for (int i = 0; i < 6; i++) {
    cout << "Buffer nr1: ";
    tab[i]->write();
    delete tab[i];
  }
  delete[] tab;
}

void zad2() {
  vector<unique_ptr<Shop>> sklepy;

  auto w1 = make_shared<Warehouse>(ksiazki, 5);
  auto w2 = make_shared<Warehouse>(komputery, 7);
  auto w3 = make_shared<Warehouse>(lozka, 9);
  cout << endl;
  auto s1 = make_unique<Shop>("Ksiegarnia");
  s1->add(w1);
  s1->add(w2);
  auto s2 = make_unique<Shop>("Agata meble");
  s2->add(w1);
  s2->add(w2);
  auto s3 = make_unique<Shop>("xkom");
  s3->add(w3);
  sklepy.push_back(move(s1));
  sklepy.push_back(move(s2));
  sklepy.push_back(move(s3));

  for (auto &s : sklepy) {
    s->showName();
    s->showWar();
    s->sell(komputery, 2);
    cout << endl;
  }
}

void zad3() {
  List lista;
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      lista.push_front(i);
    } else {
      lista.push_back(i);
    }
  }
  lista.display();
  for (int i = 0; i < 2; i++) {
    lista.pop_front();
  }
  lista.display();
  for (int i = 0; i < 2; i++) {
    lista.pop_back();
  }
  lista.display();
}

int main() {
  zad1();
  zad2();
  zad3();
  return 0;
}
