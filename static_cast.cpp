#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

struct Parent {
  void speak() { cout << "parent!" << endl; }
};

class Brother : public Parent {};

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

  return 0;
}
