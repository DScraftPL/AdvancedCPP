# Dziedziczenie

```cpp
class Parent {
public:
  void show(){ cout << "Hello!" << endl; }
};

class Child : public Parent {
private:
  int wiek;
public:
  Child() : Parent() {}
  Child(int _wiek) : Parent(), wiek(_wiek) {}
  void setWiek(int w){ wiek = w; }
  int getWiek() { return wiek; }
  void show(){ cout << "Hi!" << endl; }
};
```

Klasa Child dziedziczy publicznie po klasie Parent,
Konstruktor Child() korzysta z konstruktora bezparametrowego Parent(),
wiek(_wiek) pozwala zainicjować pole wiek z użyciem zmiennej wiek,
Pole wiek jest prywatne, aby do niego dojść trzeba utworzyć metody get i set,
Metoda show() została podmieniona z klasy Parent, przez co obiekt klasy Child wypisze "Hi!", zamiast "Hello!",

# Dynamiczne tworzenie 

```cpp
int tab1[10]; //tablica statyczna 10 elementów
int *tab2 = new int[10]; //tablica dynamiczna 10 elementów, 
delete [] tab2; //wymagane jest usunięcie tablicy dynamicznej
int *tab3[10]; //tablica statyczna 10 wskaźników
for(int i=0; i<10; i++){ tab3[i] = new int[10]; } //wypełnij tablicę statyczną wskaźników, tablicami dynamicznymi
for(int i=0; i<10; i++){ delete [] tab; } //zwolnij pamięć dla każdej tablicy
int **tab4 = new *int[10]; //tablica dynamiczna wskaźników
for(int i=0; i<10; i++) { tab4[i] = new int[10]; } 
for(int i=0; i<10; i++) { delete [] tab4[i]; }
delete [] tab4; //zwolnienie pamieci na wskazniki na koncu

Child c = new Child(); // stworzenie dynamiczne obiektu Child
```

# Polimorfizm Dynamiczny

```cpp
class Shape {
private:
  int obw;
  int pole;
  string nazwa;
public:
  virtual void show()=0;
  virtual void obliczPole() { pole = 0; }
  Shape();
  virtual ~Shape();
};
```

Klasa Shape jest klasą abstrakcyjną, ponieważ posiada metodę czysto wirtualną (show()). To znaczy, że nie da się utworzyć obiektu klasy Shape. 

```cpp
class Rectangle : public Shape {
private:
  int a;
public:
  Rectangle() : Shape() {}
  virtual ~Rectangle();
  virtual void show() override { cout << "Rectangle" << endl; }
  virtual void obliczPole() override { pole = a*a; }
};

Shape* x = new Rectangle();
x->show();
```

Klasa Rectangle posiada implementacje wszystkich metod, więc można utworzyć obiekt klasy Rectangle. Polimorfizm dynamiczny pozwala skorzystać z metod klasy nadrzędnej Rectangle pod postacią wskaźnika klasy bazowej Shape. Override jest opcjonalnym słowem kluczowym, zaznacza, że klasa bazowa zawierała metodę, która została przeciążona. 

# Szablony

```cpp
template <typename T>
void display(T zmienna){
  cout << zmienna << endl;
}

template <typename T1, typename T2>
class Dane {
private:
  T1 pole1;
  T2 pole2; 
public:
  Dane(T1 t1, T2 t2) : pole1(t1), pole2(t2) {}
}

display<int>(1);
display<char>('c');
display<double>(3.14);

Dane<int, string> d(1,"imie");
```

Funkcja display jest funkcją szablonową, z parametrem szablonowym T. 
Kolejne wywołania funkcji szablonowej display() zadziałają, mimo nie podania typu zmiennej. 
Klasa Dane jest klasą szablonową z dwoma parametrami szablonowymi T1 i T2.
Obiekt d został utworzony na podstawie klasy szablonowej z typami int i string.

Szablony pozwalają na utworzenie generycznej klasy, która jest uniezależniona od typu.

```cpp
template <>
void display(string zmienna){
  cout << "STRING HEHEHE" << endl;
}

string c = "hehe";
display(c);
display(c+c);
```

Specjalizacja szablonu dla typu string. Dzięki temu, możemy ustalić zachowanie funkcji dla określnego typu. 

# Kontenery Sekwencyjne

- array - tablica o stałej wielkości
- vector - tablica dynamiczna 
- list - lista 2-kierunkowa
- deque - kolejka 2-kierunkowa

Zawierają elementy tego samego typu i są uporządkowane. Dostęp do elementów jest w sposób sekwencyjny.

```cpp
#include <vector>
#include <list>
#include <array>
#include <deque>

vector<int> vec; 
list<char> li; 
array<string> ar;
deque<Data> dq;
```

vec jest wektorem przechowującym elementu typu int, li listą charów, ar tablicą stringów, a dq kolejką obiektów Data. 

```cpp
vector<int>::iterator it;
it=vec.begin();
```

iterator wskazuje na element w kontenerze sekwencyjnym. Pozwala efektywnie zarządzać kontenerem i poruszać się po jego elementach.

```cpp
class Funkcja {
  int operator()(int x){
    return x*2;
  }
}

for_each(vec.begin(), vec.end(), Funkcja());
```

klasa Funkcja jest funktorem, czyli obiektem który przeciąża/implementuje operator (). Pozwala to użyć obiektu jako funkcji. for_each jest algorytmem, który wykona operację z Funkcja() dla każdego elementu w podanym przedziale. 

# Kontenery Asocjacyjne

- set - zbiór 
- map - mapa

Umożliwiają dostęp do elementów poprzez klucze. 
