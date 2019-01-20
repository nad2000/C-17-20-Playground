#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Person {
private:
  string name;
  int age;

public:
  Person() { cout << "Default constructor running..." << endl; }
  Person(Person const &p) : name(p.name), age(p.age) {
    cout << "Copy constructor running..." << endl;
  }
  Person(string name, int age) : name(name), age(age) {}
  friend ostream &operator<<(ostream &out, const Person &p) {
    return out << "Person[name: '" << p.name << "', age: " << p.age << "]";
  }
  // need to implement '<' to use the class objects as keys
  bool operator<(const Person &other) const
  /* this tells that 'this' doesn't get changed either */ {
    if (name == other.name) {
      return age < other.age;
    } else {
      return name < other.name;
    }
  }
};

int main() {
  map<Person, int> people;
  // map stored elements ordered by key
  people[Person("Mike", 40)] = 40;
  people[Person("Mike", 40)] = 42;
  people[Person("Mike", 4444)] = 42;
  people[Person("Raj", 20)] = 20;
  people[Person("Vicky", 30)] = 30;
  // people.insert(make_pair(1, Person("John", 99)));
  for (map<Person, int>::iterator it = people.begin(); it != people.end(); ++it)
    cout << it->first << ": " << it->second << endl;
  for (auto const &e : people)
    cout << e.first << ": " << e.second << endl;

  return 0;
}
