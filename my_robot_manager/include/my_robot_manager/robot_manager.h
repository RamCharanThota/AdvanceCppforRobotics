#include "ros/forwards.h"
#include "ros/node_handle.h"
#include "ros/subscriber.h"
#include <nav_msgs/Odometry.h>
#include <ros/ros.h>
#include <string>

class RobotManager {
  float current_x_position;
  float current_y_position;
  std::string odometry_topic;
  void odom_callback(const nav_msgs::Odometry::ConstPtr &msg);
  ros::Subscriber odom_subscriber;
  std::string robot_name;

public:
  RobotManager(ros::NodeHandle *nh, std::string name, std::string odom_topic);
};
