#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  vector<vector<int>> grid(4, vector<int>(4));
  int i = 0;
  for (auto &row : grid) {
    for (auto &e : row) {
      e = i++;
      cout << setw(3) << e;
    }
    cout << endl;
  }
}

