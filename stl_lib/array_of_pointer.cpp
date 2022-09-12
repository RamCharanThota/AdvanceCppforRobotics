#include <iostream>

using namespace std;

int main() {
  float *arrayPtr[3];
  float array1[23];
  float array2[6];
  float array3[22];

  cout << " the stored value is: " << array1 << endl;
  arrayPtr[0] = array1;
  arrayPtr[1] = array2;
  arrayPtr[2] = array3;

  // example of the const
  int a = 9;
  const int *p = &a;

  cout << "p: " << p << " the pointer value is: " << *p << endl;

  int b = 10;
  p = &b;

  cout << "p: " << p << " the pointer value is: " << *p << endl;
}
