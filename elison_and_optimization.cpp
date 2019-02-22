#include <iostream>
#include <vector>
using namespace std;

// SEE: https://en.wikipedia.org/wiki/Copy_elision

class Test {

public:
  Test() { cout << "Default constructor" << endl; }
  Test(int i) { cout << "Parametrized constructor: " << i << endl; }
  Test(const Test &other) { cout << "Copy constructor" << endl; }
  Test &operator=(const Test &other) {
    cout << "Assignment: " << other << endl;
    return *this;
  }
  // Destructor
  ~Test() { cout << "Destructor..." << endl; }
  friend ostream &operator<<(ostream &out, const Test &t);
};

ostream &operator<<(ostream &out, const Test &t) {
  return out << "[Printing]" << endl;
}

Test getTest() { return Test(); }

int main() {
  Test t1 = getTest();
  cout << t1 << endl;

  return 0;
}

