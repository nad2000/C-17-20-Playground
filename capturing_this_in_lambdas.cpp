#include <iostream>

using namespace std;

class Test {
private:
  int one{1}, two{2};

public:
  void run() {
    int three{3}, four{4};

    // in order to get access to the memmber attibutes,
    // thsi should be included in the capturing list.
    // NB! all memeber attributest will get captured by
    // reference, and there is no need to specify instace
    // variables at all
    auto pLambda = [this, three, four]() {
      one = 111;
      two = 222;
      cout << one << endl;
      cout << two << endl;
      cout << three << endl;
      cout << four << endl;
    };
    pLambda();
  }
};

int main() {
  Test test;
  test.run();

  return 0;
}
