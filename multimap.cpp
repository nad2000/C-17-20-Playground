#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {

  multimap<int, string> lookup;
  lookup.insert(make_pair(30, "Mike"));
  lookup.insert(make_pair(10, "Vicky"));
  lookup.insert(make_pair(30, "Raj"));
  lookup.insert(make_pair(20, "Bob"));

  for (multimap<int, string>::iterator it = lookup.begin(); it != lookup.end();
       ++it)
    cout << it->first << ": " << it->second << endl;
  cout << "*** With 'find'..." << endl;
  for (multimap<int, string>::iterator it = lookup.find(20); it != lookup.end();
       ++it)
    cout << it->first << ": " << it->second << endl;
  cout << "*** With 'range'..." << endl;
  pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its =
      lookup.equal_range(20);
  for (multimap<int, string>::iterator it = its.first; it != its.second; ++it)
    cout << it->first << ": " << it->second << endl;

  return 0;
}
