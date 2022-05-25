#ifndef _ROS_surgical_task_RobotStateMsg_h
#define _ROS_surgical_task_RobotStateMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace surgical_task
{

  class RobotStateMsg : public ros::Msg
  {
    public:
      typedef int8_t _controlPhase_type;
      _controlPhase_type controlPhase;
      typedef int8_t _linearMapping_type;
      _linearMapping_type linearMapping;
      typedef int8_t _selfRotationMapping_type;
      _selfRotationMapping_type selfRotationMapping;
      float trocarPosition[3];
      float tipPosition[3];
      float ikTipPosition[3];
      typedef float _dRcmTrocar_type;
      _dRcmTrocar_type dRcmTrocar;
      typedef float _dRcmTip_type;
      _dRcmTip_type dRcmTip;
      float currentJoints[7];
      float ikJoints[7];
      typedef int8_t _ikRes_type;
      _ikRes_type ikRes;
      float humanInput[5];
      float vdTool[3];
      typedef float _selfRotationCommand_type;
      _selfRotationCommand_type selfRotationCommand;
      float currentOffsetFromInsertion[3];
      float ikOffsetFromInsertion[3];
      float desiredOffsetFromInsertion[3];
      typedef bool _eeCollisionConstraintActive_type;
      _eeCollisionConstraintActive_type eeCollisionConstraintActive;
      typedef float _dEEEE_type;
      _dEEEE_type dEEEE;
      typedef bool _toolCollisionConstraintActive_type;
      _toolCollisionConstraintActive_type toolCollisionConstraintActive;
      typedef float _dToolTool_type;
      _dToolTool_type dToolTool;
      typedef bool _workspaceCollisionConstraintActive_type;
      _workspaceCollisionConstraintActive_type workspaceCollisionConstraintActive;
      typedef bool _minimumInsertionConstraintActive_type;
      _minimumInsertionConstraintActive_type minimumInsertionConstraintActive;
      typedef float _desiredGripperPosition_type;
      _desiredGripperPosition_type desiredGripperPosition;
      typedef float _tankH_type;
      _tankH_type tankH;
      typedef float _alphaH_type;
      _alphaH_type alphaH;
      float Fext[3];
      float Fm[3];
      float Fh[3];

    RobotStateMsg():
      controlPhase(0),
      linearMapping(0),
      selfRotationMapping(0),
      trocarPosition(),
      tipPosition(),
      ikTipPosition(),
      dRcmTrocar(0),
      dRcmTip(0),
      currentJoints(),
      ikJoints(),
      ikRes(0),
      humanInput(),
      vdTool(),
      selfRotationCommand(0),
      currentOffsetFromInsertion(),
      ikOffsetFromInsertion(),
      desiredOffsetFromInsertion(),
      eeCollisionConstraintActive(0),
      dEEEE(0),
      toolCollisionConstraintActive(0),
      dToolTool(0),
      workspaceCollisionConstraintActive(0),
      minimumInsertionConstraintActive(0),
      desiredGripperPosition(0),
      tankH(0),
      alphaH(0),
      Fext(),
      Fm(),
      Fh()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_controlPhase;
      u_controlPhase.real = this->controlPhase;
      *(outbuffer + offset + 0) = (u_controlPhase.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->controlPhase);
      union {
        int8_t real;
        uint8_t base;
      } u_linearMapping;
      u_linearMapping.real = this->linearMapping;
      *(outbuffer + offset + 0) = (u_linearMapping.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->linearMapping);
      union {
        int8_t real;
        uint8_t base;
      } u_selfRotationMapping;
      u_selfRotationMapping.real = this->selfRotationMapping;
      *(outbuffer + offset + 0) = (u_selfRotationMapping.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->selfRotationMapping);
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_trocarPositioni;
      u_trocarPositioni.real = this->trocarPosition[i];
      *(outbuffer + offset + 0) = (u_trocarPositioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_trocarPositioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_trocarPositioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_trocarPositioni.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->trocarPosition[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_tipPositioni;
      u_tipPositioni.real = this->tipPosition[i];
      *(outbuffer + offset + 0) = (u_tipPositioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tipPositioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tipPositioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tipPositioni.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tipPosition[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_ikTipPositioni;
      u_ikTipPositioni.real = this->ikTipPosition[i];
      *(outbuffer + offset + 0) = (u_ikTipPositioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ikTipPositioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ikTipPositioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ikTipPositioni.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ikTipPosition[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_dRcmTrocar;
      u_dRcmTrocar.real = this->dRcmTrocar;
      *(outbuffer + offset + 0) = (u_dRcmTrocar.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dRcmTrocar.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dRcmTrocar.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dRcmTrocar.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dRcmTrocar);
      union {
        float real;
        uint32_t base;
      } u_dRcmTip;
      u_dRcmTip.real = this->dRcmTip;
      *(outbuffer + offset + 0) = (u_dRcmTip.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dRcmTip.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dRcmTip.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dRcmTip.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dRcmTip);
      for( uint32_t i = 0; i < 7; i++){
      union {
        float real;
        uint32_t base;
      } u_currentJointsi;
      u_currentJointsi.real = this->currentJoints[i];
      *(outbuffer + offset + 0) = (u_currentJointsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_currentJointsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_currentJointsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_currentJointsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->currentJoints[i]);
      }
      for( uint32_t i = 0; i < 7; i++){
      union {
        float real;
        uint32_t base;
      } u_ikJointsi;
      u_ikJointsi.real = this->ikJoints[i];
      *(outbuffer + offset + 0) = (u_ikJointsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ikJointsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ikJointsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ikJointsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ikJoints[i]);
      }
      union {
        int8_t real;
        uint8_t base;
      } u_ikRes;
      u_ikRes.real = this->ikRes;
      *(outbuffer + offset + 0) = (u_ikRes.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ikRes);
      for( uint32_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_humanInputi;
      u_humanInputi.real = this->humanInput[i];
      *(outbuffer + offset + 0) = (u_humanInputi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_humanInputi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_humanInputi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_humanInputi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->humanInput[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_vdTooli;
      u_vdTooli.real = this->vdTool[i];
      *(outbuffer + offset + 0) = (u_vdTooli.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vdTooli.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vdTooli.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vdTooli.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vdTool[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_selfRotationCommand;
      u_selfRotationCommand.real = this->selfRotationCommand;
      *(outbuffer + offset + 0) = (u_selfRotationCommand.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_selfRotationCommand.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_selfRotationCommand.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_selfRotationCommand.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->selfRotationCommand);
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_currentOffsetFromInsertioni;
      u_currentOffsetFromInsertioni.real = this->currentOffsetFromInsertion[i];
      *(outbuffer + offset + 0) = (u_currentOffsetFromInsertioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_currentOffsetFromInsertioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_currentOffsetFromInsertioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_currentOffsetFromInsertioni.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->currentOffsetFromInsertion[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_ikOffsetFromInsertioni;
      u_ikOffsetFromInsertioni.real = this->ikOffsetFromInsertion[i];
      *(outbuffer + offset + 0) = (u_ikOffsetFromInsertioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ikOffsetFromInsertioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ikOffsetFromInsertioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ikOffsetFromInsertioni.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ikOffsetFromInsertion[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_desiredOffsetFromInsertioni;
      u_desiredOffsetFromInsertioni.real = this->desiredOffsetFromInsertion[i];
      *(outbuffer + offset + 0) = (u_desiredOffsetFromInsertioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_desiredOffsetFromInsertioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_desiredOffsetFromInsertioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_desiredOffsetFromInsertioni.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->desiredOffsetFromInsertion[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_eeCollisionConstraintActive;
      u_eeCollisionConstraintActive.real = this->eeCollisionConstraintActive;
      *(outbuffer + offset + 0) = (u_eeCollisionConstraintActive.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->eeCollisionConstraintActive);
      union {
        float real;
        uint32_t base;
      } u_dEEEE;
      u_dEEEE.real = this->dEEEE;
      *(outbuffer + offset + 0) = (u_dEEEE.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dEEEE.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dEEEE.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dEEEE.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dEEEE);
      union {
        bool real;
        uint8_t base;
      } u_toolCollisionConstraintActive;
      u_toolCollisionConstraintActive.real = this->toolCollisionConstraintActive;
      *(outbuffer + offset + 0) = (u_toolCollisionConstraintActive.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->toolCollisionConstraintActive);
      union {
        float real;
        uint32_t base;
      } u_dToolTool;
      u_dToolTool.real = this->dToolTool;
      *(outbuffer + offset + 0) = (u_dToolTool.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dToolTool.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dToolTool.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dToolTool.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dToolTool);
      union {
        bool real;
        uint8_t base;
      } u_workspaceCollisionConstraintActive;
      u_workspaceCollisionConstraintActive.real = this->workspaceCollisionConstraintActive;
      *(outbuffer + offset + 0) = (u_workspaceCollisionConstraintActive.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->workspaceCollisionConstraintActive);
      union {
        bool real;
        uint8_t base;
      } u_minimumInsertionConstraintActive;
      u_minimumInsertionConstraintActive.real = this->minimumInsertionConstraintActive;
      *(outbuffer + offset + 0) = (u_minimumInsertionConstraintActive.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->minimumInsertionConstraintActive);
      union {
        float real;
        uint32_t base;
      } u_desiredGripperPosition;
      u_desiredGripperPosition.real = this->desiredGripperPosition;
      *(outbuffer + offset + 0) = (u_desiredGripperPosition.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_desiredGripperPosition.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_desiredGripperPosition.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_desiredGripperPosition.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->desiredGripperPosition);
      union {
        float real;
        uint32_t base;
      } u_tankH;
      u_tankH.real = this->tankH;
      *(outbuffer + offset + 0) = (u_tankH.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tankH.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tankH.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tankH.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tankH);
      union {
        float real;
        uint32_t base;
      } u_alphaH;
      u_alphaH.real = this->alphaH;
      *(outbuffer + offset + 0) = (u_alphaH.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_alphaH.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_alphaH.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_alphaH.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alphaH);
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_Fexti;
      u_Fexti.real = this->Fext[i];
      *(outbuffer + offset + 0) = (u_Fexti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Fexti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Fexti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Fexti.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Fext[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_Fmi;
      u_Fmi.real = this->Fm[i];
      *(outbuffer + offset + 0) = (u_Fmi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Fmi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Fmi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Fmi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Fm[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_Fhi;
      u_Fhi.real = this->Fh[i];
      *(outbuffer + offset + 0) = (u_Fhi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Fhi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Fhi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Fhi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Fh[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_controlPhase;
      u_controlPhase.base = 0;
      u_controlPhase.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->controlPhase = u_controlPhase.real;
      offset += sizeof(this->controlPhase);
      union {
        int8_t real;
        uint8_t base;
      } u_linearMapping;
      u_linearMapping.base = 0;
      u_linearMapping.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->linearMapping = u_linearMapping.real;
      offset += sizeof(this->linearMapping);
      union {
        int8_t real;
        uint8_t base;
      } u_selfRotationMapping;
      u_selfRotationMapping.base = 0;
      u_selfRotationMapping.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->selfRotationMapping = u_selfRotationMapping.real;
      offset += sizeof(this->selfRotationMapping);
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_trocarPositioni;
      u_trocarPositioni.base = 0;
      u_trocarPositioni.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_trocarPositioni.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_trocarPositioni.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_trocarPositioni.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->trocarPosition[i] = u_trocarPositioni.real;
      offset += sizeof(this->trocarPosition[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_tipPositioni;
      u_tipPositioni.base = 0;
      u_tipPositioni.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tipPositioni.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tipPositioni.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tipPositioni.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tipPosition[i] = u_tipPositioni.real;
      offset += sizeof(this->tipPosition[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_ikTipPositioni;
      u_ikTipPositioni.base = 0;
      u_ikTipPositioni.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ikTipPositioni.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ikTipPositioni.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ikTipPositioni.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ikTipPosition[i] = u_ikTipPositioni.real;
      offset += sizeof(this->ikTipPosition[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_dRcmTrocar;
      u_dRcmTrocar.base = 0;
      u_dRcmTrocar.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dRcmTrocar.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dRcmTrocar.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dRcmTrocar.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dRcmTrocar = u_dRcmTrocar.real;
      offset += sizeof(this->dRcmTrocar);
      union {
        float real;
        uint32_t base;
      } u_dRcmTip;
      u_dRcmTip.base = 0;
      u_dRcmTip.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dRcmTip.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dRcmTip.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dRcmTip.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dRcmTip = u_dRcmTip.real;
      offset += sizeof(this->dRcmTip);
      for( uint32_t i = 0; i < 7; i++){
      union {
        float real;
        uint32_t base;
      } u_currentJointsi;
      u_currentJointsi.base = 0;
      u_currentJointsi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_currentJointsi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_currentJointsi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_currentJointsi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->currentJoints[i] = u_currentJointsi.real;
      offset += sizeof(this->currentJoints[i]);
      }
      for( uint32_t i = 0; i < 7; i++){
      union {
        float real;
        uint32_t base;
      } u_ikJointsi;
      u_ikJointsi.base = 0;
      u_ikJointsi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ikJointsi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ikJointsi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ikJointsi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ikJoints[i] = u_ikJointsi.real;
      offset += sizeof(this->ikJoints[i]);
      }
      union {
        int8_t real;
        uint8_t base;
      } u_ikRes;
      u_ikRes.base = 0;
      u_ikRes.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ikRes = u_ikRes.real;
      offset += sizeof(this->ikRes);
      for( uint32_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_humanInputi;
      u_humanInputi.base = 0;
      u_humanInputi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_humanInputi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_humanInputi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_humanInputi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->humanInput[i] = u_humanInputi.real;
      offset += sizeof(this->humanInput[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_vdTooli;
      u_vdTooli.base = 0;
      u_vdTooli.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vdTooli.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vdTooli.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vdTooli.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vdTool[i] = u_vdTooli.real;
      offset += sizeof(this->vdTool[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_selfRotationCommand;
      u_selfRotationCommand.base = 0;
      u_selfRotationCommand.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_selfRotationCommand.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_selfRotationCommand.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_selfRotationCommand.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->selfRotationCommand = u_selfRotationCommand.real;
      offset += sizeof(this->selfRotationCommand);
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_currentOffsetFromInsertioni;
      u_currentOffsetFromInsertioni.base = 0;
      u_currentOffsetFromInsertioni.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_currentOffsetFromInsertioni.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_currentOffsetFromInsertioni.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_currentOffsetFromInsertioni.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->currentOffsetFromInsertion[i] = u_currentOffsetFromInsertioni.real;
      offset += sizeof(this->currentOffsetFromInsertion[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_ikOffsetFromInsertioni;
      u_ikOffsetFromInsertioni.base = 0;
      u_ikOffsetFromInsertioni.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ikOffsetFromInsertioni.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ikOffsetFromInsertioni.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ikOffsetFromInsertioni.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ikOffsetFromInsertion[i] = u_ikOffsetFromInsertioni.real;
      offset += sizeof(this->ikOffsetFromInsertion[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_desiredOffsetFromInsertioni;
      u_desiredOffsetFromInsertioni.base = 0;
      u_desiredOffsetFromInsertioni.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_desiredOffsetFromInsertioni.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_desiredOffsetFromInsertioni.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_desiredOffsetFromInsertioni.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->desiredOffsetFromInsertion[i] = u_desiredOffsetFromInsertioni.real;
      offset += sizeof(this->desiredOffsetFromInsertion[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_eeCollisionConstraintActive;
      u_eeCollisionConstraintActive.base = 0;
      u_eeCollisionConstraintActive.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->eeCollisionConstraintActive = u_eeCollisionConstraintActive.real;
      offset += sizeof(this->eeCollisionConstraintActive);
      union {
        float real;
        uint32_t base;
      } u_dEEEE;
      u_dEEEE.base = 0;
      u_dEEEE.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dEEEE.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dEEEE.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dEEEE.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dEEEE = u_dEEEE.real;
      offset += sizeof(this->dEEEE);
      union {
        bool real;
        uint8_t base;
      } u_toolCollisionConstraintActive;
      u_toolCollisionConstraintActive.base = 0;
      u_toolCollisionConstraintActive.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->toolCollisionConstraintActive = u_toolCollisionConstraintActive.real;
      offset += sizeof(this->toolCollisionConstraintActive);
      union {
        float real;
        uint32_t base;
      } u_dToolTool;
      u_dToolTool.base = 0;
      u_dToolTool.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dToolTool.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dToolTool.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dToolTool.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dToolTool = u_dToolTool.real;
      offset += sizeof(this->dToolTool);
      union {
        bool real;
        uint8_t base;
      } u_workspaceCollisionConstraintActive;
      u_workspaceCollisionConstraintActive.base = 0;
      u_workspaceCollisionConstraintActive.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->workspaceCollisionConstraintActive = u_workspaceCollisionConstraintActive.real;
      offset += sizeof(this->workspaceCollisionConstraintActive);
      union {
        bool real;
        uint8_t base;
      } u_minimumInsertionConstraintActive;
      u_minimumInsertionConstraintActive.base = 0;
      u_minimumInsertionConstraintActive.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->minimumInsertionConstraintActive = u_minimumInsertionConstraintActive.real;
      offset += sizeof(this->minimumInsertionConstraintActive);
      union {
        float real;
        uint32_t base;
      } u_desiredGripperPosition;
      u_desiredGripperPosition.base = 0;
      u_desiredGripperPosition.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_desiredGripperPosition.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_desiredGripperPosition.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_desiredGripperPosition.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->desiredGripperPosition = u_desiredGripperPosition.real;
      offset += sizeof(this->desiredGripperPosition);
      union {
        float real;
        uint32_t base;
      } u_tankH;
      u_tankH.base = 0;
      u_tankH.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tankH.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tankH.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tankH.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tankH = u_tankH.real;
      offset += sizeof(this->tankH);
      union {
        float real;
        uint32_t base;
      } u_alphaH;
      u_alphaH.base = 0;
      u_alphaH.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_alphaH.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_alphaH.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_alphaH.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->alphaH = u_alphaH.real;
      offset += sizeof(this->alphaH);
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_Fexti;
      u_Fexti.base = 0;
      u_Fexti.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Fexti.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Fexti.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Fexti.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Fext[i] = u_Fexti.real;
      offset += sizeof(this->Fext[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_Fmi;
      u_Fmi.base = 0;
      u_Fmi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Fmi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Fmi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Fmi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Fm[i] = u_Fmi.real;
      offset += sizeof(this->Fm[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_Fhi;
      u_Fhi.base = 0;
      u_Fhi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Fhi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Fhi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Fhi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Fh[i] = u_Fhi.real;
      offset += sizeof(this->Fh[i]);
      }
     return offset;
    }

    virtual const char * getType() override { return "surgical_task/RobotStateMsg"; };
    virtual const char * getMD5() override { return "df32c195b70b16b44e3d4e6293bb7011"; };

  };

}
#endif
