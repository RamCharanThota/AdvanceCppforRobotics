#include "nav_msgs/Odometry.h"
#include "robot_commander/robot_commander.h"
#include "ros/init.h"
#include <ros/ros.h>
#include <unistd.h>

#include <set>
#include <utility>

typedef std::pair<float, float> pairs;
std::set<pairs> xy_set;

void saveXYPosInSet(float x_in, float y_in) {
  pairs xy_pairs = std::make_pair(x_in, y_in);
  xy_set.insert(xy_pairs);
}

void printXYPos() {

  for (auto pair_xy : xy_set) {
    std::cout << "x_pos: " << pair_xy.first << " y_pos: " << pair_xy.second
              << std::endl;
  }
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "position_array");
  RobotCommander robot_cmd;

  // save intial x and y position to set
  saveXYPosInSet(robot_cmd.get_x_position(), robot_cmd.get_y_position());
  for (int i = 0; i < 3; i++) {
    // move forward for 10 sec
    robot_cmd.move_forward(10);
    saveXYPosInSet(robot_cmd.get_x_position(), robot_cmd.get_y_position());
    // turn robot 90 deg
    robot_cmd.turn(0.523599, 3);
    saveXYPosInSet(robot_cmd.get_x_position(), robot_cmd.get_y_position());
  }
  // move forward
  robot_cmd.move_forward(10);
  saveXYPosInSet(robot_cmd.get_x_position(), robot_cmd.get_y_position());

  robot_cmd.stop_moving();

  printXYPos();

  return 0;
}