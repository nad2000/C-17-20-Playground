#include "ring.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
  auto texts = {"one", "two", "three"};

  for (auto &t : texts)
    cout << t << endl;

  vector<int> numbers;
  numbers.push_back(5);
  numbers.push_back(7);
  numbers.push_back(8);
  numbers.push_back(9);
  numbers.push_back(3);
  for (auto &n : numbers)
    cout << n << endl;

  for (auto i = numbers.begin(); i != numbers.end(); ++i) {
    cout << *i << endl;
  }

  // custom range loop supporting class
  // RingBuffer
  ring<string> r(3);
  r.add("one");
  r.add("two");
  r.add("three");
  r.add("four");
  // old-school
  cout << "*** old-school:" << endl;
  for (int i = 0; i < r.size(); i++)
    cout << r.get(i) << endl;
  // iterator:
  cout << "*** iterator:" << endl;
  for (ring<string>::iterator it = r.begin(); it != r.end(); it++)
    cout << *it << endl;
  // enhanced loop:
  cout << "*** enhanced loop:" << endl;
  for (string v : r)
    cout << v << endl;

  return 0;
}
