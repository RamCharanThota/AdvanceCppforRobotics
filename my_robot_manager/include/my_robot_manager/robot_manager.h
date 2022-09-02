#include "ros/forwards.h"
#include "ros/node_handle.h"
#include "ros/subscriber.h"
#include <nav_msgs/Odometry.h>
#include <ros/ros.h>
#include <string>

class RobotManager {
  float current_x_position;
  float current_y_position;
  std::string odometry_topic = "/robot1/odom";
  void odom_callback(const nav_msgs::Odometry::ConstPtr &msg);

public:
  RobotManager(const ros::NodeHandlePtr &nh);
};
