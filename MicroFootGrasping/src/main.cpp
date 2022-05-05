#include <Arduino.h>
#include "ros.h"
#include "ros/publisher.h"
#include "std_msgs/Int8.h"

//Definitions

enum gripperActionStateList
{
  OPEN_GRIPPER,
  CLOSE_GRIPPER
};
  //Pin Definitions
#define SWITCH PA8


// Variable Creation
int lastButtonState;    //! the previous state of button
int currentButtonState; //! the current state of button
gripperActionStateList gripperActionROS;
  //ROS message
  ros::NodeHandle nh;
  std_msgs::Int8 buttonStateROS;
  ros::Publisher buttonPublisher("/foot_grasping/buttonState",&buttonStateROS);  
  
void setup() {
  //HW and variables Setup and Initialization
  pinMode(SWITCH,INPUT_PULLUP);
  currentButtonState = digitalRead(SWITCH);
  lastButtonState = 0; currentButtonState = 0;
  gripperActionROS = OPEN_GRIPPER;
  //Ros setup
  nh.getHardware()->setBaud(460800);
  nh.initNode();
  nh.advertise(buttonPublisher);
  while(!nh.connected())
  { 
    nh.spinOnce();
  }
  nh.loginfo("The interface to the button and fsr is connected");
  delay(1);
}

void loop() {
  
  lastButtonState    = currentButtonState;      // save the last state
  currentButtonState = digitalRead(SWITCH); // read new state
  if(currentButtonState - lastButtonState == 1) {
    switch (gripperActionROS)
    {
    case OPEN_GRIPPER:
      gripperActionROS = CLOSE_GRIPPER;
      break;
    case CLOSE_GRIPPER:
      gripperActionROS = OPEN_GRIPPER;
      break;
    }
  }
  buttonStateROS.data = (int8_t) gripperActionROS;
  buttonPublisher.publish(&buttonStateROS);
  nh.spinOnce();
  delay(5);
}