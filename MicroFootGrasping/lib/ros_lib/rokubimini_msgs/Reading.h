#ifndef _ROS_rokubimini_msgs_Reading_h
#define _ROS_rokubimini_msgs_Reading_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/Imu.h"
#include "geometry_msgs/WrenchStamped.h"
#include "sensor_msgs/Temperature.h"

namespace rokubimini_msgs
{

  class Reading : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _statusword_type;
      _statusword_type statusword;
      typedef sensor_msgs::Imu _imu_type;
      _imu_type imu;
      typedef geometry_msgs::WrenchStamped _wrench_type;
      _wrench_type wrench;
      typedef sensor_msgs::Imu _externalImu_type;
      _externalImu_type externalImu;
      typedef bool _isForceTorqueSaturated_type;
      _isForceTorqueSaturated_type isForceTorqueSaturated;
      typedef sensor_msgs::Temperature _temperature_type;
      _temperature_type temperature;

    Reading():
      header(),
      statusword(0),
      imu(),
      wrench(),
      externalImu(),
      isForceTorqueSaturated(0),
      temperature()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->statusword >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->statusword >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->statusword >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->statusword >> (8 * 3)) & 0xFF;
      offset += sizeof(this->statusword);
      offset += this->imu.serialize(outbuffer + offset);
      offset += this->wrench.serialize(outbuffer + offset);
      offset += this->externalImu.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_isForceTorqueSaturated;
      u_isForceTorqueSaturated.real = this->isForceTorqueSaturated;
      *(outbuffer + offset + 0) = (u_isForceTorqueSaturated.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isForceTorqueSaturated);
      offset += this->temperature.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->statusword =  ((uint32_t) (*(inbuffer + offset)));
      this->statusword |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->statusword |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->statusword |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->statusword);
      offset += this->imu.deserialize(inbuffer + offset);
      offset += this->wrench.deserialize(inbuffer + offset);
      offset += this->externalImu.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_isForceTorqueSaturated;
      u_isForceTorqueSaturated.base = 0;
      u_isForceTorqueSaturated.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->isForceTorqueSaturated = u_isForceTorqueSaturated.real;
      offset += sizeof(this->isForceTorqueSaturated);
      offset += this->temperature.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "rokubimini_msgs/Reading"; };
    virtual const char * getMD5() override { return "f632d7286fac45ac13e8083c2bf7f237"; };

  };

}
#endif
