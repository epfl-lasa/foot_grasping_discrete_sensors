#ifndef _ROS_SERVICE_SetSensorConfiguration_h
#define _ROS_SERVICE_SetSensorConfiguration_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rokubimini_msgs
{

static const char SETSENSORCONFIGURATION[] = "rokubimini_msgs/SetSensorConfiguration";

  class SetSensorConfigurationRequest : public ros::Msg
  {
    public:
      typedef bool _a_type;
      _a_type a;

    SetSensorConfigurationRequest():
      a(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_a;
      u_a.real = this->a;
      *(outbuffer + offset + 0) = (u_a.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->a);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_a;
      u_a.base = 0;
      u_a.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->a = u_a.real;
      offset += sizeof(this->a);
     return offset;
    }

    virtual const char * getType() override { return SETSENSORCONFIGURATION; };
    virtual const char * getMD5() override { return "685b546c53fb0b7de5dfef48cf30fe1f"; };

  };

  class SetSensorConfigurationResponse : public ros::Msg
  {
    public:
      typedef bool _b_type;
      _b_type b;

    SetSensorConfigurationResponse():
      b(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_b;
      u_b.real = this->b;
      *(outbuffer + offset + 0) = (u_b.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->b);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_b;
      u_b.base = 0;
      u_b.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->b = u_b.real;
      offset += sizeof(this->b);
     return offset;
    }

    virtual const char * getType() override { return SETSENSORCONFIGURATION; };
    virtual const char * getMD5() override { return "88c93a4e354c9b18b18fde29f72f94c2"; };

  };

  class SetSensorConfiguration {
    public:
    typedef SetSensorConfigurationRequest Request;
    typedef SetSensorConfigurationResponse Response;
  };

}
#endif
