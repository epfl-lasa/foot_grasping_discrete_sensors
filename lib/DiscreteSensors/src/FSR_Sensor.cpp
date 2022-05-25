#include <Arduino.h>
#include "FSR_Sensor.h"


FSR_Sensor::FSR_Sensor(gripperLaterality id): _myID(id){
    switch (_myID)
    {
    case RIGHT_GRIPPER:
        _fsrContinuousPublisher = new ros::Publisher("/right/foot_grasping/FSRContinuous",&_fsrContinuousROS);
        _fsrStatePublisher =  new ros::Publisher("/right/foot_grasping/FSRState",&_fsrStateROS);
        break;
    case LEFT_GRIPPER:
        _fsrContinuousPublisher = new ros::Publisher("/left/foot_grasping/FSRContinuous",&_fsrContinuousROS);
        _fsrStatePublisher =  new ros::Publisher("/left/foot_grasping/FSRState",&_fsrStateROS);
        break;
    }
    
    _lastFSRState = 0; _currentFSRState = 0; _fsrValue=0;
}

void FSR_Sensor::setup(){
    _fsrFilter.setAlpha(0.87);
    _fsrThreshold_low=2500;   
    _fsrThreshold_up= 3700;
    _gripperActionFSRROS = GRIPROS_OPENING;
    _fsrAllowSwitch=1; _fsrSwitch=0;
}

void FSR_Sensor::step(){
    _fsrValue = _fsrFilter.update((float) analogRead(FSR_PIN[_myID]));
    _lastFSRState  = _currentFSRState; 

    if (_fsrAllowSwitch==0)
    {
      if (_fsrValue > _fsrThreshold_up)
      {
        _fsrAllowSwitch=1;
        _fsrSwitch = 0;
      }else{
        _fsrAllowSwitch = 0;
      }
    }
    else
    {
      if (_fsrSwitch==0)
      {
        if (_fsrValue < _fsrThreshold_low)
        {
          _fsrSwitch = 1;
          _fsrAllowSwitch=0;
        }else{
          _fsrSwitch=0;
        }
 
      }
    }
      
    _currentFSRState = _fsrSwitch;

    if(_currentFSRState - _lastFSRState == 1) {
      switch (_gripperActionFSRROS)
      {
      case GRIPROS_OPENING:
        _gripperActionFSRROS = GRIPROS_CLOSING;
        break;
      case GRIPROS_CLOSING:
        _gripperActionFSRROS = GRIPROS_OPENING;
        break;
      }
    }

    _fsrContinuousROS.data = (int16_t) _fsrValue;
    _fsrStateROS.data = (int8_t) _gripperActionFSRROS;


    _fsrContinuousPublisher->publish(&_fsrContinuousROS);
    _fsrStatePublisher->publish(&_fsrStateROS);
      
}

FSR_Sensor::~FSR_Sensor()
{
    delete(_fsrStatePublisher);
    delete(_fsrContinuousPublisher);
};
