#ifndef _ROS_custom_msgs_gripper_GraspingAssistanceMsg_h
#define _ROS_custom_msgs_gripper_GraspingAssistanceMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace custom_msgs_gripper
{

  class GraspingAssistanceMsg : public ros::Msg
  {
    public:
      float ga_posThresholds[5];
      float ga_speedThresholds[5];
      typedef float _ga_threshold_type;
      _ga_threshold_type ga_threshold;
      typedef float _ga_wantAssistanceTank_type;
      _ga_wantAssistanceTank_type ga_wantAssistanceTank;
      typedef float _ga_wantAssistanceBelief_type;
      _ga_wantAssistanceBelief_type ga_wantAssistanceBelief;
      typedef bool _ga_assistanceOn_type;
      _ga_assistanceOn_type ga_assistanceOn;

    GraspingAssistanceMsg():
      ga_posThresholds(),
      ga_speedThresholds(),
      ga_threshold(0),
      ga_wantAssistanceTank(0),
      ga_wantAssistanceBelief(0),
      ga_assistanceOn(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_ga_posThresholdsi;
      u_ga_posThresholdsi.real = this->ga_posThresholds[i];
      *(outbuffer + offset + 0) = (u_ga_posThresholdsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ga_posThresholdsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ga_posThresholdsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ga_posThresholdsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ga_posThresholds[i]);
      }
      for( uint32_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_ga_speedThresholdsi;
      u_ga_speedThresholdsi.real = this->ga_speedThresholds[i];
      *(outbuffer + offset + 0) = (u_ga_speedThresholdsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ga_speedThresholdsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ga_speedThresholdsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ga_speedThresholdsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ga_speedThresholds[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_ga_threshold;
      u_ga_threshold.real = this->ga_threshold;
      *(outbuffer + offset + 0) = (u_ga_threshold.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ga_threshold.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ga_threshold.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ga_threshold.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ga_threshold);
      union {
        float real;
        uint32_t base;
      } u_ga_wantAssistanceTank;
      u_ga_wantAssistanceTank.real = this->ga_wantAssistanceTank;
      *(outbuffer + offset + 0) = (u_ga_wantAssistanceTank.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ga_wantAssistanceTank.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ga_wantAssistanceTank.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ga_wantAssistanceTank.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ga_wantAssistanceTank);
      union {
        float real;
        uint32_t base;
      } u_ga_wantAssistanceBelief;
      u_ga_wantAssistanceBelief.real = this->ga_wantAssistanceBelief;
      *(outbuffer + offset + 0) = (u_ga_wantAssistanceBelief.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ga_wantAssistanceBelief.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ga_wantAssistanceBelief.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ga_wantAssistanceBelief.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ga_wantAssistanceBelief);
      union {
        bool real;
        uint8_t base;
      } u_ga_assistanceOn;
      u_ga_assistanceOn.real = this->ga_assistanceOn;
      *(outbuffer + offset + 0) = (u_ga_assistanceOn.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ga_assistanceOn);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_ga_posThresholdsi;
      u_ga_posThresholdsi.base = 0;
      u_ga_posThresholdsi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ga_posThresholdsi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ga_posThresholdsi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ga_posThresholdsi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ga_posThresholds[i] = u_ga_posThresholdsi.real;
      offset += sizeof(this->ga_posThresholds[i]);
      }
      for( uint32_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_ga_speedThresholdsi;
      u_ga_speedThresholdsi.base = 0;
      u_ga_speedThresholdsi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ga_speedThresholdsi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ga_speedThresholdsi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ga_speedThresholdsi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ga_speedThresholds[i] = u_ga_speedThresholdsi.real;
      offset += sizeof(this->ga_speedThresholds[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_ga_threshold;
      u_ga_threshold.base = 0;
      u_ga_threshold.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ga_threshold.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ga_threshold.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ga_threshold.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ga_threshold = u_ga_threshold.real;
      offset += sizeof(this->ga_threshold);
      union {
        float real;
        uint32_t base;
      } u_ga_wantAssistanceTank;
      u_ga_wantAssistanceTank.base = 0;
      u_ga_wantAssistanceTank.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ga_wantAssistanceTank.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ga_wantAssistanceTank.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ga_wantAssistanceTank.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ga_wantAssistanceTank = u_ga_wantAssistanceTank.real;
      offset += sizeof(this->ga_wantAssistanceTank);
      union {
        float real;
        uint32_t base;
      } u_ga_wantAssistanceBelief;
      u_ga_wantAssistanceBelief.base = 0;
      u_ga_wantAssistanceBelief.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ga_wantAssistanceBelief.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ga_wantAssistanceBelief.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ga_wantAssistanceBelief.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ga_wantAssistanceBelief = u_ga_wantAssistanceBelief.real;
      offset += sizeof(this->ga_wantAssistanceBelief);
      union {
        bool real;
        uint8_t base;
      } u_ga_assistanceOn;
      u_ga_assistanceOn.base = 0;
      u_ga_assistanceOn.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ga_assistanceOn = u_ga_assistanceOn.real;
      offset += sizeof(this->ga_assistanceOn);
     return offset;
    }

    virtual const char * getType() override { return "custom_msgs_gripper/GraspingAssistanceMsg"; };
    virtual const char * getMD5() override { return "24530cdefff1541af64aa1c124f5f431"; };

  };

}
#endif
