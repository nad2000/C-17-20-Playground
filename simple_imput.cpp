#include <iostream>

using namespace std;

int main() {
  int input;
  cout << "Please enter a number" << endl;
  try {
    cin >> input;
  } catch (string message) {
    cout << message << endl;
  }
  cout << "You have entered " << input << endl;
}
