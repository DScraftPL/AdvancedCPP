szlak mnie ten teges trafi

konsultacje mailowo

test na koniec
na kartkach
wielokrotny

wyklad 10 gdzies wczesniej, bo lambda

bez przepisywania na razie

podstawowe pojęcia obiektowego
sposob pisania programów OOP

problem => klasa z metodami => obiekty 
program == praca na obiektach, powiązanych związkami

obiekt ma określony zestaw zachowań

Abstrakcja - skupić sie na rozwiązaniu problemu
Hermetyzacja - blokowanie dostępu
Dziedziczenie - 

Raz zddefiniowana klasa, wiele razy wykorzystana

klasa jest typem, podobny do struktury
pola i metody łączymy w jedną całość

deklaracja klasy - z jakich składowych sie składa (pola, metody i z których użytkownik możę skorzystać)
definicja klasy - implementacja metod klasy

interfejs - ...

klasy konkretne - typy wbudowane, odpoweidniki ich
klasy abstrakcyjne - czysty interfejs do klas potomnych, metody bez implementacji

public wszedzie, protected tylko w potomnych, private tylko dla klasy
zaprzyjazione? friend - cos zewnętrznego, widzą co jest w private

domyslnie prywatne C++

statyczne - przypisane do klasy, nie obiektu, wspolny element
atrybut identyczny dla wszystkich obiektów

konstruktor z listą inicjalizacyjną

accessory - metody dostępowe do pól set i get
pole -> 2 metody 

Konstrutor kopiujący -> kopiowanie obiektów const className& s, przypisuje to co z obiektu s do nowego. 

#dyrektywa preprocesora
#define MAKRO

statyczne pole musi być redefiniowane pozaklasą, chyba trzeba

//xD tablice znakowe,, str_cpyXDDDDDD

przeciążanie operatorów pogu

klasy wyliczeniowe,

enum class Color {red, blue, green}; 0,1,2
Color col = Color::red; <- git gud, 

w abstrakcyjnej interfejs, który bedziemy wykorzystywać

virutal int size() const=0; <- abstrakcyjna

nie da sie utworzyć obiektu, ale można użyć klasę potomn, która pochodzi z intefejsu za pomocą use ? 

override (opcjonalne), przeciążą funkcje

funkcja stała const; wewnątrz nie można zmienić atrybutów, są do odczytu
przeciążenie konstruktorów

konstruktor nie tworzy obiektów, tworzy je środowisko
konstruktor jest uruchamiany, może inicjalizować, klika -> przeciążone

klasa(int p1=1, int p2=2) -> WARTOŚCI DOMYŚLNE WWWWWWWWWWW

konstruktor przenoszący? przenoszenie danych??
kopiujący kopiuje dane
delegatowy (C++11) wywoływanie równorzędnego konstruktora,

klasa(int x): pole(x) {}; <- konstruktor parametrowy
klasa() : pole(5) <- konsturktor domyślny uruchamia delegata, którym jest konstruktor parametrowy

przenoszenie vs kopiowanie, np. przenoszący zmienia tylko adresy początkowe tablic (xD)

z = x - kopiujący
y = std::move(x) - przenoszący

Destruktor
wyjscie z bloku
nie zwalnia pamieci, nie likwiduje obiektu, sprząta po obiekcie

przeciązanie funkcji - definiowanie wielu funkcji o tej samej nazwie, inne parametry

przesłanianie nazw - pola, pola w klasie takie same jak zmienne lokalne

nazwaKlasy::nazwa -- pole w klasie
nazwa -- pole lokalne

nie ma konstruktora, domyślny działa

C++03 //fajna prehistoria heheheheheheheh

auto x : v 

pętla zakresowa 
for(auto x : v) v = {1,2,3}

int d1 = 2 === int d1 {2} === int d1 = {2} === auto d1 = 2

auto automatycznie dedukuje typ, ogarnia to kompilator

przed konstruktorem explicit, zabrania przypisania jawnej konwersji na typ klasowy

metoda jako default, jezeli klasa nie ma konstruktora to utworzy sie konstruktor bezparametrowy

automatycznie robi sie: domyslny, przypisania, kopiujący
  ALE jeżeli zrobimy własny konstruktor, to domyślny nie zadziała,
  aby utworzyc domyslny trzeba albo uwtorzyć go samemu, AlBO klasa() = default
  klasa () = delete -- kompilator nie wygeneruje metody, tutaj nie wygeneruje domyślnego
  klasa (const klasa &) = delete - kompilator nie wygeneruje kompiującego

  można zablokować metody
    void m1(double x)
    void m1(int x) = delete <- blokada niejawnej konwersji

Obiekt -  zmienna typu klasowego, instancja klasy
  Tożsamość - ID, nazwa, "uchwyt"
  Stan - zawartość komórek w obiekcie, zmienny w czasie
  Sposób zachowania - zbiór operacji na obiekcie, metody

statyczne - przypisane do klasy

Komunikat!
  obiekty jeżeli między sobą działają, wysyłają sobie komunikaty
  wywołanie publicznych składowych dla obiektu
    nazwa obiektu do którego kierujemy
    nazwa metody
    parametry

  "obiektowy odpowiednik wywołania funkcji/procedury"

