#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

// SEE: https://en.wikipedia.org/wiki/Copy_elision

class Test {
private:
  static const int SIZE = 100;
  int *_pBuffer{nullptr}; // a good practice to initialize a pointer to
                          // 'nullptr'. It might reduce any bugs...

public:
  Test() {
    cout << "Default constructor" << endl;
    // _pBuffer = new int[SIZE];
    // memset(_pBuffer, 0, sizeof(int)*SIZE); // old-school approach
    // New way (C++11):
    //_pBuffer = new int[SIZE](); // OR
    _pBuffer = new int[SIZE]{};
  }
  Test(int i) {
    cout << "Parametrized constructor: " << i << endl;
    // with C++11, a constructor can call another constructor
    _pBuffer = new int[SIZE];
    for (int j = 0; j < SIZE; j++)
      _pBuffer[j] = i;
  }
  Test(const Test &other) {
    cout << "Copy constructor" << endl;
    _pBuffer = new int[SIZE];
    // one way with 'memcpy':
    memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
    // problems that can occure: memory overruns...
  }
  // Move Constructor is similar to the copy constructor, but it uses R-value
  // references. It reuses the resorces of a temporal object:
  Test(Test &&other) {
    cout << "** Move constructor" << endl;
    _pBuffer = other._pBuffer;
    other._pBuffer = nullptr; // this prevent deltetion of the allocated memory
  }

  Test &operator=(const Test &other) {
    cout << "Assignment: " << other << endl;
    memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
    return *this;
  }
  // Move assignment:
  Test &operator=(Test &&other) {
    cout << "Move Assignment" << endl;
    // First we need to deallocate any memeory athat might have been allocated
    delete[] _pBuffer;
    _pBuffer = other._pBuffer;
    other._pBuffer = nullptr; // this prevent deltetion of the allocated memory
    return *this;
  }
  // Destructor
  ~Test() {
    cout << "Destructor..." << endl;
    delete[] _pBuffer;
  }
  friend ostream &operator<<(ostream &out, const Test &t);
};

ostream &operator<<(ostream &out, const Test &t) {
  return out << "[Printing]" << endl;
}

Test getTest() { return Test(); }

int main() {
  vector<Test> vec;
  vec.push_back(Test());

  Test t = Test(); // will get otimized with using any assignement operator
  Test t0;
  t0 = getTest();
  t0 = Test();
  t0 = Test(42);

  return 0;
}

