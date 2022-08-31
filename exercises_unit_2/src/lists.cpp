#include <forward_list>
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
  list<string> laser;
  laser.push_back("range_max");
  laser.push_back("range_min");
  laser.push_back("angle_max");
  laser.push_back("angle_min");

  cout << *(next(laser.begin(), 2));
}