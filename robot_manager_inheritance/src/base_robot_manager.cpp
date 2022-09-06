#include "robot_manager_inheritance/base_robot_manager.h"
#include "ros/node_handle.h"

RobotManagerBase::RobotManagerBase(ros::NodeHandle &nh_in) { nh = nh_in; }

RobotManagerBase::RobotManagerBase() {}

bool RobotManagerBase::ConfigOutputCallback(
    std_srvs::SetBoolRequest &req, std_srvs::SetBoolResponse &response) {
  bool request = req.data;

  // Check if request is same as current output configuration
  if (request == output_enabled) {
    response.success = false;
    response.message = "Output configuration request is the same as the "
                       "current output configuration.";
    return true;
  }

  response.success = true;
  output_enabled = request;
  if (output_enabled == false) {
    response.message = "Console output disabled.";
    ROS_INFO("Robot Manager console output disabled.");
  } else {
    response.message = "Console output enabled.";
    ROS_INFO("Robot Manager console output enabled.");
  }
  return true;
}

void RobotManagerBase::init_config_output_srv() {
  config_output_srv = nh.advertiseService(
      "robot_manager_output", &RobotManagerBase::ConfigOutputCallback, this);
}