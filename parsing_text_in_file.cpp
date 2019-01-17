#include <exception>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

static const string fileName = "stats.txt";

vector<pair<string, int>> readLines(ifstream &ifs) {
  vector<pair<string, int>> lines{};
  string country;
  int population;
  while (ifs) { // == !ifs.eof()
    getline(ifs, country, ':');
    ifs >> population;
    ifs >> ws; // reads up 'white spaces' or use ifs.get(); // to digest '\n'
    if (country != "")
      lines.push_back(make_pair(country, population));
  }
  return lines;
}

int main() {
  ifstream inFile; // or fstream and then open with 'ios:in'

  inFile.open(fileName);

  if (inFile.is_open()) {
    auto lines = readLines(inFile);
    int lineNo = 1;
    for (const auto &l : lines) {
      cout << lineNo++ << ":" << l.first << " -- " << l.second << endl;
    }
    inFile.close();
  } else {
    cout << "Cannot open file '" << fileName << "'" << endl;
    return -1;
  }
}
