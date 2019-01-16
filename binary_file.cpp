#include <exception>
#include <fstream>
#include <iostream>
using namespace std;

// when write to file the padding should be removed
#pragma pack(push, 1)
struct Person {
  char name[50]; // 50 bytes
  int age;       // 4 bytest
  double height; // 8 bytest
};
#pragma pack(pop)

int main() {

  // C++ already pads structures
  /* cout << sizeof(Person) << endl; */
  /* cout << sizeof(char[50]) + sizeof(int) + sizeof(double) << endl; */
  Person someone = {"Frodo", 220, 0.5};
  const string fileName = "test.bin";
  fstream outputFile;
  // ofstream outputFile; // can open w/o ios::out
  outputFile.open(fileName, ios::binary | ios::out);
  if (outputFile.is_open()) {
    // outputFile.write((char *)&someone, sizeof(Person));
    // this is supposetly right way of
    // doing casting now...
    outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));
    outputFile.close();
  } else {
    cerr << "Failed to open the file '" << fileName << "'";
  }

  // Read the data ...
  Person someoneElse = {};
  fstream inputFile;
  // ofstream outputFile; // can open w/o ios::out
  inputFile.open(fileName, ios::binary | ios::in);
  if (inputFile.is_open()) {
    inputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));
    inputFile.close();
    cout << "Person[" << endl
         << "\tname: " << someoneElse.name << endl
         << "\tage: " << someoneElse.age << endl
         << "\theihgt: " << someoneElse.height << endl
         << "]" << endl;
  } else {
    cerr << "Failed to open the file for reading '" << fileName << "'";
  }
}
