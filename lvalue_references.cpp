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

void check(const Test &value) { cout << "L-value function!" << endl; }

void check(Test &&value) { cout << "R-value function!" << endl; }

void intCheck(const int &i) { cout << "L-value (int) function!" << endl; }

void intCheck(int &&i) { cout << "R-value (int) function!" << endl; }

Test getTest() { return Test(); }

int getIntTest() { return 42; }

int main() {
  Test t1 = getTest();
  cout << t1 << endl;

  vector<Test> vec;
  vec.push_back(Test());

  Test &rTest1 = t1;
  vec.push_back(rTest1);
  // cannot bind non-const lvalue reference of type 'Test&' to an rvalue of type
  // 'Test':
  // Test &rTest2 = getTest();
  // But:
  const Test &rTest2 = getTest();
  vec.push_back(rTest2);

  // Compiler can do optimization using R/L-values:
  // 1. When returning a temp value like with getTest();
  // 2. When passing as an argument a temp value:
  vec.push_back(Test());

  Test &ltest1 = t1; // L-value reference
  // Test &&rtest1 = t1; // R-value reference
  Test &&rtest1 = getTest(); // R-value reference

  check(t1);
  check(getTest());
  check(Test());

  intCheck(1);
  intCheck(getIntTest());
  auto intV = getIntTest();
  intCheck(intV);
  auto &&rintV = getIntTest();
  intCheck(rintV);
  int &lintV = intV;
  intCheck(lintV);

  return 0;
}

