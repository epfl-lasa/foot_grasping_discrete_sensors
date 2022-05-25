#ifndef _ROS_custom_msgs_TwoFeetOneToolMsg_h
#define _ROS_custom_msgs_TwoFeetOneToolMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/JointState.h"

namespace custom_msgs
{

  class TwoFeetOneToolMsg : public ros::Msg
  {
    public:
      typedef uint8_t _currentTool_type;
      _currentTool_type currentTool;
      typedef uint8_t _currentControlMode_type;
      _currentControlMode_type currentControlMode;
      typedef uint8_t _mixedPlatformStateMachine_type;
      _mixedPlatformStateMachine_type mixedPlatformStateMachine;
      float mixedPlatformOffset[5];
      typedef sensor_msgs::JointState _mixedPlatformJointState_type;
      _mixedPlatformJointState_type mixedPlatformJointState;

    TwoFeetOneToolMsg():
      currentTool(0),
      currentControlMode(0),
      mixedPlatformStateMachine(0),
      mixedPlatformOffset(),
      mixedPlatformJointState()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->currentTool >> (8 * 0)) & 0xFF;
      offset += sizeof(this->currentTool);
      *(outbuffer + offset + 0) = (this->currentControlMode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->currentControlMode);
      *(outbuffer + offset + 0) = (this->mixedPlatformStateMachine >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mixedPlatformStateMachine);
      for( uint32_t i = 0; i < 5; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->mixedPlatformOffset[i]);
      }
      offset += this->mixedPlatformJointState.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->currentTool =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->currentTool);
      this->currentControlMode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->currentControlMode);
      this->mixedPlatformStateMachine =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mixedPlatformStateMachine);
      for( uint32_t i = 0; i < 5; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->mixedPlatformOffset[i]));
      }
      offset += this->mixedPlatformJointState.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "custom_msgs/TwoFeetOneToolMsg"; };
    virtual const char * getMD5() override { return "c13947aa600fe4cbf6de59e8c2aad533"; };

  };

}
#endif
