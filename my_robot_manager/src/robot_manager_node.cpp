#include "my_robot_manager/robot_manager.h"
#include "ros/node_handle.h"
#include "ros/ros.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_manager");
  ros::NodeHandle nh;
  RobotManager r_obj1 = RobotManager(&nh, "turtulebot1", "/robot1/odom");
  RobotManager r_obj2 = RobotManager(&nh, "turtulebot2", "/robot2/odom");

  ros::Duration(5).sleep();
  r_obj1.printxyval();
  r_obj2.printxyval();
  ros::spin();
}
