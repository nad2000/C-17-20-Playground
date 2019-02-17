#include <iostream>

using namespace std;

void test(void (*pFunc)()) { pFunc(); }
void testGreet(void (*greet)(string)) { greet("Bob"); }
void testDivide(double (*divide)(double a, double b)) {
  auto rval = divide(9, 3);
  cout << "9 / 3 = " << rval << endl;
}

int main() {
  auto pGreet = [](string name) { cout << "Hello " << name << endl; };
  pGreet("Mike");
  testGreet(pGreet);
  testGreet([](string name) { cout << "Hello again, " << name << endl; });

  // need to use trailing return type syntac bacause
  // it is impossible to infer deterministicly the type of
  // the returned expression.
  cout << "Result: " << [](double a, double b) -> double {
    if (b == 0.0)
      return 0;
    return a / b;
  }(10., 5.) << endl;

  auto pDivide = [](double a, double b) -> double {
    if (b == 0.0)
      return 0;
    return a / b;
  };
  testDivide(pDivide);

  return 0;
}

