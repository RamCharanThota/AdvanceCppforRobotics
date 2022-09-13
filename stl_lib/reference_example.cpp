#include <iostream>

using namespace std;

int main() {

  int value1 = 10;
  int value2 = 50;
  int &ref = value1;
  value1 = 60;
  ref = value2;

  cout << "the ref value is " << ref << "" << value1;
}