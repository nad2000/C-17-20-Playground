#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Test {
private:
  int id;
  string name;

public:
  Test(int id, string name) : id(id), name(name) {}
  Test(const Test &t) : id(t.id), name(t.name) {}
  Test() {}
  ~Test() { cout << "Object destroyed" << endl; }

  friend ostream &operator<<(ostream &out, const Test &t) {
    return out << "Test[id: " << t.id << ", name: '" << t.name << "']";
  }
  // need this one for sets:
  bool operator<(const Test &other) const { return name < other.name; }
};

int main() {

  stack<Test> testStack;

  testStack.push(Test(11, "Mike"));
  testStack.push(Test(12, "John"));
  testStack.push(Test(42, "Sue"));
  cout << "Top: " << testStack.top() << endl;
  // NB! BEWARE!!!
  auto &test1 = testStack.top();
  cout << "Still here (reference to destroyed): " << test1 << endl;
  testStack.pop();
  cout << "Top: " << testStack.top() << endl;

  // FIFO
  queue<Test> testQueue;
  testQueue.push(Test(11, "Mike"));
  testQueue.push(Test(12, "John"));
  testQueue.push(Test(42, "Sue"));

  while (testQueue.size() > 0) {
    Test &test = testQueue.front();
    cout << "Test: " << test << endl;
    testQueue.pop();
  }

  return 0;
}

