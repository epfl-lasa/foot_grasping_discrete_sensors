#include <Arduino.h>
#include "ros.h"
#include "ros/publisher.h"
#include "std_msgs/Int8.h"
#include "std_msgs/Int16.h"
#include "LP_Filter.h"
#include "Button_Sensor.h"
#include "FSR_Sensor.h"

void getParamsFSR(gripperLaterality id);