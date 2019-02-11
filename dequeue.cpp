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

  vector<Test> tests;

  tests.push_back(Test(12, "John"));
  tests.push_back(Test(3, "Vicky"));
  tests.push_back(Test(11, "Mike"));
  tests.push_back(Test(42, "Sue"));

  sort(tests.begin(), tests.end());
  for (const auto &t : tests) {
    cout << t << endl;
  }

  sort(tests.begin(), tests.begin() + 3, comp);
  for (const auto &t : tests) {
    cout << t << endl;
  }
  return 0;
}

