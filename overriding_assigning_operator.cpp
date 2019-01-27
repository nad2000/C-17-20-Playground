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

  const Test &operator=(const Test &t) {
    id = t.id;
    name = t.name;
    cout << "Assignment running..." << endl;
    return *this;
  }
};

int main() {

  Test test1(10, "Mike");
  cout << test1 << endl;
  Test test2(20, "Bob");
  cout << test2 << endl;
  // by default C++ impolemts 'shallow copy'
  test1 = test2;
  // OR:
  test1.operator=(test2);
  cout << test1 << endl;

  return 0;
}

