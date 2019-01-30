#include <iostream>
using namespace std;

// actually 'virtual' methods are function pointer in a way

void test() { cout << "Hello" << endl; }
void test_2(int value, string str) {
  cout << "Hello: " << value << " / " << str << endl;
}

int main() {
  // while
  // void *pTest();  // is a function returning a pointer to 'void' :)
  // (anything)
  void (*pTest)(); // is a function pointer to a void function (a function that
                   // doesn't
                   // return anything.

  test();
  pTest = &test;

  (*pTest)(); // and this how we call it. Not *pTest();
  // that would dereference the void :(
  // However, this will work too:
  pTest();

  // short-cut:
  void (*pTest0)() = test;
  pTest0();
  void (*pTest2)(int, string) = test_2;
  // void (*pTest2)(int, string) = test; // this doesn't work
  pTest2(42, "Hello Again!");

  return 0;
}
