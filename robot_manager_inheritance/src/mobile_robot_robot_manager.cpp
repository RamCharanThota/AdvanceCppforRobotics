#include "robot_manager_inheritance/mobile_robot_robot_manager.h"
#include "robot_manager_inheritance/base_robot_manager.h"
#include "ros/node_handle.h"

RobotManagerMobile::RobotManagerMobile(ros::NodeHandle &nh_in) {
  nh = nh_in;
  odometry_topic = "/robot1/odom";
  init_odom_subscriber();
  init_config_output_srv();
}

void RobotManagerMobile::init_odom_subscriber() {
  odom_subscriber = nh.subscribe(odometry_topic, 1000,
                                 &RobotManagerMobile::odom_callback, this);
  ROS_INFO("Odometry subscriber created");
}

void RobotManagerMobile::odom_callback(const nav_msgs::OdometryConstPtr &msg) {
  if (output_enabled) {
    current_x_position = msg->pose.pose.position.x;
    current_y_position = msg->pose.pose.position.y;
    ROS_INFO("Position (x,y): %lf , %lf", current_x_position,
             current_y_position);
  }
}

void RobotManagerMobile::dispalyRobotDetails() {
  ROS_INFO("robot name: %s , location: %s ", robot_name.c_str(),
           robot_location.c_str());

  ROS_INFO("Battery Charge level: %f , type of batter: %s ",
           battery_charge_level, type_of_battery.c_str());
}
