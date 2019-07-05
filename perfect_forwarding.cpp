
#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

struct Test {};

template <typename T> void call(T &&arg) { check(static_cast<T>(arg)); }

void check(Test &t) { cout << "lvalue" << endl; }
void check(Test &&t) { cout << "rvalue" << endl; }

int main() {
  auto &&t = Test(); // rvalue is valid

  Test test;        // and we can compile with lvalue too
  auto &&t2 = test; // here will ocure so called "referenc collapsing"

  call(t);
  call(t2);
  call(test);
  call(Test());

  return 0;
}

// SEE: perfect forwarding, refrence collapsing
