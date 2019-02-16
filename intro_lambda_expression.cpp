#include <iostream>

using namespace std;

void test(void (*pFunc)()) { pFunc(); }

int main() {
  []() {}();
  []() { cout << "Hello" << endl; }();
  auto func = []() { cout << "Hello Again" << endl; };
  func();
  test(func);
  test([]() { cout << "Hello Again and Again!" << endl; });
  return 0;
}
