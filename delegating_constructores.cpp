#include <iostream>
using namespace std;

class Parent {
  int dogs;
  string text;

public:
  Parent() : Parent("Default") {
    cout << "No parameter parent constructor" << endl;
  }
  Parent(string text) : dogs(5) {
    this->text = text;
    cout << "String parent constructor with \"" << text << "\"" << endl;
  }
};

class Child : public Parent {
public:
  // Child constructor implicitly would call the default constructor.
  Child()
      : Parent("Hello") {
  } // This works only with C++11 (delegated constructors)
  // Pre C++11 general approach was to define "init" method
};

int main() {
  Parent p0;
  Parent p("Parent");
  Child c;

  return 0;
}
