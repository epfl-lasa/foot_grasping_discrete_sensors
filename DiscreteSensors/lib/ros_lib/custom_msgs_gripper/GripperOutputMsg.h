#ifndef _ROS_custom_msgs_gripper_GripperOutputMsg_h
#define _ROS_custom_msgs_gripper_GripperOutputMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace custom_msgs_gripper
{

  class GripperOutputMsg : public ros::Msg
  {
    public:
      typedef ros::Time _gripper_stamp_type;
      _gripper_stamp_type gripper_stamp;
      typedef int8_t _gripper_id_type;
      _gripper_id_type gripper_id;
      typedef float _gripper_position_type;
      _gripper_position_type gripper_position;
      typedef float _gripper_speed_type;
      _gripper_speed_type gripper_speed;
      typedef float _gripper_desPosition_type;
      _gripper_desPosition_type gripper_desPosition;
      typedef float _gripper_torqueCmd_type;
      _gripper_torqueCmd_type gripper_torqueCmd;
      typedef float _gripper_torqueMeas_type;
      _gripper_torqueMeas_type gripper_torqueMeas;
      typedef int8_t _gripper_machineState_type;
      _gripper_machineState_type gripper_machineState;

    GripperOutputMsg():
      gripper_stamp(),
      gripper_id(0),
      gripper_position(0),
      gripper_speed(0),
      gripper_desPosition(0),
      gripper_torqueCmd(0),
      gripper_torqueMeas(0),
      gripper_machineState(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->gripper_stamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gripper_stamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->gripper_stamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->gripper_stamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gripper_stamp.sec);
      *(outbuffer + offset + 0) = (this->gripper_stamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gripper_stamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->gripper_stamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->gripper_stamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gripper_stamp.nsec);
      union {
        int8_t real;
        uint8_t base;
      } u_gripper_id;
      u_gripper_id.real = this->gripper_id;
      *(outbuffer + offset + 0) = (u_gripper_id.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gripper_id);
      union {
        float real;
        uint32_t base;
      } u_gripper_position;
      u_gripper_position.real = this->gripper_position;
      *(outbuffer + offset + 0) = (u_gripper_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gripper_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gripper_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gripper_position.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gripper_position);
      union {
        float real;
        uint32_t base;
      } u_gripper_speed;
      u_gripper_speed.real = this->gripper_speed;
      *(outbuffer + offset + 0) = (u_gripper_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gripper_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gripper_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gripper_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gripper_speed);
      union {
        float real;
        uint32_t base;
      } u_gripper_desPosition;
      u_gripper_desPosition.real = this->gripper_desPosition;
      *(outbuffer + offset + 0) = (u_gripper_desPosition.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gripper_desPosition.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gripper_desPosition.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gripper_desPosition.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gripper_desPosition);
      union {
        float real;
        uint32_t base;
      } u_gripper_torqueCmd;
      u_gripper_torqueCmd.real = this->gripper_torqueCmd;
      *(outbuffer + offset + 0) = (u_gripper_torqueCmd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gripper_torqueCmd.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gripper_torqueCmd.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gripper_torqueCmd.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gripper_torqueCmd);
      union {
        float real;
        uint32_t base;
      } u_gripper_torqueMeas;
      u_gripper_torqueMeas.real = this->gripper_torqueMeas;
      *(outbuffer + offset + 0) = (u_gripper_torqueMeas.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gripper_torqueMeas.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gripper_torqueMeas.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gripper_torqueMeas.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gripper_torqueMeas);
      union {
        int8_t real;
        uint8_t base;
      } u_gripper_machineState;
      u_gripper_machineState.real = this->gripper_machineState;
      *(outbuffer + offset + 0) = (u_gripper_machineState.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gripper_machineState);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->gripper_stamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->gripper_stamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gripper_stamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->gripper_stamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->gripper_stamp.sec);
      this->gripper_stamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->gripper_stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gripper_stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->gripper_stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->gripper_stamp.nsec);
      union {
        int8_t real;
        uint8_t base;
      } u_gripper_id;
      u_gripper_id.base = 0;
      u_gripper_id.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->gripper_id = u_gripper_id.real;
      offset += sizeof(this->gripper_id);
      union {
        float real;
        uint32_t base;
      } u_gripper_position;
      u_gripper_position.base = 0;
      u_gripper_position.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gripper_position.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gripper_position.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gripper_position.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gripper_position = u_gripper_position.real;
      offset += sizeof(this->gripper_position);
      union {
        float real;
        uint32_t base;
      } u_gripper_speed;
      u_gripper_speed.base = 0;
      u_gripper_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gripper_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gripper_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gripper_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gripper_speed = u_gripper_speed.real;
      offset += sizeof(this->gripper_speed);
      union {
        float real;
        uint32_t base;
      } u_gripper_desPosition;
      u_gripper_desPosition.base = 0;
      u_gripper_desPosition.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gripper_desPosition.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gripper_desPosition.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gripper_desPosition.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gripper_desPosition = u_gripper_desPosition.real;
      offset += sizeof(this->gripper_desPosition);
      union {
        float real;
        uint32_t base;
      } u_gripper_torqueCmd;
      u_gripper_torqueCmd.base = 0;
      u_gripper_torqueCmd.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gripper_torqueCmd.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gripper_torqueCmd.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gripper_torqueCmd.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gripper_torqueCmd = u_gripper_torqueCmd.real;
      offset += sizeof(this->gripper_torqueCmd);
      union {
        float real;
        uint32_t base;
      } u_gripper_torqueMeas;
      u_gripper_torqueMeas.base = 0;
      u_gripper_torqueMeas.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gripper_torqueMeas.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gripper_torqueMeas.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gripper_torqueMeas.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gripper_torqueMeas = u_gripper_torqueMeas.real;
      offset += sizeof(this->gripper_torqueMeas);
      union {
        int8_t real;
        uint8_t base;
      } u_gripper_machineState;
      u_gripper_machineState.base = 0;
      u_gripper_machineState.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->gripper_machineState = u_gripper_machineState.real;
      offset += sizeof(this->gripper_machineState);
     return offset;
    }

    virtual const char * getType() override { return "custom_msgs_gripper/GripperOutputMsg"; };
    virtual const char * getMD5() override { return "f335f59b0a72cab5b5103379adc578c3"; };

  };

}
#endif
