#ifndef _ROS_SERVICE_GripperSetStateSrv_h
#define _ROS_SERVICE_GripperSetStateSrv_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace custom_msgs_gripper
{

static const char GRIPPERSETSTATESRV[] = "custom_msgs_gripper/GripperSetStateSrv";

  class GripperSetStateSrvRequest : public ros::Msg
  {
    public:
      typedef int8_t _ros_desState_type;
      _ros_desState_type ros_desState;

    GripperSetStateSrvRequest():
      ros_desState(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_ros_desState;
      u_ros_desState.real = this->ros_desState;
      *(outbuffer + offset + 0) = (u_ros_desState.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ros_desState);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_ros_desState;
      u_ros_desState.base = 0;
      u_ros_desState.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ros_desState = u_ros_desState.real;
      offset += sizeof(this->ros_desState);
     return offset;
    }

    virtual const char * getType() override { return GRIPPERSETSTATESRV; };
    virtual const char * getMD5() override { return "add32780982964f9747bcd348e64c9fd"; };

  };

  class GripperSetStateSrvResponse : public ros::Msg
  {
    public:
      typedef bool _gripper_newState_type;
      _gripper_newState_type gripper_newState;

    GripperSetStateSrvResponse():
      gripper_newState(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_gripper_newState;
      u_gripper_newState.real = this->gripper_newState;
      *(outbuffer + offset + 0) = (u_gripper_newState.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gripper_newState);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_gripper_newState;
      u_gripper_newState.base = 0;
      u_gripper_newState.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->gripper_newState = u_gripper_newState.real;
      offset += sizeof(this->gripper_newState);
     return offset;
    }

    virtual const char * getType() override { return GRIPPERSETSTATESRV; };
    virtual const char * getMD5() override { return "0f0d6a6ff05f3dd6f14969e84835312d"; };

  };

  class GripperSetStateSrv {
    public:
    typedef GripperSetStateSrvRequest Request;
    typedef GripperSetStateSrvResponse Response;
  };

}
#endif
