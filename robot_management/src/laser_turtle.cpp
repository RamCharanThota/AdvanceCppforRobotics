#include "robot_management/laser_turtle.h"
#include "sensor_msgs/LaserScan.h"
#include "unistd.h"
#include <ros/ros.h>

#include <list>
#include <string>

using namespace std;

// TurtleClass constructor- make changes in the constructor as per definition
TurtleClass::TurtleClass() {
  n = ros::NodeHandle("~");
  laser_sub = n.subscribe("/robot1/kobuki/laser/scan", 10,
                          &TurtleClass::laser_callback, this);
  ROS_INFO("Initializing node .................................");
  usleep(2000000); // make the thread go to sleep for microseconds
}

/* CREATE THE CLASS DESTRUCTOR HERE */

void TurtleClass::laser_callback(
    const sensor_msgs::LaserScan::ConstPtr &laser_msg) {

  /* WRITE HERE YOUR CODE */
  int i = 0;
  for (auto range : laser_msg->ranges) {
    last_laser_ranges[i] = range;
    ROS_INFO("the laser %d and the value is %f", i, range);
    i++;
  }
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "rosbot_class_node");

  TurtleClass tc = TurtleClass();
  ros::spin();

  return 0;
}