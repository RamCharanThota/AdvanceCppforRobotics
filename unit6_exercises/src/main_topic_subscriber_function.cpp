#include "ros/ros.h"
#include "sensor_msgs/Image.h"
#include "unit6_exercises/topic_subscriber_function.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "subscriber_function_node");

  ros::NodeHandle _n("topic_subscriber_main_ns");
  std::string topic_name = "/camera/rgb/image_raw";

  MagicSubscriber magic_subscriber_object;
  magic_subscriber_object.init<sensor_msgs::Image>(_n, topic_name);
  ros::spin();
}
