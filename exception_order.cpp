#include <iostream>
#include <exception>
using namespace std;

void goesWrong() {
	throw exception();
	throw bad_alloc();
}

int main() {
	try {
		goesWrong();
	} catch (bad_alloc &e) {
		cout << "Caught a bad_alloc exception... " << endl;
	} catch (exception &e) {
		cout << "Caught a generic exception... " << endl;
	}
}
	

