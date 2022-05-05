#ifndef _ROS_phidgets_msgs_EncoderDecimatedSpeed_h
#define _ROS_phidgets_msgs_EncoderDecimatedSpeed_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace phidgets_msgs
{

  class EncoderDecimatedSpeed : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _avr_speed_type;
      _avr_speed_type avr_speed;

    EncoderDecimatedSpeed():
      header(),
      avr_speed(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->avr_speed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->avr_speed));
     return offset;
    }

    virtual const char * getType() override { return "phidgets_msgs/EncoderDecimatedSpeed"; };
    virtual const char * getMD5() override { return "20fbdbe041b6e052c8c414d50464f125"; };

  };

}
#endif
