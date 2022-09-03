#include <iostream>

using namespace std;

class IceTray {
public:
  string crab_shape = "frozen";
  IceTray(){crab_shape = "rewriting Frozen";}

  ~IceTray() { cout << "Destructor is called" << endl; }
};

int main() {
  IceTray Orange_Juice;
  cout << Orange_Juice.crab_shape << endl;
  return 0;
}