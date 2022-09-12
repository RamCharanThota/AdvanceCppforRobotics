#include <iostream>

class Myclass {
  int value;

public:
  int myconstfunc() const { return value; }
  void mynonconstfunc(int val) { value = val; }
};

int main() {
  Myclass mc;
  mc.mynonconstfunc(2);
  std::cout << "the value of value is: " << mc.myconstfunc();
}