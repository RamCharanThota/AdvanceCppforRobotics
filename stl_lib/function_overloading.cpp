#include <iostream>

using namespace std;

class Base {
public:
  virtual void Display() {
    cout << "\nThis is Display() method"
            " of base class Mobile"
         << endl;
  }
  virtual void Show() {
    cout << "\nThis is Show() method "
            "of BaseClass Mobile"
         << endl;
  }
};

class Child : public Base {
public:
  // Overriding method - new working of
  // base class's display method
  void Display() {
    cout << "\nThis is Display() method"
            " of derived Class VideoPlayer"
         << endl;
  }
};

// Driver code
int main() {
  Base b;
  b.Display();
  Child c;
  c.Display();

  Base &b1 = c;
  c.Display();
}