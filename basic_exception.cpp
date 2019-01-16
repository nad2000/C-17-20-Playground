#include <iostream>

using namespace std;

void mightGoWrong(int errorType) {
  bool error = true;
  if (error) {
    switch (errorType) {
    case 0:
      throw 42;
      break;
    case 1:
      throw "Something went wrong!";
      break;
    case 2:
      throw string("Something else went wrong!");
    }
  }
}

int main() {
  try {
    mightGoWrong(0);
  } catch (int e) {
    cout << "Error code: " << e << endl;
  }
  try {
    mightGoWrong(1);
  } catch (char const *e) {
    cout << e << endl;
  }
  try {
    mightGoWrong(2);
  } catch (string const &e) {
    cout << e << endl;
  }
  cout << "Still running" << endl;

  return 0;
}
