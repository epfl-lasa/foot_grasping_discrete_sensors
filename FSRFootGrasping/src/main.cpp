#include <Arduino.h>
#include "ros.h"
#include "ros/publisher.h"
#include "std_msgs/Int8.h"

//Pin definition
#define FORCE_SENSOR_PIN A3
//Definitions
enum gripperActionStateList
{
  OPEN_GRIPPER,
  CLOSE_GRIPPER
};

gripperActionStateList gripperActionROS;
  //ROS message
  ros::NodeHandle nh; //Ros node
  std_msgs::Int8 FsrStateROS; //Ros msg
  ros::Publisher FsrPublisher("/foot_grasping/FsrState",&FsrStateROS);  //Publie ROS msg in the ROS topic
  int lower_th;
  
void setup() {
   gripperActionROS = OPEN_GRIPPER;
   Serial.begin(9600);// put your setup code here, to run once:
  //Ros setup
  nh.getHardware()->setBaud(460800);
  nh.initNode();
  nh.advertise(FsrPublisher);
  while(!nh.connected())
  { 
    nh.spinOnce();
  }
  nh.loginfo("The interface to the button and fsr is connected");
  nh.getParam("/ros/fsr_lower_th", lower_th);

  delay(1);
}

void loop() {
 int analogReading = analogRead(FORCE_SENSOR_PIN);

  Serial.print("Force sensor reading = ");
  Serial.print(analogReading); // print the raw analog reading

  if (analogReading < 10)       // from 0 to 9
    Serial.println(" -> no pressure"); //ungrasp
    //grasp
  else if (analogReading < 200) // from 10 to 199
    Serial.println(" -> light touch");
  else if (analogReading < 500) // from 200 to 499
    Serial.println(" -> light squeeze");
  else if (analogReading < 800) // from 500 to 799
    Serial.println(" -> medium squeeze");
  else // from 800 to 1023
    Serial.println(" -> big squeeze");

  delay(1000);
  // put your main code here, to run repeatedly:
}