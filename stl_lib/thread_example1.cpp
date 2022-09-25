#include <iostream>
#include <thread>

void myThreadFunction() {
  std::cout << "the thread function is executed" << std::endl;
}

int main() {
  std::thread t(&myThreadFunction);

  if (t.joinable()) {
    t.join();
  }

  return 0;
}