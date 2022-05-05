#ifndef _ROS_custom_msgs_gripper_GripperInputMsg_h
#define _ROS_custom_msgs_gripper_GripperInputMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace custom_msgs_gripper
{

  class GripperInputMsg : public ros::Msg
  {
    public:
      typedef float _ros_desAngle_type;
      _ros_desAngle_type ros_desAngle;
      typedef float _ros_desTorque_type;
      _ros_desTorque_type ros_desTorque;

    GripperInputMsg():
      ros_desAngle(0),
      ros_desTorque(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_ros_desAngle;
      u_ros_desAngle.real = this->ros_desAngle;
      *(outbuffer + offset + 0) = (u_ros_desAngle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ros_desAngle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ros_desAngle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ros_desAngle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ros_desAngle);
      union {
        float real;
        uint32_t base;
      } u_ros_desTorque;
      u_ros_desTorque.real = this->ros_desTorque;
      *(outbuffer + offset + 0) = (u_ros_desTorque.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ros_desTorque.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ros_desTorque.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ros_desTorque.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ros_desTorque);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_ros_desAngle;
      u_ros_desAngle.base = 0;
      u_ros_desAngle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ros_desAngle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ros_desAngle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ros_desAngle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ros_desAngle = u_ros_desAngle.real;
      offset += sizeof(this->ros_desAngle);
      union {
        float real;
        uint32_t base;
      } u_ros_desTorque;
      u_ros_desTorque.base = 0;
      u_ros_desTorque.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ros_desTorque.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ros_desTorque.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ros_desTorque.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ros_desTorque = u_ros_desTorque.real;
      offset += sizeof(this->ros_desTorque);
     return offset;
    }

    virtual const char * getType() override { return "custom_msgs_gripper/GripperInputMsg"; };
    virtual const char * getMD5() override { return "5653be6978942489d7baaf7938b194d3"; };

  };

}
#endif
