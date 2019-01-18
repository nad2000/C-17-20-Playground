#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <utility>
using namespace std;

list<int> read(string const filename);
void write(const string filename, const list<int> &numbers);

int main() {
  const string filename = "numbers.bin";
  list<int> numbers;
  numbers = read(filename);

  for (int i = 1; i < 4; ++i)
    numbers.push_back(i);
  for (int i = -1; i > -4; --i)
    numbers.push_front(i);

  auto it = numbers.begin();
  it++;
  numbers.insert(it, 42);

  it = numbers.end();
  it--;
  numbers.erase(it);
  cout << "Erased element: " << *it << endl;

  // more nightmare with iterators:
  for (list<int>::iterator it = numbers.begin(); it != numbers.end();) {
    if (*it % 2 == 0) {
      numbers.insert(it, 999 + *it);
      it++;
    } else
      it = numbers.erase(it);
  }
  write(filename, numbers);

  for (auto const &n : numbers)
    cout << n << endl;
}

list<int> read(string const filename) {
  list<int> result;
  fstream inputFile;
  inputFile.open(filename, ios::binary | ios::in);
  if (inputFile.is_open()) {
    int value;
    while (inputFile) {
      inputFile.read(reinterpret_cast<char *>(&value), sizeof(int));
      result.push_back(value);
    }
    inputFile.close();
  } else
    cerr << "Failed to open the file for reading '" << filename << "'";
  return result;
}

void write(const string filename, const list<int> &numbers) {
  fstream outputFile;
  outputFile.open(filename, ios::binary | ios::out);
  if (outputFile.is_open()) {
    for (auto &v : numbers)
      outputFile.write(reinterpret_cast<const char *>(&v), sizeof(int));
    outputFile.close();
  } else {
    cerr << "Failed to open the file '" << filename << "'";
  }
}

