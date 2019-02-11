#include <iostream>

using namespace std;

class Animal {
public:
  virtual void speak() = 0;
  virtual void run() = 0;
};

class Dog : public Animal {
public:
  void speak() { // virtual can be omitted. It will be "virtual" anyway.
    cout << "Woof!" << endl;
  }
};

class Labrador : public Dog {
public:
  Labrador() { cout << "New Labrador" << endl; }
  void run() { // virtual can be omitted. It will be "virtual" anyway.
    cout << "Labrador is running!" << endl;
  }
};

int main() {
  Labrador l;
  l.speak();
  l.run();

  Animal *animals[5];
  animals[0] = &l;
  animals[0]->speak();
  animals[0]->run();

  return 0;
}
