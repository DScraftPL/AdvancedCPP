#include <iostream>
#include "Product.h"
#include <random>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

void kacper(){
    list<int> wiacek;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(-150, 150);
    uniform_int_distribution<int> ilosc(9,17);
    int n = ilosc(gen);
    cout << "wylosowana liczba: " << n << endl;
    int suma = 0;
    for(int i=0; i<n; i++){
        int k = dist(gen);
        if(k >= 0){
            wiacek.push_back(k);
        } else {
            wiacek.push_front(k);
        }
        suma += k;
    }
    cout << "Lista: " << endl;
    for (auto it=wiacek.begin(); it!=wiacek.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    cout << "Srednia: " << suma/n << endl;
    cout << "Mediana: " << endl;
    list<int> druga;
    for (auto it=wiacek.begin(); it!=wiacek.end(); it++){
        int kk = *it;
        if(kk % 2 == 0){
            druga.push_back(kk);
        } else {
            druga.push_front(kk);
        }
    }
    for (auto it=druga.begin(); it!=druga.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    druga.sort();
    for (auto it=druga.begin(); it!=druga.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    Product KacperWiacekProdukt("produkt", 3.14, 5, "99733");
    Product bezparametrowy;
    KacperWiacekProdukt.info();
    bezparametrowy.info();
    bezparametrowy.setName("nowa nazwa");
    bezparametrowy.setPrice(9.9999);
    bezparametrowy.setQuantity(99);
    bezparametrowy.info();
    cout << "Hello world" << endl;
    kacper();
    return 0;
}
