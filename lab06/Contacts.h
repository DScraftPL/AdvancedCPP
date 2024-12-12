#include "Contact.h"
#include <algorithm>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index_container.hpp>
#include <iostream>
#include <set>
using namespace boost::multi_index;
using namespace std;

typedef multi_index_container<
    Contact,
    indexed_by<
        hashed_non_unique<member<Contact, string, &Contact::imie>>,
        hashed_non_unique<member<Contact, string, &Contact::nazwisko>>,
        hashed_non_unique<member<Contact, int, &Contact::wiek>>,
        hashed_non_unique<member<Contact, string, &Contact::ulica>>,
        hashed_non_unique<member<Contact, string, &Contact::numer_telefonu>>>>
    Contact_book;

class Contacts {
private:
  Contact_book contact_book;

public:
  void add(Contact kontakt) {
    auto &phone_index = contact_book.get<4>();
    auto it = phone_index.find(kontakt.numer_telefonu);
    if (it == phone_index.end()) {
      contact_book.insert(kontakt);
    }
  }
  void del(string numer) {
    auto &phone_index = contact_book.get<4>();
    auto it = phone_index.find(numer);
    if (it != phone_index.end()) {
      phone_index.erase(it);
    }
  }
  void find_street(string street) {
    auto &street_index = contact_book.get<3>();
    auto range = street_index.equal_range(street);
    for (auto it = range.first; it != range.second; it++) {
      cout << it->imie << " " << it->nazwisko << " " << it->wiek << " "
           << it->ulica << " " << it->numer_telefonu << endl;
    }
  }
  void find_age(int min, int max) {
    auto &age_index = contact_book.get<2>();
    for (int i = min; i < max; i++) {
      auto range = age_index.equal_range(i);
      for (auto it = range.first; it != range.second; it++) {
        cout << it->imie << " " << it->nazwisko << " " << it->wiek << " "
             << it->ulica << " " << it->numer_telefonu << endl;
      }
    }
  }
  void find_phone(string number) {
    auto &phone_index = contact_book.get<4>();
    auto it = phone_index.find(number);
    if (it != phone_index.end()) {
      cout << it->imie << " " << it->nazwisko << " " << it->wiek << " "
           << it->ulica << " " << it->numer_telefonu << endl;
    }
  }
  void change_street(string old_street, string new_street) {
    auto &street_index = contact_book.get<3>();
    auto range = street_index.equal_range(old_street);
    vector<Contact> to_change;
    for (auto it = range.first; it != range.second; it++) {
      to_change.push_back(*it);
    }
    for (auto &kontakt : to_change) {
      street_index.erase(street_index.find(kontakt.ulica));
    }
    for (auto konkakt : to_change) {
      konkakt.ulica = new_street;
      contact_book.insert(konkakt);
    }
  }
  void count_18() {
    cout << count_if(contact_book.begin(), contact_book.end(),
                     [](auto kontakt) { return kontakt.wiek > 18; });
  }
  void count_unique_surname() {
    auto &surname_index = contact_book.get<1>();
    set<string> surnames;
    for (auto it = surname_index.begin(); it != surname_index.end(); it++) {
      surnames.insert(it->nazwisko);
    }
    cout << surnames.size() << endl;
  }
  void show() {
    for (auto kontakt : contact_book) {
      cout << kontakt.imie << " " << kontakt.nazwisko << " " << kontakt.wiek
           << " " << kontakt.ulica << " " << kontakt.numer_telefonu << endl;
    }
  }
};
