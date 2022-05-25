#include "aux.h"

extern FSR_Sensor fsrSensors[];
extern ros::NodeHandle nh;
const char *gripperNames[] = {"right","left"};

void getParamsFSR(gripperLaterality id)
{
  static char msg [100];

  sprintf(msg,"/%s/foot_grasping/fsr_threshold_low", gripperNames[id]);
  if (!nh.getParam(msg, &fsrSensors[id]._fsrThreshold_low,1)) {
    sprintf(msg,"no %s fsr_threshold_low param found", gripperNames[id]);
    nh.logerror(msg);
  }else{
    sprintf(msg,"%s fsr_threshold_low %d param loaded", gripperNames[id], fsrSensors[id]._fsrThreshold_low);
    nh.loginfo(msg);
  }

 sprintf(msg,"/%s/foot_grasping/fsr_threshold_up", gripperNames[id]);
  if (!nh.getParam(msg, &fsrSensors[id]._fsrThreshold_up,1)) {
    sprintf(msg,"no %s fsr_threshold_up param found", gripperNames[id]);
    nh.logerror(msg);
  }else{
    sprintf(msg,"%s fsr_threshold_up %d param loaded", gripperNames[id], fsrSensors[id]._fsrThreshold_up);
    nh.loginfo(msg);
  }
  
}