#include <iostream>
#include <typeinfo>

using namespace std;

class Base {
protected:
  void prFunc() {
    this->puFunc();
    cout << "prtinting prFunc Base" << endl;
  }

public:
  Base() { prFunc(); }
  virtual void puFunc() { cout << "prtinting puFunc Base" << endl; }
};

class Child : public Base {
public:
  void puFunc() { cout << "prtinting puFunc child" << endl; }
};

int main() {
  Child c;
  Base *b = &c;
}