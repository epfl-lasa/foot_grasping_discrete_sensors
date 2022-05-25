#include <Arduino.h>
#include "ros.h"
#include "ros/publisher.h"
#include "std_msgs/Int8.h"
#include "std_msgs/Int16.h"
#include "LP_Filter.h"
#include "Button_Sensor.h"
#include "FSR_Sensor.h"
#include "aux.h"

// Variable Creation
Button_Sensor buttonSensors[NB_GRIPPERS] {RIGHT_GRIPPER, LEFT_GRIPPER};
FSR_Sensor fsrSensors[NB_GRIPPERS]{RIGHT_GRIPPER, LEFT_GRIPPER};
bool disconnectedFromRos;

//ROS variables
ros::NodeHandle nh;

void setup() {
  //HW and variables Setup and Initialization
  disconnectedFromRos=false;
  analogReadResolution(12); 
  
    //Ros setup
  nh.getHardware()->setBaud(460800);
  nh.initNode();

  for (size_t i = 0; i < NB_GRIPPERS; i++)
  {
    buttonSensors[i].setup();
    fsrSensors[i].setup();
    getParamsFSR((gripperLaterality) i); // function from aux.cpp
    //Ros setup
    nh.advertise(*buttonSensors[i]._buttonPublisher);
    nh.advertise(*fsrSensors[i]._fsrContinuousPublisher);
    nh.advertise(*fsrSensors[i]._fsrStatePublisher);
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
      
        getParamsFSR((gripperLaterality) i);
        disconnectedFromRos=false;
      }
      buttonSensors[i].step();
      fsrSensors[i].step();
    }  
    }else
    {
      disconnectedFromRos = true;
    }

    nh.spinOnce();
    delay(5);
}