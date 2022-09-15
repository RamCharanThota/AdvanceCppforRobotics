#include <iostream>
#include <string>

template <typename T1, typename T2>

void printFunc(T1 a, T2 b) {
  std::cout << " type of T1 is" << typeid(a).name() << std::endl;
  std::cout << " type of T1 is" << typeid(b).name() << std::endl;
}

int main() {
  printFunc<int, double>(2, 3.3);
  printFunc<char, std::string>('c', "string");
}