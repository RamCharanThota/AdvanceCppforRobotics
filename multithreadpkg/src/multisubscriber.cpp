#include "ros/ros.h"
#include "ros/subscribe_options.h"
#include "std_msgs/String.h"
#include <chrono>
#include <thread>

void ChatterCallback(const std_msgs::String::ConstPtr &msg) {
  ROS_INFO(" I heard: [%s]", msg->data.c_str());
  std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::SubscribeOptions ops;
  ops.template init<std_msgs::String>("chatter", 1, ChatterCallback);
  ops.allow_concurrent_callbacks = true;
  ros::Subscriber sub1 = n.subscribe(ops);
  ros::MultiThreadedSpinner spinner(2);
  spinner.spin();
  return 0;
}