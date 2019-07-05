#include <functional>
#include <iostream>

// bind is in the std
using namespace std;
using namespace placeholders;

int add(int a, int b, int c) {
  cout << a << ", " << b << ", " << c << endl;
  return a + b + c;
}

int run(function<int(int, int)> f) { return f(7, 3); }

class Test {
public:
  int add(int a, int b, int c) {
    cout << a << ", " << b << ", " << c << endl;
    return a + b + c;
  }
  static int sadd(int a, int b, int c) {
    cout << a << ", " << b << ", " << c << endl;
    return a + b + c;
  }
};

int main(int argc, char *argv[]) {
  cout << add(1, 2, 3) << endl;

  auto caculate = bind(add, 3, 4, 5);
  // or (& is optional)
  auto caculate2 = bind(&add, 4, 5, 6);

  cout << caculate() << endl;
  cout << caculate2() << endl;

  // and now with "placeholders"
  auto caculate3 = bind(&add, _1, _2, _3);
  cout << caculate3(10, 11, 12) << endl;

  // and now with "placeholders" with different order:
  auto caculate4 = bind(&add, _2, _3, _1);
  cout << caculate4(10, 11, 12) << endl;

  // and now with "placeholders" cobined with constant arguments
  auto caculate5 = bind(&add, _1, _2, 333);
  cout << caculate5(100, 200) << endl;
  cout << run(caculate5) << endl;

  // binding to object method:
  auto t = Test{};
  auto caculate6 = bind(&Test::add, t, _1, _2, 444);
  cout << caculate6(101, 201) << endl;

  // binding to class static method:
  auto caculate7 = bind(Test::sadd, _1, _2, 555);
  // OR: auto caculate7 = bind(&Test::sadd, _1, _2, 333);
  cout << caculate7(102, 202) << endl;

  return 0;
}
