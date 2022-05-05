#ifndef _ROS_custom_msgs_FootHapticDataMsg_h
#define _ROS_custom_msgs_FootHapticDataMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace custom_msgs
{

  class FootHapticDataMsg : public ros::Msg
  {
    public:
      float fh_haptEffLegIn[7];
      float fh_normEffortCoeffs[7];
      float fh_jointLimCoeffs[7];
      float fh_bckgndEffLeg[7];
      float fh_weberRatios[7];
      float fh_weberCoeff[7];
      float fh_haptEffLPF[5];
      float fh_haptEffLPF_Proj[5];
      float fh_haptEffHPF[5];
      float fh_effFootOut[5];
      float fh_vibFB[5];
      float fh_maxPossGains[5];
      typedef float _fh_effGainRaw_type;
      _fh_effGainRaw_type fh_effGainRaw;
      typedef float _fh_effGainBounded_type;
      _fh_effGainBounded_type fh_effGainBounded;

    FootHapticDataMsg():
      fh_haptEffLegIn(),
      fh_normEffortCoeffs(),
      fh_jointLimCoeffs(),
      fh_bckgndEffLeg(),
      fh_weberRatios(),
      fh_weberCoeff(),
      fh_haptEffLPF(),
      fh_haptEffLPF_Proj(),
      fh_haptEffHPF(),
      fh_effFootOut(),
      fh_vibFB(),
      fh_maxPossGains(),
      fh_effGainRaw(0),
      fh_effGainBounded(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 7; i++){
      union {
        float real;
        uint32_t base;
      } u_fh_haptEffLegIni;
      u_fh_haptEffLegIni.real = this->fh_haptEffLegIn[i];
      *(outbuffer + offset + 0) = (u_fh_haptEffLegIni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fh_haptEffLegIni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fh_haptEffLegIni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fh_haptEffLegIni.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fh_haptEffLegIn[i]);
      }
      for( uint32_t i = 0; i < 7; i++){
      union {
        float real;
        uint32_t base;
      } u_fh_normEffortCoeffsi;
      u_fh_normEffortCoeffsi.real = this->fh_normEffortCoeffs[i];
      *(outbuffer + offset + 0) = (u_fh_normEffortCoeffsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fh_normEffortCoeffsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fh_normEffortCoeffsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fh_normEffortCoeffsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fh_normEffortCoeffs[i]);
      }
      for( uint32_t i = 0; i < 7; i++){
      union {
        float real;
        uint32_t base;
      } u_fh_jointLimCoeffsi;
      u_fh_jointLimCoeffsi.real = this->fh_jointLimCoeffs[i];
      *(outbuffer + offset + 0) = (u_fh_jointLimCoeffsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fh_jointLimCoeffsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fh_jointLimCoeffsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fh_jointLimCoeffsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fh_jointLimCoeffs[i]);
      }
      for( uint32_t i = 0; i < 7; i++){
      union {
        float real;
        uint32_t base;
      } u_fh_bckgndEffLegi;
      u_fh_bckgndEffLegi.real = this->fh_bckgndEffLeg[i];
      *(outbuffer + offset + 0) = (u_fh_bckgndEffLegi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fh_bckgndEffLegi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fh_bckgndEffLegi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fh_bckgndEffLegi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fh_bckgndEffLeg[i]);
      }
      for( uint32_t i = 0; i < 7; i++){
      union {
        float real;
        uint32_t base;
      } u_fh_weberRatiosi;
      u_fh_weberRatiosi.real = this->fh_weberRatios[i];
      *(outbuffer + offset + 0) = (u_fh_weberRatiosi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fh_weberRatiosi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fh_weberRatiosi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fh_weberRatiosi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fh_weberRatios[i]);
      }
      for( uint32_t i = 0; i < 7; i++){
      union {
        float real;
        uint32_t base;
      } u_fh_weberCoeffi;
      u_fh_weberCoeffi.real = this->fh_weberCoeff[i];
      *(outbuffer + offset + 0) = (u_fh_weberCoeffi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fh_weberCoeffi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fh_weberCoeffi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fh_weberCoeffi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fh_weberCoeff[i]);
      }
      for( uint32_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_fh_haptEffLPFi;
      u_fh_haptEffLPFi.real = this->fh_haptEffLPF[i];
      *(outbuffer + offset + 0) = (u_fh_haptEffLPFi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fh_haptEffLPFi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fh_haptEffLPFi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fh_haptEffLPFi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fh_haptEffLPF[i]);
      }
      for( uint32_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_fh_haptEffLPF_Proji;
      u_fh_haptEffLPF_Proji.real = this->fh_haptEffLPF_Proj[i];
      *(outbuffer + offset + 0) = (u_fh_haptEffLPF_Proji.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fh_haptEffLPF_Proji.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fh_haptEffLPF_Proji.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fh_haptEffLPF_Proji.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fh_haptEffLPF_Proj[i]);
      }
      for( uint32_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_fh_haptEffHPFi;
      u_fh_haptEffHPFi.real = this->fh_haptEffHPF[i];
      *(outbuffer + offset + 0) = (u_fh_haptEffHPFi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fh_haptEffHPFi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fh_haptEffHPFi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fh_haptEffHPFi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fh_haptEffHPF[i]);
      }
      for( uint32_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_fh_effFootOuti;
      u_fh_effFootOuti.real = this->fh_effFootOut[i];
      *(outbuffer + offset + 0) = (u_fh_effFootOuti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fh_effFootOuti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fh_effFootOuti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fh_effFootOuti.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fh_effFootOut[i]);
      }
      for( uint32_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_fh_vibFBi;
      u_fh_vibFBi.real = this->fh_vibFB[i];
      *(outbuffer + offset + 0) = (u_fh_vibFBi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fh_vibFBi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fh_vibFBi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fh_vibFBi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fh_vibFB[i]);
      }
      for( uint32_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_fh_maxPossGainsi;
      u_fh_maxPossGainsi.real = this->fh_maxPossGains[i];
      *(outbuffer + offset + 0) = (u_fh_maxPossGainsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fh_maxPossGainsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fh_maxPossGainsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fh_maxPossGainsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fh_maxPossGains[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_fh_effGainRaw;
      u_fh_effGainRaw.real = this->fh_effGainRaw;
      *(outbuffer + offset + 0) = (u_fh_effGainRaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fh_effGainRaw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fh_effGainRaw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fh_effGainRaw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fh_effGainRaw);
      union {
        float real;
        uint32_t base;
      } u_fh_effGainBounded;
      u_fh_effGainBounded.real = this->fh_effGainBounded;
      *(outbuffer + offset + 0) = (u_fh_effGainBounded.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fh_effGainBounded.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fh_effGainBounded.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fh_effGainBounded.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fh_effGainBounded);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 7; i++){
      union {
        float real;
        uint32_t base;
      } u_fh_haptEffLegIni;
      u_fh_haptEffLegIni.base = 0;
      u_fh_haptEffLegIni.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fh_haptEffLegIni.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fh_haptEffLegIni.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fh_haptEffLegIni.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fh_haptEffLegIn[i] = u_fh_haptEffLegIni.real;
      offset += sizeof(this->fh_haptEffLegIn[i]);
      }
      for( uint32_t i = 0; i < 7; i++){
      union {
        float real;
        uint32_t base;
      } u_fh_normEffortCoeffsi;
      u_fh_normEffortCoeffsi.base = 0;
      u_fh_normEffortCoeffsi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fh_normEffortCoeffsi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fh_normEffortCoeffsi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fh_normEffortCoeffsi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fh_normEffortCoeffs[i] = u_fh_normEffortCoeffsi.real;
      offset += sizeof(this->fh_normEffortCoeffs[i]);
      }
      for( uint32_t i = 0; i < 7; i++){
      union {
        float real;
        uint32_t base;
      } u_fh_jointLimCoeffsi;
      u_fh_jointLimCoeffsi.base = 0;
      u_fh_jointLimCoeffsi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fh_jointLimCoeffsi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fh_jointLimCoeffsi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fh_jointLimCoeffsi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fh_jointLimCoeffs[i] = u_fh_jointLimCoeffsi.real;
      offset += sizeof(this->fh_jointLimCoeffs[i]);
      }
      for( uint32_t i = 0; i < 7; i++){
      union {
        float real;
        uint32_t base;
      } u_fh_bckgndEffLegi;
      u_fh_bckgndEffLegi.base = 0;
      u_fh_bckgndEffLegi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fh_bckgndEffLegi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fh_bckgndEffLegi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fh_bckgndEffLegi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fh_bckgndEffLeg[i] = u_fh_bckgndEffLegi.real;
      offset += sizeof(this->fh_bckgndEffLeg[i]);
      }
      for( uint32_t i = 0; i < 7; i++){
      union {
        float real;
        uint32_t base;
      } u_fh_weberRatiosi;
      u_fh_weberRatiosi.base = 0;
      u_fh_weberRatiosi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fh_weberRatiosi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fh_weberRatiosi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fh_weberRatiosi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fh_weberRatios[i] = u_fh_weberRatiosi.real;
      offset += sizeof(this->fh_weberRatios[i]);
      }
      for( uint32_t i = 0; i < 7; i++){
      union {
        float real;
        uint32_t base;
      } u_fh_weberCoeffi;
      u_fh_weberCoeffi.base = 0;
      u_fh_weberCoeffi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fh_weberCoeffi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fh_weberCoeffi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fh_weberCoeffi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fh_weberCoeff[i] = u_fh_weberCoeffi.real;
      offset += sizeof(this->fh_weberCoeff[i]);
      }
      for( uint32_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_fh_haptEffLPFi;
      u_fh_haptEffLPFi.base = 0;
      u_fh_haptEffLPFi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fh_haptEffLPFi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fh_haptEffLPFi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fh_haptEffLPFi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fh_haptEffLPF[i] = u_fh_haptEffLPFi.real;
      offset += sizeof(this->fh_haptEffLPF[i]);
      }
      for( uint32_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_fh_haptEffLPF_Proji;
      u_fh_haptEffLPF_Proji.base = 0;
      u_fh_haptEffLPF_Proji.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fh_haptEffLPF_Proji.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fh_haptEffLPF_Proji.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fh_haptEffLPF_Proji.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fh_haptEffLPF_Proj[i] = u_fh_haptEffLPF_Proji.real;
      offset += sizeof(this->fh_haptEffLPF_Proj[i]);
      }
      for( uint32_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_fh_haptEffHPFi;
      u_fh_haptEffHPFi.base = 0;
      u_fh_haptEffHPFi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fh_haptEffHPFi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fh_haptEffHPFi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fh_haptEffHPFi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fh_haptEffHPF[i] = u_fh_haptEffHPFi.real;
      offset += sizeof(this->fh_haptEffHPF[i]);
      }
      for( uint32_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_fh_effFootOuti;
      u_fh_effFootOuti.base = 0;
      u_fh_effFootOuti.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fh_effFootOuti.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fh_effFootOuti.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fh_effFootOuti.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fh_effFootOut[i] = u_fh_effFootOuti.real;
      offset += sizeof(this->fh_effFootOut[i]);
      }
      for( uint32_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_fh_vibFBi;
      u_fh_vibFBi.base = 0;
      u_fh_vibFBi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fh_vibFBi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fh_vibFBi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fh_vibFBi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fh_vibFB[i] = u_fh_vibFBi.real;
      offset += sizeof(this->fh_vibFB[i]);
      }
      for( uint32_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_fh_maxPossGainsi;
      u_fh_maxPossGainsi.base = 0;
      u_fh_maxPossGainsi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fh_maxPossGainsi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fh_maxPossGainsi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fh_maxPossGainsi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fh_maxPossGains[i] = u_fh_maxPossGainsi.real;
      offset += sizeof(this->fh_maxPossGains[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_fh_effGainRaw;
      u_fh_effGainRaw.base = 0;
      u_fh_effGainRaw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fh_effGainRaw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fh_effGainRaw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fh_effGainRaw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fh_effGainRaw = u_fh_effGainRaw.real;
      offset += sizeof(this->fh_effGainRaw);
      union {
        float real;
        uint32_t base;
      } u_fh_effGainBounded;
      u_fh_effGainBounded.base = 0;
      u_fh_effGainBounded.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fh_effGainBounded.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fh_effGainBounded.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fh_effGainBounded.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fh_effGainBounded = u_fh_effGainBounded.real;
      offset += sizeof(this->fh_effGainBounded);
     return offset;
    }

    virtual const char * getType() override { return "custom_msgs/FootHapticDataMsg"; };
    virtual const char * getMD5() override { return "360e78cd21b795f6598cc5fd3fae4cf9"; };

  };

}
#endif
