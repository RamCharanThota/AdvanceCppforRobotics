#include "robot_commander/robot_commander.h"
#include <exception>
#include <iostream>
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "exercise_8_1");

  RobotCommander my_robot;

  int n = 0;

  while (n < 5) {

    float turn_velocity;
    std::cout << "Enter turn velocity: ";

    // INSERT YOUR CODE BELOW THIS LINE
    std::cin >> turn_velocity;
    if (std::cin.fail()) {
      ROS_WARN("Please entry of a decimal number.");
      std::cin.clear();
      std::cin.ignore(256, '\n');
    } else {
      try {
        if (turn_velocity >= -1 && turn_velocity <= 0) {
          my_robot.turn(turn_velocity, 5);
        } else {
          throw 1;
        }

      } catch (...) {
        ROS_WARN("Enter turn velocity between -1.0 and 0.0");
      }
    }

    // INSERT YOUR CODE ABOVE THIS LINE
    n++;
  }

  return 0;
}