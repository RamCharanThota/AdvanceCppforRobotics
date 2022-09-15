#include <iostream>

template <typename T> class Compare {
  T first, second;

public:
  Compare(T a, T b) {
    first = a;
    second = b;
  }
  T Bigger();
};

template <typename T>

T Compare<T>::Bigger() {

  return first > second ? first : second;
}

int main() {

  Compare<std::string> c("A","B");
  std::string val = c.Bigger();
  std::cout << "bigger value is :" << val << std::endl;
}
