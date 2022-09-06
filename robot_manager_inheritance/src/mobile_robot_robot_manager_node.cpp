#include "robot_manager_inheritance/base_robot_manager.h"
#include "robot_manager_inheritance/mobile_robot_robot_manager.h"
#include "ros/init.h"
#include "ros/node_handle.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "base_robot_node");
  ros::NodeHandle nh;
  RobotManagerMobile robot_manager_mobile(nh);
  ros::spin();
}