#include <iostream>
using namespace std;

class CanGoWrong {
public:
  CanGoWrong() {
    char *pMemory = new char[999999999999];
    delete[] pMemory;
  }
};

int main() {
  // a nice way of getting error
  // in the case of constructor...
  try {
    CanGoWrong wrong;
    // } catch(bad_alloc &e) {
  } catch (exception &e) {
    cout << e.what() << endl;
    cout << "... but still running ..." << endl;
    return -1;
  }

  return 0;
}
