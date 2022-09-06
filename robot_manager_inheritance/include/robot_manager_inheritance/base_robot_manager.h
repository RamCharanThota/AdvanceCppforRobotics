#pragma once
#include "ros/node_handle.h"
#include "ros/service_server.h"
#include <ros/ros.h>
#include <std_srvs/SetBool.h>

class RobotManagerBase {

  ros::ServiceServer config_output_srv;
  bool ConfigOutputCallback(std_srvs::SetBoolRequest &req,
                            std_srvs::SetBoolResponse &response);

protected:
  ros::NodeHandle nh;
  bool output_enabled;

public:
  RobotManagerBase(ros::NodeHandle &nh_in);
  void init_config_output_srv();
  RobotManagerBase();
};