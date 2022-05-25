#ifndef _ROS_surgical_task_SurgicalTaskStateMsg_h
#define _ROS_surgical_task_SurgicalTaskStateMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace surgical_task
{

  class SurgicalTaskStateMsg : public ros::Msg
  {
    public:
      typedef int8_t _humanInputMode_type;
      _humanInputMode_type humanInputMode;
      typedef int8_t _currentRobot_type;
      _currentRobot_type currentRobot;
      typedef bool _useCameraAssistance_type;
      _useCameraAssistance_type useCameraAssistance;
      typedef int8_t _cameraAssistanceModality_type;
      _cameraAssistanceModality_type cameraAssistanceModality;
      uint32_t beliefsC_length;
      typedef float _beliefsC_type;
      _beliefsC_type st_beliefsC;
      _beliefsC_type * beliefsC;
      typedef bool _clutching_type;
      _clutching_type clutching;
      typedef bool _wait_type;
      _wait_type wait;
      bool useRobot[2];
      int8_t tool[2];
      float retractorPositionC[3];

    SurgicalTaskStateMsg():
      humanInputMode(0),
      currentRobot(0),
      useCameraAssistance(0),
      cameraAssistanceModality(0),
      beliefsC_length(0), st_beliefsC(), beliefsC(nullptr),
      clutching(0),
      wait(0),
      useRobot(),
      tool(),
      retractorPositionC()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_humanInputMode;
      u_humanInputMode.real = this->humanInputMode;
      *(outbuffer + offset + 0) = (u_humanInputMode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->humanInputMode);
      union {
        int8_t real;
        uint8_t base;
      } u_currentRobot;
      u_currentRobot.real = this->currentRobot;
      *(outbuffer + offset + 0) = (u_currentRobot.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->currentRobot);
      union {
        bool real;
        uint8_t base;
      } u_useCameraAssistance;
      u_useCameraAssistance.real = this->useCameraAssistance;
      *(outbuffer + offset + 0) = (u_useCameraAssistance.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->useCameraAssistance);
      union {
        int8_t real;
        uint8_t base;
      } u_cameraAssistanceModality;
      u_cameraAssistanceModality.real = this->cameraAssistanceModality;
      *(outbuffer + offset + 0) = (u_cameraAssistanceModality.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cameraAssistanceModality);
      *(outbuffer + offset + 0) = (this->beliefsC_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->beliefsC_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->beliefsC_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->beliefsC_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->beliefsC_length);
      for( uint32_t i = 0; i < beliefsC_length; i++){
      union {
        float real;
        uint32_t base;
      } u_beliefsCi;
      u_beliefsCi.real = this->beliefsC[i];
      *(outbuffer + offset + 0) = (u_beliefsCi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_beliefsCi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_beliefsCi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_beliefsCi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->beliefsC[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_clutching;
      u_clutching.real = this->clutching;
      *(outbuffer + offset + 0) = (u_clutching.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->clutching);
      union {
        bool real;
        uint8_t base;
      } u_wait;
      u_wait.real = this->wait;
      *(outbuffer + offset + 0) = (u_wait.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wait);
      for( uint32_t i = 0; i < 2; i++){
      union {
        bool real;
        uint8_t base;
      } u_useRoboti;
      u_useRoboti.real = this->useRobot[i];
      *(outbuffer + offset + 0) = (u_useRoboti.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->useRobot[i]);
      }
      for( uint32_t i = 0; i < 2; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_tooli;
      u_tooli.real = this->tool[i];
      *(outbuffer + offset + 0) = (u_tooli.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->tool[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_retractorPositionCi;
      u_retractorPositionCi.real = this->retractorPositionC[i];
      *(outbuffer + offset + 0) = (u_retractorPositionCi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_retractorPositionCi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_retractorPositionCi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_retractorPositionCi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->retractorPositionC[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_humanInputMode;
      u_humanInputMode.base = 0;
      u_humanInputMode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->humanInputMode = u_humanInputMode.real;
      offset += sizeof(this->humanInputMode);
      union {
        int8_t real;
        uint8_t base;
      } u_currentRobot;
      u_currentRobot.base = 0;
      u_currentRobot.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->currentRobot = u_currentRobot.real;
      offset += sizeof(this->currentRobot);
      union {
        bool real;
        uint8_t base;
      } u_useCameraAssistance;
      u_useCameraAssistance.base = 0;
      u_useCameraAssistance.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->useCameraAssistance = u_useCameraAssistance.real;
      offset += sizeof(this->useCameraAssistance);
      union {
        int8_t real;
        uint8_t base;
      } u_cameraAssistanceModality;
      u_cameraAssistanceModality.base = 0;
      u_cameraAssistanceModality.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->cameraAssistanceModality = u_cameraAssistanceModality.real;
      offset += sizeof(this->cameraAssistanceModality);
      uint32_t beliefsC_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      beliefsC_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      beliefsC_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      beliefsC_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->beliefsC_length);
      if(beliefsC_lengthT > beliefsC_length)
        this->beliefsC = (float*)realloc(this->beliefsC, beliefsC_lengthT * sizeof(float));
      beliefsC_length = beliefsC_lengthT;
      for( uint32_t i = 0; i < beliefsC_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_beliefsC;
      u_st_beliefsC.base = 0;
      u_st_beliefsC.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_beliefsC.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_beliefsC.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_beliefsC.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_beliefsC = u_st_beliefsC.real;
      offset += sizeof(this->st_beliefsC);
        memcpy( &(this->beliefsC[i]), &(this->st_beliefsC), sizeof(float));
      }
      union {
        bool real;
        uint8_t base;
      } u_clutching;
      u_clutching.base = 0;
      u_clutching.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->clutching = u_clutching.real;
      offset += sizeof(this->clutching);
      union {
        bool real;
        uint8_t base;
      } u_wait;
      u_wait.base = 0;
      u_wait.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wait = u_wait.real;
      offset += sizeof(this->wait);
      for( uint32_t i = 0; i < 2; i++){
      union {
        bool real;
        uint8_t base;
      } u_useRoboti;
      u_useRoboti.base = 0;
      u_useRoboti.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->useRobot[i] = u_useRoboti.real;
      offset += sizeof(this->useRobot[i]);
      }
      for( uint32_t i = 0; i < 2; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_tooli;
      u_tooli.base = 0;
      u_tooli.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->tool[i] = u_tooli.real;
      offset += sizeof(this->tool[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_retractorPositionCi;
      u_retractorPositionCi.base = 0;
      u_retractorPositionCi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_retractorPositionCi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_retractorPositionCi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_retractorPositionCi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->retractorPositionC[i] = u_retractorPositionCi.real;
      offset += sizeof(this->retractorPositionC[i]);
      }
     return offset;
    }

    virtual const char * getType() override { return "surgical_task/SurgicalTaskStateMsg"; };
    virtual const char * getMD5() override { return "837c7495ec69e6bdff0ec62ffe60a17a"; };

  };

}
#endif
