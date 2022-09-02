#include "robot_manager.h"

RobotManager::RobotManager(const ros::NodeHandlePtr &nh) {
  ros::Subscriber odom_subscriber =
      nh->subscribe(odometry_topic, 1000, &RobotManager::odom_callback, this);
}

void RobotManager::odom_callback(const nav_msgs::Odometry::ConstPtr &msg) {
  current_x_position = msg->pose.pose.position.x;
  current_y_position = msg->pose.pose.position.y;
  ROS_INFO("x_pos is %f and y pos is %f ", current_x_position,
           current_y_position);
}