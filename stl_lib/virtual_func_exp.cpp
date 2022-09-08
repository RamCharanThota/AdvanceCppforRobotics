#include <iostream>
#include <typeinfo>

using namespace std;

class Base {
protected:
  void prFunc() { cout << "prtinting prFunc Base" << endl; }

public:
  virtual void puFunc() { cout << "prtinting puFunc Base" << endl; }
};

class Child : public Base {
public:
  void puFunc() {
    prFunc();
    cout << "prtinting puFunc child" << endl;
  }
  void puFunctwo() { cout << "prtinting puFunctwo child" << endl; }
};

int main() {
  Child c;
  Base *b = &c;
  b->puFunc();
}