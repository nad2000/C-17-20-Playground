#include <fstream>
#include <iostream>
#include <set>
using namespace std;

class Test {
private:
  int id;
  string name;

public:
  Test(int id, string name) : id(id), name(name) {}
  Test(const Test &t) : id(t.id), name(t.name) {}
  Test() {}
  friend ostream &operator<<(ostream &out, const Test &t) {
    return out << "Test[id: " << t.id << ", name: '" << t.name << "']";
  }
  // need this one for sets:
  bool operator<(const Test &other) const { return name < other.name; }
};

int main() {

  set<int> numbers;
  numbers.insert(50);
  numbers.insert(10);
  numbers.insert(20);
  numbers.insert(30);
  numbers.insert(30);
  numbers.insert(50);

  for (set<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
    cout << *it << endl;

  set<int>::iterator itFind = numbers.find(30);
  if (itFind != numbers.end())
    cout << "Found: " << *itFind << endl;

  if (numbers.count(30))
    cout << "Number found." << endl;

  set<Test> tests;
  tests.insert(Test(12, "Mike"));
  tests.insert(Test(42, "Joe"));
  tests.insert(Test(13, "Sue"));
  for (auto const &t : tests)
    cout << t << endl;

  return 0;
}

