#include <iostream>
#include <memory> // for unique_ptr
// shared pointers destroy deallocated
// only when all pointers go out of the scope

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

  shared_ptr<Test> pt0(nullptr);
  {
    shared_ptr<Test> pt = make_shared<Test>(
        "t"); // won't get deallocted until p0 gets out of the scope.
    shared_ptr<Test> pt1 = make_shared<Test>("t1");
    pt0 = pt;
    pt->greet();
  }

  cout << "Finished" << endl;

  return 0;
}
