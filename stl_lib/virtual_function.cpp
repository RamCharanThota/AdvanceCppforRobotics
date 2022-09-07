#include <iostream>
using namespace std;

class Father {
public:
  virtual void run() { cout << "Father is running\n"; }
};

class Son : public Father {
public:
  void run() { cout << "Son is running\n"; }
};

int main() {
  Father *fptr;
  Son s;
  fptr = &s;

  fptr->run();

  return 0;
}