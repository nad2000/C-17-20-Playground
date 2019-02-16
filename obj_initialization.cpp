#include <initializer_list>
#include <iostream>
#include <vector>

using namespace std;

class Test {

  int id{3};
  string name{"Mike"};

public:
  Test() = default;
  Test(const Test &other) = default; // It will be fully implemented;
  // Test(const Test &other) = delete; // It remove default constructro
  Test &operator=(const Test &other) = default;
  // Test &operator=(const Test &other) = deleted;
  Test(int id) : id(id) {}
  Test(int id, string name) : id(id), name(name) {}
  Test(initializer_list<string> texts) {
    for (const auto &t : texts)
      cout << t << endl;
  }

  void print(initializer_list<string> texts) {
    for (const auto &t : texts)
      cout << t << endl;
  }
  void print() {
    cout << "[id: " << id << ", name: \"" << name << "\"]" << endl;
  }
};

int main() {
  Test t0;
  t0.print();

  Test t(7, "John");
  t.print();

  Test t1(13);
  t1.print();

  Test t2(t);
  t2.print();

  Test t3 = t2;
  t3.print();
}
