#include <iostream>
#include <vector>
using namespace std;

// SEE:
// https://smartbear.com/blog/develop/c11-tutorial-explaining-the-ever-elusive-lvalues-a/
// https://www.bogotobogo.com/cplusplus/C11/4_C11_Rvalue_Lvalue.php
// https://en.cppreference.com/w/cpp/language/value_category

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

  int value1 = 7; // with C++98: value1 - L-value, 7 - R-value
  // In C++11: L-value is anything you can take an address of...
  int *pValue = &value1; // vlaue1 here is also L-value
  // int *pValue1 = &7; // can't do because '7' is R-value
  // The same true with objects:
  Test *pTest1 = &t1;
  // But not:
  // Test *pTest1 = &getTest();

  return 0;
}

