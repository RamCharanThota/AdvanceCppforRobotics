#include <iostream>
using namespace std;

// Create a Class
class IceTray {
  // Access specifier
  // Data members(variables inside a class)
  string fish_shape;
  string star_shape;

  // Member Functions()
public:
  void frozen_status() {
    cout << "Crystal which is in fish shape is " << fish_shape
         << " and the one in star shape is " << star_shape << endl;
  }

  void SetFishShape(const string &status) { this->fish_shape = status; }
  void SetStarShape(const string &status) { this->star_shape = status; }

  string GetFishShape() { return this->fish_shape; }

  string GetStarShape() { return this->star_shape; }
};

int main() {

  // Declare an object of class IceTray
  IceTray Orange_juice;

  // Accessing data member
  Orange_juice.SetFishShape("Frozen");
  Orange_juice.SetStarShape("Not frozen");

  // Accessing Member Function
  Orange_juice.frozen_status();
  return 0;
}