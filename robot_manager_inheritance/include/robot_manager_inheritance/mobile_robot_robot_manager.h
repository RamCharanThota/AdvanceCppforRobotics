#pragma once

#include "base_robot_manager.h"
#include "nav_msgs/Odometry.h"
#include "ros/ros.h"
#include <string>

class RobotManagerMobile : public RobotManagerBase {
  std::string odometry_topic;
  void odom_callback(const nav_msgs::OdometryConstPtr &msg);
  ros::Subscriber odom_subscriber;
  void init_odom_subscriber();
  float current_x_position = 0.0;
  float current_y_position = 0.0;
  float battery_charge_level = 0.55;
  std::string type_of_battery = "lead acid";

public:
  RobotManagerMobile(ros::NodeHandle &nh_in);
  void dispalyRobotDetails();
  void init_config_output_srv();
};