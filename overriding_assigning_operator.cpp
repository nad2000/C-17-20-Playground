#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Test {
private:
  int id;
  string name;

public:
  Test(int id, string name) : id(id), name(name) {}
  Test(const Test &t) : id(t.id), name(t.name) {}
  Test() {}
  ~Test() { cout << "Object destroyed" << endl; }

  friend ostream &operator<<(ostream &out, const Test &t) {
    return out << "Test[id: " << t.id << ", name: '" << t.name << "']";
  }
  // need this one for sets:
  bool operator<(const Test &other) const {
    return id < other.id; /*name < other.name;*/
  }
  friend bool comp(const Test &a, const Test &b); // give access to a funcion
};

// alternatively ot overriding '<':
bool comp(const Test &a, const Test &b) { return a.name < b.name; }

int main() {
  Test test1(10, "Mike");
  cout << test1 << endl;
  Test test2(20, "Bob");
  cout << test2 << endl;
  // by default C++ impolemts 'shallow copy'
  test1 = test2;
  cout << test1 << endl;

  return 0;
}

