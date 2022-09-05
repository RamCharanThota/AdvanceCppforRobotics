#pragma once
#include "ros/node_handle.h"
#include "ros/service_server.h"
#include <ros/ros.h>
#include <std_srvs/SetBool.h>

class RobotManagerBase {
  bool output_enabled;
  ros::ServiceServer config_output_srv;
  bool ConfigOutputCallback(std_srvs::SetBoolRequest &req,
                            std_srvs::SetBoolResponse &response);
  ros::NodeHandle nh;

public:
  RobotManagerBase(ros::NodeHandle &nh_in);
  void init_config_output_srv();
};