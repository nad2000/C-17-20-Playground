#include <iostream>

using namespace std;

struct Test {
  virtual bool operator()(const string &s) = 0;
};

struct Pred : Test {
  bool operator()(const string &s) { return s == "lion"; }
};

int main() {
  Pred p;
  cout << p("life") << endl;

  return 0;
}
