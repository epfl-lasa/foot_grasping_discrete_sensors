#include "utils_functions.h"
#include "math.h"
float bound(float value, float lower, float upper){
    if (!isnan(value) && !isinf(value))
    {
      return value < lower ? lower : value > upper ? upper : value;
    }else {return 0.0f;}
}


float map(float x, float a, float b, float c, float d){
  
  if (d>c)
  {  
    return bound( ((x - a) * (d-c)/(b-a)) + c , c , d);
  } 
  else
  {
    return bound( ((x - a) * (d-c)/(b-a)) + c , d , c);
  }
}

