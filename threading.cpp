#include <iostream>
#include <thread>

using namespace std;

int main(int argc, char *argv[]) {
  auto greet = [](const char *name) { cout << "Hello, " << name << endl; };

  thread t1(greet, "Joe");
  thread t2(greet, "Jim");
  t1.join();
  t2.join();

  return 0;
}

