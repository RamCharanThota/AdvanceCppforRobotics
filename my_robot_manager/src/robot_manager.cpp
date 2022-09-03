#include "my_robot_manager/robot_manager.h"
#include "ros/ros.h"

RobotManager::RobotManager(ros::NodeHandle *nh, std::string name,
                           std::string odom_topic)
    : robot_name(name), odometry_topic(odom_topic) {
  odom_subscriber =
      nh->subscribe(odometry_topic, 1000, &RobotManager::odom_callback, this);
}

void RobotManager::odom_callback(const nav_msgs::Odometry::ConstPtr &msg) {
  current_x_position = msg->pose.pose.position.x;
  current_y_position = msg->pose.pose.position.y;
  ROS_INFO("%s x_pos is %f and y pos is %f ", robot_name.c_str(),
           current_x_position, current_y_position);
}