#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
  map<string, int> ages;

  ages["Mike"] = 40;
  ages["Raj"] = 20;
  ages["Vicky"] = 30;

  // many ways of adding entry:
  pair<string, int> age("Peter", 100);
  ages.insert(age);
  ages.insert(pair<string, int>("John", 101));

  if (ages.find("Vicky") != ages.end()) {
    cout << "Found Vicky" << endl;
  } else {
    cout << "Not Found" << endl;
  }

  for (auto const &n : vector<string>{"Mike", "Raj", "Vicky"})
    cout << ages[n] << endl;

  for (map<string, int>::iterator it = ages.begin(); it != ages.end(); ++it) {
    age = *it;
    cout << it->first << ": " << it->second << endl;
    // OR:
    cout << age.first << ": " << age.second << endl;
  }

  return 0;
}
