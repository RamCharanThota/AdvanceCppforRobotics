#include "my_robot_manager/robot_manager.h"
#include "ros/ros.h"

RobotManager::RobotManager(ros::NodeHandle *nh, std::string name,
                           std::string odom_topic)
    : robot_name(name), odometry_topic(odom_topic) {
  odom_subscriber =
      nh->subscribe(odometry_topic, 1000, &RobotManager::odom_callback, this);
  robot_count++;
  ROS_INFO("Robot %d created", robot_count);
}

void RobotManager::odom_callback(const nav_msgs::Odometry::ConstPtr &msg) {
  this->current_x_position = msg->pose.pose.position.x;
  this->current_y_position = msg->pose.pose.position.y;
}
float RobotManager::get_coords(int param) {
  if (param == 1) {
    return this->current_x_position;
  }
  if (param == 2) {
    return this->current_y_position;
  }
  return -1;
}

void RobotManager::printxyval() {
  ROS_INFO("%s current coordinates [X,Y]: %f , %f", this->robot_name.c_str(),
           this->get_coords(1), this->get_coords(2));
}
// static member function intialization
int RobotManager::robot_count = 0;