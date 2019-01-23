#include <fstream>
#include <iostream>
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

  // friend gives access to the private members to the function
  friend ostream &operator<<(ostream &out, const Test &t);

  // need this one for sets:
  bool operator<(const Test &other) const {
    return id < other.id; /*name < other.name;*/
  }
};

// implimentation of the function.
// the prototype typically gets placed in the header file.
ostream &operator<<(ostream &out, const Test &t) {
  return out << "Test[id: " << t.id << ", name: '" << t.name << "']";
}

int main() {
  Test test1(10, "Mike");
  cout << test1 << endl;
  Test test2(20, "Bob");
  cout << test2 << endl;
  cout << test1 << endl << test2 << endl;

  return 0;
}
