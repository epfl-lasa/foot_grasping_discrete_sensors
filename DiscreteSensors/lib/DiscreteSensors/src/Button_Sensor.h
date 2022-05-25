#ifndef BUTTON_SENSOR_H
#define BUTTON_SENSOR_H

#include <Arduino.h>
#include "ros.h"
#include "ros/publisher.h"
#include "std_msgs/Int8.h"
#include "std_msgs/Int16.h"
#include "Definitions.h"

class Button_Sensor{
    public:
        Button_Sensor(gripperLaterality id);
        ~Button_Sensor();
        void setup(), step();
        ros::Publisher* _buttonPublisher;  
    private: 
        gripperLaterality _myID;
        int _lastButtonState, _currentButtonState;
        gripperROS_State _gripperActionButtonROS;
        //ROS message button
        std_msgs::Int8 _buttonStateROS;        
};

#endif //BUTTON_SENSOR_H

