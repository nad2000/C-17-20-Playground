#include <iostream>

using namespace std;

struct Test {
  virtual bool operator()(const string &s) const = 0;
  virtual ~Test() {}
};

// Example of functor:
struct Pred : Test {
  bool operator()(const string &s) const { return s == "lion"; }
};

void check(const string &text, const Test &t) {
  cout << (t(text) ? "match" : "no match") << endl;
}

int main() {
  Pred p;
  check("lion", p);
  check("life", p);

  return 0;
}
