#ifndef LASER_TURTLE_H
#define LASER_TURTLE_H
#include "sensor_msgs/LaserScan.h"
#include <list>
#include <ros/ros.h>
#include <string>

using namespace std;

class TurtleClass {
private:
  // Communicate with nodes
  ros::NodeHandle n;
  // Laser data
  ros::Subscriber laser_sub;

  void laser_callback(const sensor_msgs::LaserScan::ConstPtr &laser_msg);

  /* DEFINE HERE THE POINTER TO THE LASER RANGES ARRAY */
  float *last_laser_ranges = new float[720];

public:
  TurtleClass();
  ~TurtleClass() { delete[] last_laser_ranges; }
};

#endif