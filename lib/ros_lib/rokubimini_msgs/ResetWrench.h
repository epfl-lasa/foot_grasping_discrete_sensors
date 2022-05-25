#ifndef _ROS_SERVICE_ResetWrench_h
#define _ROS_SERVICE_ResetWrench_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Wrench.h"

namespace rokubimini_msgs
{

static const char RESETWRENCH[] = "rokubimini_msgs/ResetWrench";

  class ResetWrenchRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Wrench _desired_wrench_type;
      _desired_wrench_type desired_wrench;

    ResetWrenchRequest():
      desired_wrench()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->desired_wrench.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->desired_wrench.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return RESETWRENCH; };
    virtual const char * getMD5() override { return "c17e2a03e9bfbf4880fb44b7cbb9269b"; };

  };

  class ResetWrenchResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    ResetWrenchResponse():
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

    virtual const char * getType() override { return RESETWRENCH; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class ResetWrench {
    public:
    typedef ResetWrenchRequest Request;
    typedef ResetWrenchResponse Response;
  };

}
#endif
