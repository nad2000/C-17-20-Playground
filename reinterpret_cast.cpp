#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

struct Parent {
  void speak() { cout << "parent!" << endl; }
  virtual ~Parent() {}
};

class Brother : public Parent {
  string name{"brother"};

public:
  void say() { cout << name << endl; }
};
class Sister : public Parent {};

int main() {
  Parent p;
  Brother b;
  Sister s;

  Parent *ppb = &b;
  Sister *pbb =
      reinterpret_cast<Sister *>(ppb); // less checks than with static_cast

  cout << pbb << endl;
  pbb->speak();
  return 0;
}

// More reading on: RTTI, virtual table, type_info (vtale, global data)
