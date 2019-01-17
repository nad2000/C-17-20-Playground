#include <exception>
#include <iostream>
using namespace std;

class MyException : public exception {
public:
  // 'const throw()' -- indicates what
  // exception the method can throw
  virtual const char *what() const throw() { return "Somethig bad happened"; }
};

class Task {
public:
  Task(){};
  virtual ~Task(){};
  // NB! ISO C++17 does not allow dynamic exception specifications
  void goesWrong() { throw MyException(); }

private:
  /* data */
};

int main() {

  try {
    Task task;
    task.goesWrong();
  } catch (exception &e) {
    cout << e.what() << endl;
    cout << "... but still running ..." << endl;
    return -1;
  }

  return 0;
}
