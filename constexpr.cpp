#include <iostream>

using namespace std;

constexpr const int calc(int a) {
  auto res = a * a;
  return res;
}

int main() {
  auto v1 = calc(42);
  auto v2 = calc(42);
  cout << v1 << v2 << endl;
}
