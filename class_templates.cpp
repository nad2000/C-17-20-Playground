#include <iostream>

using namespace std;

template <class T> class Test {
private:
  T obj;

public:
  Test(const T &obj) : obj(obj) {}
  Test() {}
  void print() { cout << obj << endl; }
};

int main() {
  Test<string> str_t("Hello world!");
  Test<int> int_t(42);
  str_t.print();
  int_t.print();
}

