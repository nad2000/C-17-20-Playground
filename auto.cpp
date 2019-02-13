#include <iostream>
#include <typeinfo>

using namespace std;

// https://stackoverflow.com/questions/22514855/arrow-operator-in-function-heading?answertab=active
template <class T, class S>
auto test(T value1, S value2) -> decltype(value1 + value2) {
  return value1 + value2;
}

int get() { return 999; }

auto test2() -> decltype(get()) { return get(); }

int main() {
  int x{5};
  auto addr{&x};
  cout << "Values stored in addr is " << *addr << " at " << addr << endl;
  for (int i = 0; i < 3; i++) {
    *(++addr) = x;
    cout << "Values stored in addr is " << *addr << " at " << addr << endl;
  }
  // Just buffer flushing w/o newline:
  cout << "Flush buffer..." << flush;
  // Flushing with newline
  cout << "... With a newline " << endl;

  auto value = 7;
  cout << "value typeid: " << typeid(value).name() << endl;
  cout << "test(5,6) typeid: " << typeid(test(5, 6)).name() << endl;
  cout << "test2() typeid: " << typeid(test2()).name() << endl;
}
