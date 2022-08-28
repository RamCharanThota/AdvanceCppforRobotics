#include <functional>
#include <iostream>
#include <set>
#include <string>

using namespace std;

template <class myType> void print_func(myType set_obj) {
  for (auto &e : set_obj) {
    std::cout << e << endl;
  }
}

class Person {
public:
  int age_;
  string name_;
  bool operator<(const Person &rhs) const { return age_ < rhs.age_; }
  // Person(int age, string name) : age_(age), name_(name) {}
};

void print_user_fun(set<Person> set_p_obj) {
  for (auto &e : set_p_obj) {
    std::cout << "age: " << e.age_ << " name:" << e.name_ << endl;
  }
}

int main() {
  // print ascending order
  set<int> set_as_ob = {1, 23, 234, 567, 9, 0, 8, -1};
  print_func(set_as_ob);

  // print descending order
  set<int, greater<int>> set_ds_ob = {1, 23, 234, 567, 9, 0, 8, -1};
  print_func(set_ds_ob);

  // print user defined set in ascending order using their name
  set<Person> set_p_obj = {
      {20, "manju"}, {40, "sowmya"}, {30, "ram"}, {26, "pavani"}};
  print_user_fun(set_p_obj);
}