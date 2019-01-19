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
};

int main() {
  map<int, Person> people;
  // map stored elements ordered by key
  people[42] = Person("Mike", 40);
  people[13] = Person("Raj", 20);
  people[4] = Person("Vicky", 30);
  people.insert(make_pair(1, Person("John", 99)));
  for (auto const &e : people)
    cout << e.first << ": " << e.second << endl;

  return 0;
}
