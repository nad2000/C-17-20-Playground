#include <iostream>

using namespace std;

int main() {
  int x{5};
  auto addr{&x};
  cout << "Values stored in addr is " << *addr << " at " << addr << endl;
  for (int i = 0; i < 3; i++) {
    *(++addr) = x;
    cout << "Values stored in addr is " << *addr << " at " << addr << endl;
  }
  // Just buffer flushing w/o newline:
  cout << "Flush buffer..." << flush;
  // Flushing with newline
  cout << "... With a newline " << endl;
}
