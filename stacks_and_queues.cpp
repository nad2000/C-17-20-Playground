#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
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

int main() { return 0; }

