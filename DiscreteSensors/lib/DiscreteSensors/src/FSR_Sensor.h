#ifndef FSR_SENSOR_H
#define FSR_SENSOR_H

#include <Arduino.h>
#include "ros.h"
#include "ros/publisher.h"
#include "std_msgs/Int8.h"
#include "std_msgs/Int16.h"
#include "Definitions.h"
#include "LP_Filter.h"

class FSR_Sensor{
    public:
        FSR_Sensor(gripperLaterality id);
        ~FSR_Sensor();
        int _fsrThreshold_low, _fsrThreshold_up;
        void setup(), step();
        ros::Publisher *_fsrStatePublisher, *_fsrContinuousPublisher;  
    private: 
        gripperLaterality _myID;
        int _lastFSRState, _currentFSRState;
        int _fsrValue, _fsrSwitch, _fsrAllowSwitch;
        LP_Filter _fsrFilter;
        gripperROS_State _gripperActionFSRROS;
        //ROS message fsr
        std_msgs::Int16 _fsrContinuousROS;
        std_msgs::Int8 _fsrStateROS;
        void publishData();
        
};

#endif //FSR_SENSOR_H


