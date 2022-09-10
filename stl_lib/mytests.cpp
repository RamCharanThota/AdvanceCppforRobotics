#include <iostream>

using namespace std;

int main() {

  int *my_array = new int[10];

  int a = 2;
  my_array[8] = a;

  cout << "the content of p " << my_array[9];

  delete[] my_array;
}