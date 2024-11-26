#include "Product.h"
#include <iostream>

using namespace std;

Product::Product(){
    name = "undefined";
    price = 0.0;
    quantity = 0;
    studentID = "99733";
}

Product::Product(std::string _name, float _price, int _quantity, std::string _studentID){
    name = _name;
    price = _price;
    quantity = _quantity;
    studentID = _studentID;
}

        void Product::setName(std::string s){
        name = s;
        }
        void Product::setPrice(float p){
            price = p;
        }
        void Product::setQuantity(int q){
            quantity = q;
        }
        std::string Product::getName(){
            return name;
        }
        float Product::getPrice(){
            return price;
        }
        int Product::getQuantity(){
            return quantity;
        }
        void Product::info(){
            cout << "Produkt: " << name << ", Cena: " << price <<", Ilość: " << quantity << ", Numer albumu: " << studentID << endl;
        }

        Product::~Product() {
        }
