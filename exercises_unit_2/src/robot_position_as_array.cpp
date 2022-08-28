#include "nav_msgs/Odometry.h"
#include "robot_commander/robot_commander.h"
#include "ros/init.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "position_array");
  RobotCommander robot_cmd;

  float my_array[3];
  my_array[0] = robot_cmd.get_x_position();
  my_array[1] = robot_cmd.get_y_position();
  my_array[2] = robot_cmd.get_z_position();

  for (int i = 0; i < 3; i++)
    std::cout << my_array[i] << " ";
  std::cout << std::endl;
  return 0;
}