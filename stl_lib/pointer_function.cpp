#include <iostream>

using namespace std;

int myfunction(int i, double d) {

  cout << "using the myfunction" << endl;

  return 1;
}

double myoperation(int x, double y, int (*functocall)(int, double)) {
  int z = (*functocall)(x, y);

  return z;
}

int main() { int (*myfunction_pointer)(int, double) = myfunction; 

int returnval = myoperation(2, 3,myfunction_pointer );
}