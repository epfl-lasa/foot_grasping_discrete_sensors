#include <Arduino.h>
#include "ros.h"
#include "ros/publisher.h"
#include "std_msgs/Int8.h"
#include "std_msgs/Int16.h"

//Definitions

enum gripperROS_State{GRIPROS_STANDBY, GRIPROS_OPENING, GRIPROS_CLOSING, GRIPROS_SWITCH};
  //Pin Definitions
#define SWITCH D7
#define FSR_PIN A3


// Variable Creation
int lastButtonState, currentButtonState;
int lastFSRState, currentFSRState;
int fsrThreshold;
int fsrValue;

gripperROS_State gripperActionButtonROS, gripperActionFSRROS;

  //ROS message button
  ros::NodeHandle nh;
  std_msgs::Int8 buttonStateROS;
  ros::Publisher buttonPublisher("/foot_grasping/buttonState",&buttonStateROS);  
//ROS message fsr
  std_msgs::Int16 fsrContinuousROS;
  ros::Publisher fsrContinuousPublisher("/foot_grasping/FSRContinuous",&fsrContinuousROS);  
  
  std_msgs::Int8 fsrStateROS;
  ros::Publisher fsrStatePublisher("/foot_grasping/FSRState",&fsrStateROS);  
  
void setup() {
  //HW and variables Setup and Initialization
  pinMode(SWITCH,INPUT_PULLUP);
  fsrThreshold=900;
  fsrValue=0;
  currentButtonState = digitalRead(SWITCH);
  lastButtonState = 0; currentButtonState = 0;
  lastFSRState = 0; currentFSRState = 0;
  gripperActionButtonROS = GRIPROS_OPENING;
  gripperActionFSRROS = GRIPROS_OPENING;
  analogReadResolution(12);
  //Ros setup
  nh.getHardware()->setBaud(460800);
  nh.initNode();
  nh.advertise(buttonPublisher);
  nh.advertise(fsrContinuousPublisher);
  nh.advertise(fsrStatePublisher);
  while(!nh.connected())
  { 
    nh.spinOnce();
  }
  nh.loginfo("The interface to the button and fsr is connected");
  delay(1);
  if (!nh.getParam("/foot_grasping/fsr_threshold", &fsrThreshold,1)) {
    nh.logerror("no fsr_threshold param");
  }else{
    char msg [100];
    sprintf(msg,"fsr threshold %d param loaded", fsrThreshold);
    nh.loginfo(msg);
  }

}

void loop() {
  fsrValue = analogRead(FSR_PIN);
  lastButtonState    = currentButtonState;      // save the last state
  currentButtonState = digitalRead(SWITCH); // read new state
  
  if(currentButtonState - lastButtonState == 1) {
    switch (gripperActionButtonROS)
    {
    case GRIPROS_OPENING:
      gripperActionButtonROS = GRIPROS_CLOSING;
      break;
    case GRIPROS_CLOSING:
      gripperActionButtonROS = GRIPROS_OPENING;
      break;
    }
  }

  lastFSRState  = currentFSRState; 
  currentFSRState = fsrValue<fsrThreshold ? 1 : 0;

  if(currentFSRState - lastFSRState == 1) {
    switch (gripperActionFSRROS)
    {
    case GRIPROS_OPENING:
      gripperActionFSRROS = GRIPROS_CLOSING;
      break;
    case GRIPROS_CLOSING:
      gripperActionFSRROS = GRIPROS_OPENING;
      break;
    }
  }

  buttonStateROS.data = (int8_t) gripperActionButtonROS;
  buttonPublisher.publish(&buttonStateROS);
  
  fsrContinuousROS.data = (int16_t) fsrValue;
  fsrContinuousPublisher.publish(&fsrContinuousROS);
  
  fsrStateROS.data = (int8_t) gripperActionFSRROS;
  fsrStatePublisher.publish(&fsrStateROS);

  nh.spinOnce();
  delay(5);
}