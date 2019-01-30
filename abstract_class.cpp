#include <iostream>

using namespace std;

class Animal {
public:
  virtual void speak() = 0;
};

class Dog : public Animal {
public:
  void speak() { // virtual can be omitted. It will be "virtual" anyway.
    cout << "Woof!" << endl;
  }
};

int main() {
  Dog d;
  d.speak();

  return 0;
}
