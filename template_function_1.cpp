#include <iostream>
using namespace std;

// template<class T>
template <typename T> // the same as 'class'
void print(const T &n) {
  cout << "Template version: " << n << endl;
}

void print(const int &n) { cout << "Non-template version: " << n << endl; }

template <class T> void show() { cout << "T(): " << T() << endl; }

int main() {
  print<int>(42);
  print<string>("Hello World!");
  // no need to specify type, C++ can infer them
  print(
      42); // though since here closer match will be the non-template function.
  // but themplated version can be denoted wiht <>
  print<>(42);
  print("Hello World!");
  // cannot infer with
  // show();
  // show<>();
  // BUT:
  show<double>(); // is fine.
  show<int>();    // is fine.

  return 0;
}

