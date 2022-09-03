#include "my_robot_manager/robot_manager.h"
#include "ros/node_handle.h"
#include "ros/ros.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_manager");
  ros::NodeHandle nh;
  RobotManager robot_manager_obj =
      RobotManager(&nh, "turtulebot", "/robot1/odom");
  ros::spin();
}
