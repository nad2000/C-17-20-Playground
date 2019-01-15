#include <iostream>
#include <fstream>
#include <exception>
#include <vector>
#include <utility>
using namespace std;

// when write to file the padding should be removed
#pragma pack (push, 1)
struct Person {
	char name[50]; // 50 bytes
	int age; // 4 bytest
	double weight; // 8 bytest
};
#pragma pack(pop)

int main() {
	// C++ already pads structures
	cout << sizeof(Person) << endl;
	cout << sizeof(char[50]) + sizeof(int) + sizeof(double) << endl;
}
