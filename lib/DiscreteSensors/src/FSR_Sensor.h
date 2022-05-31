#ifndef FSR_SENSOR_H
#define FSR_SENSOR_H

#include <Arduino.h>
#include "ros.h"
#include "ros/publisher.h"
#include "std_msgs/Int8.h"
#include "std_msgs/Int16.h"
#include "Definitions.h"
#include "LP_Filter.h"

#define NB_SAMPLES_VARIABLE_SET_POINT 100

class FSR_Sensor{
    public:
        FSR_Sensor(gripperLaterality id, ros::NodeHandle* nh);
        ~FSR_Sensor();
        void setup(), step();
        void getParamsROS();
    private: 
        ros::Publisher *_fsrStatePublisher, *_fsrContinuousPublisher; 
        ros::NodeHandle* _nh; 
        gripperLaterality _myID;
        int _deltaThreshold, _variableThreshold;
        int _lastFSRState, _currentFSRState;
        int _fsrValue, _fsrSwitch, _fsrAllowSwitch, _fsrVariableOffset, _fsrCountSamples, _fsrAverageNbSamples;
        LP_Filter _fsrFilter;
        float _fsrFilterAlpha;
        gripperROS_State _gripperActionFSRROS;
        //ROS message fsr
        std_msgs::Int16 _fsrContinuousROS;
        std_msgs::Int8 _fsrStateROS;
        void publishData();
        
};

#endif //FSR_SENSOR_H


