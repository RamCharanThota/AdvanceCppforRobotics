#include "robot_manager_inheritance/mobile_robot_robot_manager.h"
#include "robot_manager_inheritance/base_robot_manager.h"
#include "ros/node_handle.h"

RobotManagerMobile::RobotManagerMobile(ros::NodeHandle &nh_in) {
  nh = nh_in;
  odometry_topic = "/robot1/odom";
  init_config_output_srv();
  init_odom_subscriber();
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