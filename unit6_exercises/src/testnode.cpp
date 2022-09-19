#include "ros/init.h"
#include "ros/ros.h"
#include "ros/subscriber.h"
#include "sensor_msgs/JointState.h"
#include <iostream>
#include <vector>

void classback(const sensor_msgs::JointStateConstPtr msg) {

  int index = std::find(msg->name.begin(), msg->name.end(),
                        std::string("wheel_right_joint")) -
              msg->name.begin();
  float right_position = msg->position[index];

  ROS_INFO("the right wheel position is %f", right_position);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "test_node");

  ros::NodeHandle nh;

  ros::Subscriber joint_sub_ = nh.subscribe("joint_states", 1, &classback);
  ros::spin();
}