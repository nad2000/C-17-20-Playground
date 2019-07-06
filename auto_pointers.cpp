#include <iostream>
#include <memory> // for unique_ptr

using namespace std;

class Test {
private:
  string n;

public:
  Test() : n{"N/A"} { cout << "created" << endl; }
  Test(string name) : n{name} { cout << "created" << endl; }

  void greet() { cout << "hello! this is " << n << endl; }
  ~Test() { cout << n << " destroyed" << endl; };
};

int main(int argc, char *argv[]) {

  unique_ptr<int> pTest(new int);
  *pTest = 7;
  cout << *pTest << endl;

  unique_ptr<Test> pt(new Test("t"));
  auto pt0 = new Test(
      "t0"); // this one won't get destroyed when it gets out of context.
  pt0->greet();
  pt->greet();
  {
    // with arrays
    unique_ptr<Test[]> pta(new Test[2]);
    pta[1].greet();
  }

  // prior C++11 there wehre auto_ptr (now depricated) for this job.
  unique_ptr<Test> pt1(new Test("t1"));
  pt1->greet();

  cout << "Finished" << endl;

  return 0;
}
