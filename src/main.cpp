#include <Arduino.h>
#include "ros.h"
#include "ros/publisher.h"
#include "std_msgs/Int8.h"
#include "std_msgs/Int16.h"
#include "LP_Filter.h"
#include "Button_Sensor.h"
#include "FSR_Sensor.h"
#include "utils_functions.h"

//ROS Variables
ros::NodeHandle nh;

// Global Variable Creation
Button_Sensor buttonSensors[NB_GRIPPERS] {{RIGHT_GRIPPER, &nh}, {LEFT_GRIPPER, &nh}};
FSR_Sensor fsrSensors[NB_GRIPPERS]{{RIGHT_GRIPPER, &nh}, {LEFT_GRIPPER, &nh}};
bool disconnectedFromRos;



void setup() {
  //HW and variables Setup and Initialization
  disconnectedFromRos=true;
  analogReadResolution(12); 
  
    //Ros setup
  nh.getHardware()->setBaud(460800);
  nh.initNode();

  for (size_t i = 0; i < NB_GRIPPERS; i++)
  {
    buttonSensors[i].setup();
    fsrSensors[i].setup();
  }
  
  while(!nh.connected())
  { 
    nh.spinOnce();
  }
  nh.loginfo("The interface to the discrete sensors of the platforms is connected");
  
  delay(1);

}

void loop() {
  if (nh.connected())
  {
    for (size_t i = 0; i < NB_GRIPPERS; i++)
    {
      if (disconnectedFromRos)
      {
        fsrSensors[i].getParamsROS();
        if (i==NB_GRIPPERS-1) { disconnectedFromRos= false;}
      }
      buttonSensors[i].step();
      fsrSensors[i].step();
    }
  }else
  {
    disconnectedFromRos = true;
  }
  nh.spinOnce();
  delay(10);
}