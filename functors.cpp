#include <iostream>

using namespace std;

struct Test {
  virtual bool
  operator()(const string &s) const = 0; // indicates 'pure virtual function'
  /* A pure virtual function is a virtual function that is used when the
designer of the class wants to force derived classes to override the function
and provide their own implementation.

If a class contains any pure virtual functions, it is considered an "abstract"
class and instances of that class cannot be instantiated.

C++ uses the special syntax = 0; to indicate pure virtual functions instead of
adding a new keyword to the language (as languages like C# do). You can think of
it as setting the function pointer to 0. */
  virtual ~Test() {}
};

// Example of functor:
struct Pred : Test {
  // the functor can have some state too:
  // by definition, a functor is a function object used to pass function
  // pointers along with its state
  bool operator()(const string &s) const { return s == "lion"; }
};

struct PredWithState : Test {
  // the functor can have some state too:
  // by definition, a functor is a function object used to pass function
  // pointers along with its state

  bool operator()(const string &s) const { return s == "lion"; }
  PredWithState(const string s) { this->s = s; }

private:
  string s;
};

void check(const string &text, const Test &t) {
  cout << (t(text) ? "match" : "no match") << endl;
}

int main() {
  Pred p;
  check("lion", p);
  check("life", p);

  PredWithState p1{"life"};
  check("lion", p1);
  check("life", p1);

  check("life", PredWithState("no match"));

  return 0;
}
