#include <iostream>

using namespace std;

class Icetray {
public:
  int crystals;
  // overloading operator =
  Icetray &operator=(Icetray &&source) {
    this->crystals = source.crystals;
    source.crystals = 0;
    return *this;
  }
};
int main() {

  // move the values from orange_tray to another existing object lemon_tray
  Icetray orange_tray;
  orange_tray.crystals = 5;
  Icetray lemon_tray;

  lemon_tray =
      move(orange_tray); // calling Icetray& operator= (Icetray&& source)

  cout << "Number of crystals left in tray filled with orange juice : "
       << orange_tray.crystals << std::endl;
  cout << "Number of crystals in tray filled with lemon juice : "
       << lemon_tray.crystals << std::endl;

  return 0;
}
