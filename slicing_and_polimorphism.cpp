#include <iostream>
using namespace std;

class Parent {
private:
  int one;

public:
  // if copy constructor gets defined need to define teh default
  // constructor too...
  Parent() : one(0) {}
  Parent(const Parent &p) {
    one = p.one;
    cout << "Copy parent..." << endl;
  }
  void print() { cout << "Parent" << endl; }
  virtual ~Parent() {}
};

class Child : public Parent {
private:
  int two;

public:
  Child() : two(0) {}
  void print() { cout << "Child" << endl; }
};

int main() {
  Child c1;
  Parent &p1 = c1;
  p1.print();
  Parent p2 = Child();
  p2.print(); // this invoke copy constructor

  return 0;
}
