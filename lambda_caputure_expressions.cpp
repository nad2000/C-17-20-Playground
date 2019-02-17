#include <iostream>

using namespace std;

int main() {
  int one = 1, two = 2, three = 3;
  // Capture lacal variables by value
  [one, two, three]() {
    cout << one << ", " << two << ", " << three << endl;
  }();
  // Capture all local variables by value
  [=]() { cout << one << ", " << two << ", " << three << endl; }();
  // Capture all local variables by value, and three by reference
  [=, &three]() {
    // one = 42; // ERROR: assignement of read-only variable 'one'
    three = 7;
    cout << one << ", " << two << ", " << three << endl;
  }();
  cout << "Variables: " << one << ", " << two << ", " << three << endl;
  // Capture all local variables by reference
  [&]() {
    one = 42;
    three = 3;
    two = 22;
    cout << one << ", " << two << ", " << three << endl;
  }();
  cout << "Variables: " << one << ", " << two << ", " << three << endl;
  // Capture all local variables by reference, but three by value
  [&, three]() {
    one = 99;
    // three = 3;
    two = 88;
    cout << one << ", " << two << ", " << three << endl;
  }();
  return 0;
}

