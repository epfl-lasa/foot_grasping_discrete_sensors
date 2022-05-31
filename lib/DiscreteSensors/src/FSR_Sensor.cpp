#include <Arduino.h>
#include "FSR_Sensor.h"
#include "utils_functions.h"

const char *gripperNames[] = {"right","left"};

FSR_Sensor::FSR_Sensor(gripperLaterality id, ros::NodeHandle* nh): _myID(id), _nh(nh){
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
    _fsrFilterAlpha=0.87;   
    _deltaThreshold= 1000;
    _variableThreshold = _deltaThreshold;
    _fsrValue = (int) _fsrFilter.update((float) analogRead(FSR_PIN[_myID]));
    _fsrVariableOffset = _fsrValue;
    _fsrCountSamples=0;
    _fsrAverageNbSamples = NB_SAMPLES_VARIABLE_SET_POINT;
    _gripperActionFSRROS = GRIPROS_OPENING;
    _fsrSwitch=0; _fsrAllowSwitch=1;
    _nh->advertise(*_fsrContinuousPublisher);
    _nh->advertise(*_fsrStatePublisher);
}

void FSR_Sensor::step(){
    _fsrValue = _fsrFilter.update((float) analogRead(FSR_PIN[_myID]));
    _fsrCountSamples++;
    _lastFSRState  = _currentFSRState; 
    _variableThreshold  = (int) ( map((float) _fsrValue, 0.0f , 4095.0f , 0.1f* (float)_deltaThreshold, (float)_deltaThreshold));

    if (_fsrAllowSwitch==0)
    {
      if ((_fsrVariableOffset - _fsrValue) < _variableThreshold)
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
        if ((_fsrVariableOffset - _fsrValue) > _variableThreshold)
        {
          _fsrSwitch = 1;
          _fsrAllowSwitch=0;
        }else{
          _fsrSwitch=0;
        }
 
      }
    }

    if (_fsrValue < _variableThreshold)
    {
      _nh->logwarn("The value of threshold is bigger than the FSR value");
    }
    if (_fsrCountSamples>=_fsrAverageNbSamples)
    {
      _fsrVariableOffset = _fsrValue;
      _fsrCountSamples=0;
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


void FSR_Sensor::getParamsROS()
{
  static char msg [100];

  sprintf(msg,"/%s/foot_grasping/fsr_deltaThreshold", gripperNames[_myID]);
  if (!_nh->getParam(msg, &_deltaThreshold,1)) {
    sprintf(msg,"no %s fsr_deltaThreshold param found", gripperNames[_myID]);
    _nh->logerror(msg);
  }else{
    sprintf(msg,"%s fsr_deltaThreshold %d param loaded", gripperNames[_myID], _deltaThreshold);
    _nh->loginfo(msg);
  }

  sprintf(msg,"/%s/foot_grasping/fsr_nbSamplesOffset", gripperNames[_myID]);
  if (!_nh->getParam(msg, &_fsrAverageNbSamples,1)) {
    sprintf(msg,"no %s fsr_nbSamplesOffset param found", gripperNames[_myID]);
    _nh->logerror(msg);
  }else{
    sprintf(msg,"%s fsr_nbSamplesOffset %d param loaded", gripperNames[_myID], _fsrAverageNbSamples);
    _nh->loginfo(msg);
  }

  sprintf(msg,"/%s/foot_grasping/fsr_filterAlpha", gripperNames[_myID]);
  if (!_nh->getParam(msg, &_fsrFilterAlpha,1)) {
    sprintf(msg,"no %s fsr_filterAlpha param found", gripperNames[_myID]);
    _nh->logerror(msg);
  }else{
    sprintf(msg,"%s fsr_filterAlpha %f param loaded", gripperNames[_myID], _fsrFilterAlpha);
    _nh->loginfo(msg);
  }

  _fsrFilter.setAlpha(_fsrFilterAlpha);
}