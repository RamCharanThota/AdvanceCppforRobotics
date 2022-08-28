#include <functional>
#include <iostream>
#include <set>

using namespace std;
template <class myType>

void print_func(myType set_obj) {
  for (auto &e : set_obj) {
    std::cout << e << endl;
  }
}
int main() {
  // print ascending order
  set<int> set_as_ob = {1, 23, 234, 567, 9, 0, 8, -1};
  print_func(set_as_ob);

  // print descending order
  set<int, greater<int>> set_ds_ob = {1, 23, 234, 567, 9, 0, 8, -1};
  print_func(set_ds_ob);
}