Pracowanie na obiektach
  przez zmienną
    klasa obiekt; klasa obiekt(parametry);
    klasa obiekt = klasa(parametry);
    obiekt.metoda()
  przez wskaźnik (adres obiektu)
    klasa* wsk = new klasa;
    wsk->metoda();
    delete wsk;
  przez referencje "druga nazwa obiektu (?)"
    klasa obiekt;
    klasa &ref = obiekt;
    obiekt.metoda();

funkcja pracuje na referencji - pracuje na oryginale
funkcj pracuje na zmienne - pracuje na kopii

hermetyzacja, wszystko domyślnie w C++ jest prywatne 
"ukrywa informacje wrażliwe"
dane dostępowe za pomocą metod set i get

Hermetyzacja - ogarniczenie dostępu do pól, aby użytkownik nie używał klasy błędnie

Published (?) - graficzne, czasami dostępne, wpływ na komponenty wizualne, ale deprecated AF

KONSTRUKTOR TO METODA KLASY
FRIEND NIE JEST METODĄ KLASY, to jest coś zewnętrznego, ma dostęp do wszystkich składowych
  friend to "łamanie" hermetyzacji

Dziedziczenie!
  Powtórne wykorzystanie kodu, tworzenie klasy na podstawie klas bazowych, utworzonych wcześniej
  Klasa potomna zawiera wszystko co posiadał przodek, w C++ jest możliwe wielokrotne, od wielu klas
  Można ułożyć hierarhie
  Bazowa -> Potomna1 -> Potomna 2

  Dziedziczy się co to jest public i protected, klasa potomna widzi te składniki
  sekcja prywatna jest dziedziczona, ale nia ma dostępu do niej

  Nie dziedziczy się:
    konstruktora, przypisanania przeciążonego i destruktora
    od C++11 można niby odziedziczyć, ale coś tam coś tam

  

Klasa potomka decyduje co przejąć w protected i public

class potomna : public bazowa {};

Public- public w potomku, protected protected
Protected - public i protected są protected w potomku
Private - public i protected sa private w potomku

Przeciążanie metod - różnią sie parametrami, mają tą samą nazwę
Przesłanianie metod - metoda zdefiniowana w przodku zasłania metodę odziedziczoną

Obiekt klasy potomenj zawiera w sobie obiekty klasy bazowej
  (zdefiniowanie konstruktorów domyślnych i wypisz na ekran, czarna magia!)

using przodek::przodek -- wszystkie konstruktory są porzenoszone

wielokrotne dziediczenie, konstrukcja jak podane, destrukcja odwrotnie
2 razy nie mozna dziediczyc po tym samym, bo  są problemy

przy potwórzeniu klasy bazowej, obiekt wystąpi wtedy dwa razy, obejść to można z dziedziczeniem virtualnym

konflikty nazw składowych oganrnia operator zasięgu ::

A::x 
B::x
inaczej błąd w kompilacji

//pytania na obronie są ogólne, nie z kodu
//live zientar reacion:(xd):-?.?..:-;
Polimorfizm
  wielepostaciowość
  komunikat wysyłany do obiektu, wymaga podjęcia działania

  przesłanianiae procedór wspólnym sposobem wywołania

  metody virtualne - polimorfizm dynamiczny

  przeciązanie i przesłanianie też jest - polimorfizm statyczny

  virtual - późne wiązanie - przy wykonaniu
  wczesne wiązanie metod - kompilacja 

  
Dynamiczny  - virtual przed metode
  w potomku metoda cały czas jest virtualna
  nie trzeba override podawać, by zredefiniować

  najwieksze możliwości!

  destrukor wirtualny zawsze posprząta po obiekcie, gdy tworzymy pola dynamiczne

  metody wirtualne zajmują więcej miejsca
  metody wirtualne nawet w klasie bazowej nie są związane, przesłonięte metody w potomnej, a wywoływane w bazowej przesłonięte zostaną

Specjalizacja klas - związki dziedziczenia
  Student -> Osoba
Asocjacja - przyporządkowanie jednego obiektu do drugiego

Szablony - programowanie generyczne, uogólnione
  wspólny algorytm, niezależny od typów danych
  szablony funkcji i klasy
  szablon posiada jako parametr albo typ typ generyczny

  szablony funkcji - mechanizm funkcji na podstawie ktorego tworzona jest rodzina funkcji
    które można zastosować dla różnych typów

  operator warunkowy warunek ? a : b 
  parametr szalbonnu <typename T> - uniwersalny typ

  kod źródłowy jest krótszy, ale wykonywalny sie nie zmieni, bo wygeneruje pod to co mu trzeba
  jawna specjalizacja ma mieć template<> w najnowszym standardzie

Szablon można przeciążyć (ja pierdolsztajn)
identyczne nazwy funkcji w tym samym zakresie

szablon klasy może posiadać funkcję spoza szablonu, 
może być przyjacielem inny szablon klasy,
mogą być zaprzyjaźnione niezależne szablony

polimorfizm dynamiczny - hierarchia dziedziczenia, metody wirtualne
przykładlem polimorfizmu statycznego jest szablon czy przeciążanie operatorów

Programowanie generyczne:
  jego celem jest kod do masowego wykorzystania


string porownuje na podstawie pierwszych liter

lambdy:

[kopie], (parametry) -> typzwracany { ciało }
[=] -> wszystkie zmienne w kodzie
[&] -> wszystkie zmienne jako referencje
[this] -> pracuej na oryginale 
