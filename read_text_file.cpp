#include <exception>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

vector<string> readLines(ifstream &ifs) {
  vector<string> lines{};
  string line;
  while (ifs) { // == !ifs.eof()
    getline(ifs, line);
    if (line != "")
      lines.push_back(line);
  }
  return lines;
}

int main() {
  const char *fileName = "test.txt";
  ifstream inFile; // or fstream and then open with 'ios:in'

  inFile.open(fileName);

  if (inFile.is_open()) {
    auto lines = readLines(inFile);
    int lineNo = 1;
    for (const auto &l : lines) {
      cout << lineNo++ << ":" << l << endl;
    }
    inFile.close();
  } else {
    cout << "Cannot open file '" << fileName << "'" << endl;
  }
}
