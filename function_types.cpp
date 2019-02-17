#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

bool check(const string &test) { return test.size() == 3; }

// Functor:
struct Check {
  bool operator()(string &test) { return test.size() == 5; }
} check1;

void run(function<bool(string &)> check) {
  string test = "dog";
  cout << check(test) << endl;
}

int main() {
  int size = 5;
  vector<string> vec{"one", "two", "three"};
  // with a lambda
  cout << count_if(vec.begin(), vec.end(), [size](string test) {
    return test.size() == size;
  }) << endl;
  // with function pointer:
  cout << count_if(vec.begin(), vec.end(), check) << endl;
  // with a functor:
  cout << count_if(vec.begin(), vec.end(), check1) << endl;
  // All kinds of functions:
  run([size](string &test) { return test.size() == size; });
  run(check);
  run(check1);

  //
  function<int(int, int)> add = [](int one, int two) { return one + two; };
  cout << "7 + 3 = " << add(7, 3) << endl;

  return 0;
}
