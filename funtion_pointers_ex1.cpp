#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool match(string test) { return test.size() == 3; }

int countStrings(vector<string> &texts, bool (*match)(string test)) {
  int tally = 0;
  for (auto const &t : texts) {
    if (match(t))
      tally++;
  }
  return tally;
}

int main() {
  vector<string> texts = {"one", "two", "three", "two", "four", "tow", "thtee"};
  cout << match("one") << endl;
  cout << count_if(texts.begin(), texts.end(), match) << endl;
  cout << "Count Strings: " << countStrings(texts, match) << endl;

  return 0;
}
