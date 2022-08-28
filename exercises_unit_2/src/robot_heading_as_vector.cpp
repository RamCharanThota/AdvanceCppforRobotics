#include "nav_msgs/Odometry.h"
#include "robot_commander/robot_commander.h"
#include "ros/init.h"
#include <ros/ros.h>
#include <unistd.h>
#include <vector>

int main(int argc, char **argv) {
  ros::init(argc, argv, "position_array");
  RobotCommander robot_cmd;
  robot_cmd.move_in_circles();

  int num_of_values;
  std::cout << "enter number of values to collecte:";
  // std::cin >> num_of_values;
  std::vector<float> headings;
  for (int i = 0; i < 10; i++) {
    float read_heading = robot_cmd.get_heading();
    headings.push_back(read_heading);
    std::cout << "headings" << read_heading;
    std::cout << std::endl;
    ros::Duration(0.5).sleep(); // sleep for half a second
  }

  robot_cmd.stop_moving();

  return 0;
}