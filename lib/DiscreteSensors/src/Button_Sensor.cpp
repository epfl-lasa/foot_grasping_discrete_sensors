#include <Arduino.h>
#include "Button_Sensor.h"


Button_Sensor::Button_Sensor(gripperLaterality id, ros::NodeHandle* nh): _myID(id), _nh(nh){
    switch (_myID)
    {
    case RIGHT_GRIPPER:
        _buttonPublisher = new ros::Publisher("/right/foot_grasping/buttonState",&_buttonStateROS);
        break;
    case LEFT_GRIPPER:
        _buttonPublisher = new ros::Publisher("/left/foot_grasping/buttonState",&_buttonStateROS);
        break;
    }
    
    _lastButtonState = 0; _currentButtonState = 0;
}

void Button_Sensor::setup(){
    pinMode(SWITCH_PIN[_myID],INPUT_PULLUP);
    _currentButtonState = digitalRead(SWITCH_PIN[_myID]);
    _gripperActionButtonROS = GRIPROS_OPENING;
    _nh->advertise(*_buttonPublisher);
}

void Button_Sensor::step(){
    _lastButtonState    = _currentButtonState;      // save the last state
    _currentButtonState = digitalRead(SWITCH_PIN[_myID]); // read new state

     if(_currentButtonState - _lastButtonState == 1) {
      switch (_gripperActionButtonROS)
      {
      case GRIPROS_OPENING:
        _gripperActionButtonROS = GRIPROS_CLOSING;
        break;
      case GRIPROS_CLOSING:
        _gripperActionButtonROS = GRIPROS_OPENING;
        break;
      }
    }

    _buttonStateROS.data = (int8_t) _gripperActionButtonROS;
    _buttonPublisher->publish(&_buttonStateROS);
}

Button_Sensor::~Button_Sensor(){
  delete(_buttonPublisher);
}