#include "robot_manager_inheritance/base_robot_manager.h"
#include "ros/init.h"
#include "ros/node_handle.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "base_robot_node");
  ros::NodeHandle nh;
  RobotManagerBase robot_manager_base(nh);
  ros::spin();
}