// decltype - C++11 keyword
// typeid - C++98

#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
  int value;
  string str;
  struct {
    int value;
  } s;
  struct S {
    int value;
  };
  S s_;
  cout << "typeid: " << typeid(value).name() << endl;
  cout << "typeid: " << typeid(str).name() << endl;
  cout << "typeid: " << typeid(s).name() << endl;
  cout << "typeid: " << typeid(s_).name() << endl;

  decltype(value) value2;
  decltype(str) str2;
  decltype(s) s2;
  decltype(s_) s_2;

  cout << "typeid: " << typeid(value2).name() << endl;
  cout << "typeid: " << typeid(str2).name() << endl;
  cout << "typeid: " << typeid(s2).name() << endl;
  cout << "typeid: " << typeid(s_2).name() << endl;

  return 0;
}

