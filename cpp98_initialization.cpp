#include <iostream>

using namespace std;

int main() {
  int values[] = {1, 4, 5};
  cout << values[0] << endl;

  class C {
  public:
    string text;
    int id;
  };
  C c1 = {"Hello", 7};

  struct S {
    string text;
    int id;
  };
  S s1 = {"Hello", 7};

  struct R {
    string text;
    int id;
  } r1 = {"Hello", 7}, r2 = {"Hi", 13};
  struct R r3 = {"Hello", 42};
  // or just: R r3 = {"Hello", 42};

  return 0;
}
