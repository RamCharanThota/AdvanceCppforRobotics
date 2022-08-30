#include <iostream>
#include <list>
using namespace std;

int main() {
  list<int> l{1, 2, 3};
  l.push_back(5);
  l.pop_front();
  for (auto val : l) {
    cout << val << "";
  }
  return 0;
}