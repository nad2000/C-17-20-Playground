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

  for (unsigned int i = 0; i < strings.size(); i++) {
    cout << i << ": " << strings[i] << endl;
  }

  for (auto it = strings.begin(); it != strings.end(); ++it)
    // cout << (it - strings.begin()) << ": " << *it << endl;
    cout << distance(strings.begin(), it) << ": " << *it << endl;
}

