#include "Person.h"
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index_container.hpp>
#include <iostream>
using namespace boost::multi_index;
using namespace std;
typedef multi_index_container<
    Person, indexed_by<hashed_non_unique<member<Person, string, &Person::name>>,
                       hashed_non_unique<member<Person, int, &Person::age>>>>
    person_multi;
typedef person_multi::nth_index<0>::type name_type;
typedef person_multi::nth_index<1>::type age_type;
int main() {
  person_multi persons;
  persons.insert({"Ala", 40});
  persons.insert({"Piotr", 10});
  persons.insert({"Ola", 18});
  persons.insert({"Ala", 46});
  persons.insert({"Ula", 46});

  cout << "Liczba osob o imieniu Ala: " << persons.count("Ala") << endl;
  cout << "Liczba osob o imieniu Ala: " << persons.get<0>().count("Ala")
       << endl;
  age_type &age_index = persons.get<1>();
  cout << "Liczba osob z wiekiem 18 lat: " << age_index.count(18) << endl;
  for (name_type::iterator it = persons.get<0>().begin();
       it != persons.get<0>().end(); ++it)
    it->show();
  auto &age_indexx = persons.get<1>();
  auto it = age_indexx.find(46);
  cout << "Znaleziona osoba, ktora ma 46 lat " << it->name << endl;
  return 0;
}
