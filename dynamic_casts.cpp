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

  float v = 3.23;
  cout << (int)v << endl;              // direct casting
  cout << int(v) << endl;              // initializing a new int;
  cout << static_cast<int>(v) << endl; // special, safe casting ...

  Parent *pp = &b;
  // Brother *pb = &p;  // won't work, but can be forces using "static_cast":
  Brother *pb = static_cast<Brother *>(
      &p); // there can be all kinds of probles with virtual functions...

  cout << "Brother: " << &b << endl;
  cout << "Parent(from B): " << pp << endl;

  cout << "Parent: " << &p << endl;
  cout << "Brother(from P): " << pb << endl;

  Brother *pbb = static_cast<Brother *>(pp);
  cout << pbb << endl;
  b.speak();
  pbb->speak();
  pp->speak();
  // static casting allows casting "back" to a wrong type:
  Brother *pbb0 = static_cast<Brother *>(&p);
  cout << pbb0 << endl;
  pbb0->speak();
  // pbb0->say(); // Parent didn't have this method .. it leads to a crash!
  // dynamic cast prevents that returning nulptr if the cast is incorrect:
  Brother *pb1 =
      dynamic_cast<Brother *>(&p); // clang and gcc don't allow that: error:
                                   // 'Parent' is not polymorphic until at least
                                   // one virtual menthod gets added (eg,
                                   // virtual destructor)
  cout << pb1 << endl;
  if (pb1 == nullptr)
    cout << "Invalid cast" << endl;
  // in summary: dynamic cast in the contrast to the static caset does a
  // run-time type-check...

  return 0;
}

// More reading on: RTTI, virtual table, type_info (vtale, global data)
