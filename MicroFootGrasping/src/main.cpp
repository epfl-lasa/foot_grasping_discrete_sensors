#include <Arduino.h>
#include "ros.h"
#include "ros/publisher.h"
#include "std_msgs/Int8.h"

//Definitions

enum gripperROS_State{GRIPROS_STANDBY, GRIPROS_OPENING, GRIPROS_CLOSING, GRIPROS_SWITCH};
  //Pin Definitions
#define SWITCH PA8


// Variable Creation
int lastButtonState;    //! the previous state of button
int currentButtonState; //! the current state of button

gripperROS_State gripperActionROS;

  //ROS message
  ros::NodeHandle nh;
  std_msgs::Int8 buttonStateROS;
  ros::Publisher buttonPublisher("/foot_grasping/buttonState",&buttonStateROS);  
  
void setup() {
  //HW and variables Setup and Initialization
  pinMode(SWITCH,INPUT_PULLUP);
  currentButtonState = digitalRead(SWITCH);
  lastButtonState = 0; currentButtonState = 0;
  gripperActionROS = GRIPROS_OPENING;
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
    case GRIPROS_OPENING:
      gripperActionROS = GRIPROS_CLOSING;
      break;
    case GRIPROS_CLOSING:
      gripperActionROS = GRIPROS_OPENING;
      break;
    }
  }
  buttonStateROS.data = (int8_t) gripperActionROS;
  buttonPublisher.publish(&buttonStateROS);
  nh.spinOnce();
  delay(5);
}