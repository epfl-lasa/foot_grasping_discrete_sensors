#ifndef _ROS_SERVICE_SetDigitalOutput_h
#define _ROS_SERVICE_SetDigitalOutput_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace phidgets_msgs
{

static const char SETDIGITALOUTPUT[] = "phidgets_msgs/SetDigitalOutput";

  class SetDigitalOutputRequest : public ros::Msg
  {
    public:
      typedef uint16_t _index_type;
      _index_type index;
      typedef bool _state_type;
      _state_type state;

    SetDigitalOutputRequest():
      index(0),
      state(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->index >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->index >> (8 * 1)) & 0xFF;
      offset += sizeof(this->index);
      union {
        bool real;
        uint8_t base;
      } u_state;
      u_state.real = this->state;
      *(outbuffer + offset + 0) = (u_state.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->index =  ((uint16_t) (*(inbuffer + offset)));
      this->index |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->index);
      union {
        bool real;
        uint8_t base;
      } u_state;
      u_state.base = 0;
      u_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->state = u_state.real;
      offset += sizeof(this->state);
     return offset;
    }

    virtual const char * getType() override { return SETDIGITALOUTPUT; };
    virtual const char * getMD5() override { return "87b461c46634beb857c7651b37066682"; };

  };

  class SetDigitalOutputResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    SetDigitalOutputResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return SETDIGITALOUTPUT; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class SetDigitalOutput {
    public:
    typedef SetDigitalOutputRequest Request;
    typedef SetDigitalOutputResponse Response;
  };

}
#endif
