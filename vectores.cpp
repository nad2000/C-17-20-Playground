#include <exception>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  vector<string> strings(5);
  strings[3] = "dog";
  cout << strings[3] << endl;
  cout << "SIZE: " << strings.size() << endl;
  strings.push_back("one");
  strings.push_back("two");
  strings.push_back("three");

  for (unsigned int i = 0; i < strings.size(); i++) {
    cout << i << ": " << strings[i] << endl;
  }

  // with an iterator
  for (auto it = strings.begin(); it != strings.end(); ++it)
    // cout << (it - strings.begin()) << ": " << *it << endl;
    cout << distance(strings.begin(), it) << ": " << *it << endl;

  // let's explore the change of the capacity
  vector<double> numbers(0);
  cout << "Size: " << numbers.size() << endl;
  auto capacity = numbers.capacity();
  cout << "Capacity: " << capacity << endl;
  for (int i = 0; i < 10000; ++i) {
    if (capacity < numbers.capacity()) {
      capacity = numbers.capacity();
      cout << "Capacity: " << capacity << " with " << numbers.size() << endl;
    }
    numbers.push_back(i);
  }
  numbers.resize(1000);
  cout << "After resizing..." << endl;
  cout << "Size: " << numbers.size() << endl;
  cout << "Capacity: " << numbers.capacity() << endl;

  numbers.reserve(20000);
  cout << "After reserving..." << endl;
  cout << "Size: " << numbers.size() << endl;
  cout << "Capacity: " << numbers.capacity() << endl;

  numbers.shrink_to_fit();
  cout << "After shrink_to_fit..." << endl;
  cout << "Size: " << numbers.size() << endl;
  cout << "Capacity: " << numbers.capacity() << endl;
}

