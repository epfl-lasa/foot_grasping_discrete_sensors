#ifndef _ROS_SERVICE_SetAnalogOutput_h
#define _ROS_SERVICE_SetAnalogOutput_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace phidgets_msgs
{

static const char SETANALOGOUTPUT[] = "phidgets_msgs/SetAnalogOutput";

  class SetAnalogOutputRequest : public ros::Msg
  {
    public:
      typedef uint16_t _index_type;
      _index_type index;
      typedef float _voltage_type;
      _voltage_type voltage;

    SetAnalogOutputRequest():
      index(0),
      voltage(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->index >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->index >> (8 * 1)) & 0xFF;
      offset += sizeof(this->index);
      offset += serializeAvrFloat64(outbuffer + offset, this->voltage);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->index =  ((uint16_t) (*(inbuffer + offset)));
      this->index |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->index);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->voltage));
     return offset;
    }

    virtual const char * getType() override { return SETANALOGOUTPUT; };
    virtual const char * getMD5() override { return "1dc9e97abcdfdbceae7daea4cabaa378"; };

  };

  class SetAnalogOutputResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    SetAnalogOutputResponse():
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

    virtual const char * getType() override { return SETANALOGOUTPUT; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class SetAnalogOutput {
    public:
    typedef SetAnalogOutputRequest Request;
    typedef SetAnalogOutputResponse Response;
  };

}
#endif
