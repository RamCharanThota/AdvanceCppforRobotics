#include <iostream>

using namespace std;

int main() {
  // In the pointers to constant, the data pointed by the pointer is constant
  // and cannot be changed. Although, the pointer itself can change and points
  // somewhere else (as the pointer itself is a variable).
  int const *p1;
  int value = 20;
  int value2 = 20;
  p1 = &value;
  p1 = &value2;
  //*p1=30; you can't do this

  // In constant pointers, the pointer points to a fixed memory location,
  // and the value at that location can be changed because it is a variable,
  // but the pointer will always point to the same location because it is made
  // constant here.
  int *const p2 = &value;
  *p2 = 40;
  // p2 = &value2;  you cannot do this

  //   In the constant pointers to constants,
  // the data pointed to by the pointer is constant and cannot be changed. The
  // pointer itself is constant and cannot change and point somewhere else.
  // Below is the image to illustrate the same:
  int const *const p3 = &value;
  // *p3=50;  you cannot do this
  // p3=&value2; you cannot do this
}