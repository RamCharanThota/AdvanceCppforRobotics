#include "../../test_library/include/test_library/test_library.h"
#include "nav_msgs/Odometry.h"
#include "ros/ros.h"
#include "test_vel_library.h"

void odomCallback(const nav_msgs::Odometry::ConstPtr &msg) {

  float x = msg->pose.pose.position.x;
  float y = msg->pose.pose.position.y;
  // publish velocities
  float x_vel = msg->twist.twist.linear.x;
  float y_vel = msg->twist.twist.linear.y;

  ros::Duration(1).sleep();
  display_pos(x, y);
  display_vel(x_vel, y_vel);
}

int main(int argc, char **argv) {

  ros::init(argc, argv, "odom_listener");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("odom", 1000, odomCallback);

  ros::spin();

  return 0;
}
