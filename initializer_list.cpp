#include <initializer_list>
#include <iostream>
#include <vector>

using namespace std;

class Test {
public:
  Test(initializer_list<string> texts) {
    for (const auto &t : texts)
      cout << t << endl;
  }

  void print(initializer_list<string> texts) {
    for (const auto &t : texts)
      cout << t << endl;
  }
};

int main() {
  Test test{"apple", "oranges", "banana"};
  test.print({"one", "two", "three"});

  return 0;
}
