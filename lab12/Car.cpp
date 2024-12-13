#include "Car.h"
#include <iostream>

using namespace std;

Car::Car(std::string _m, int _r, int _p) : model(_m), rok(_r), pojemnosc(_p) {}
std::string Car::getMod() { return model; }
int Car::getRok() { return rok; }
int Car::getPoj() { return pojemnosc; }
void Car::setMod(std::string _m) { model = _m; }
void Car::setRok(int _r) { rok = _r; }
void Car::setPoj(int _p) { pojemnosc = _p; }
void Car::show() { cout << model << " " << pojemnosc << " " << rok << endl; }
