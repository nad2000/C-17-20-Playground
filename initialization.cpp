#include <iostream>
#include <vector>

using namespace std;

int main() {
  int value{5};
  cout << value << endl;

  string text{"Hello"};
  cout << text << endl;

  int numbers[]{1, 2, 4};
  cout << numbers[1] << endl;

  int *pInts = new int[3]{1, 2, 3};
  cout << pInts[1] << endl;
  delete[] pInts;

  int value1{};
  cout << value1 << endl;

  int *pSomething{&value};
  cout << *pSomething << endl;

  int *pSomething1{}; // = int *pSomething = nullptr;
  cout << pSomething1 << endl;

  struct {
    int value;
    string text;
  } s1{5, "Hi"}, s2{};
  cout << s1.value << "/" << s2.value << endl;

  // initializatio list
  vector<string> strings{"one", "two", "three"};
  cout << strings[2] << endl;

  return 0;
}
