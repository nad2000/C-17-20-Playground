#include <iostream>
#include <fstream>
#include <exception>
#include <vector>
using namespace std;

void writeLines(ofstream& ofs, 
		const vector<string>& lines) {
	int lineNo = 1;
	for (auto const &l: lines) {
		ofs << lineNo++ << ": " << l << endl;
	}
}

int main() {
	const char* fileName = "output.txt";
	ofstream outFile;

	outFile.open(fileName);
	
	if(outFile.is_open()) {
		outFile << "Hello there!" << endl;
		outFile << 1234567890 << endl;
		vector<string> lines = {
			"line #1",
			"line #2"
		};
		writeLines(outFile, lines);
		outFile.close();
	} else {
		cout 
			<< "Cannot create file '" 
			<< fileName << "'" 
			<< endl;
	}
}
