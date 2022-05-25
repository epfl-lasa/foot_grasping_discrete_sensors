#ifndef _ROS_surgical_task_TaskManagerStateMsg_h
#define _ROS_surgical_task_TaskManagerStateMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace surgical_task
{

  class TaskManagerStateMsg : public ros::Msg
  {
    public:
      typedef bool _start_type;
      _start_type start;
      typedef int16_t _taskId_type;
      _taskId_type taskId;
      typedef int16_t _toolToReach_type;
      _toolToReach_type toolToReach;
      typedef bool _toolReached_type;
      _toolReached_type toolReached;
      typedef bool _finished_type;
      _finished_type finished;
      typedef bool _stopTime_type;
      _stopTime_type stopTime;
      typedef int16_t _imageId_type;
      _imageId_type imageId;

    TaskManagerStateMsg():
      start(0),
      taskId(0),
      toolToReach(0),
      toolReached(0),
      finished(0),
      stopTime(0),
      imageId(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_start;
      u_start.real = this->start;
      *(outbuffer + offset + 0) = (u_start.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->start);
      union {
        int16_t real;
        uint16_t base;
      } u_taskId;
      u_taskId.real = this->taskId;
      *(outbuffer + offset + 0) = (u_taskId.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_taskId.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->taskId);
      union {
        int16_t real;
        uint16_t base;
      } u_toolToReach;
      u_toolToReach.real = this->toolToReach;
      *(outbuffer + offset + 0) = (u_toolToReach.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_toolToReach.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->toolToReach);
      union {
        bool real;
        uint8_t base;
      } u_toolReached;
      u_toolReached.real = this->toolReached;
      *(outbuffer + offset + 0) = (u_toolReached.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->toolReached);
      union {
        bool real;
        uint8_t base;
      } u_finished;
      u_finished.real = this->finished;
      *(outbuffer + offset + 0) = (u_finished.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->finished);
      union {
        bool real;
        uint8_t base;
      } u_stopTime;
      u_stopTime.real = this->stopTime;
      *(outbuffer + offset + 0) = (u_stopTime.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->stopTime);
      union {
        int16_t real;
        uint16_t base;
      } u_imageId;
      u_imageId.real = this->imageId;
      *(outbuffer + offset + 0) = (u_imageId.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_imageId.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->imageId);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_start;
      u_start.base = 0;
      u_start.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->start = u_start.real;
      offset += sizeof(this->start);
      union {
        int16_t real;
        uint16_t base;
      } u_taskId;
      u_taskId.base = 0;
      u_taskId.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_taskId.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->taskId = u_taskId.real;
      offset += sizeof(this->taskId);
      union {
        int16_t real;
        uint16_t base;
      } u_toolToReach;
      u_toolToReach.base = 0;
      u_toolToReach.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_toolToReach.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->toolToReach = u_toolToReach.real;
      offset += sizeof(this->toolToReach);
      union {
        bool real;
        uint8_t base;
      } u_toolReached;
      u_toolReached.base = 0;
      u_toolReached.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->toolReached = u_toolReached.real;
      offset += sizeof(this->toolReached);
      union {
        bool real;
        uint8_t base;
      } u_finished;
      u_finished.base = 0;
      u_finished.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->finished = u_finished.real;
      offset += sizeof(this->finished);
      union {
        bool real;
        uint8_t base;
      } u_stopTime;
      u_stopTime.base = 0;
      u_stopTime.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->stopTime = u_stopTime.real;
      offset += sizeof(this->stopTime);
      union {
        int16_t real;
        uint16_t base;
      } u_imageId;
      u_imageId.base = 0;
      u_imageId.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_imageId.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->imageId = u_imageId.real;
      offset += sizeof(this->imageId);
     return offset;
    }

    virtual const char * getType() override { return "surgical_task/TaskManagerStateMsg"; };
    virtual const char * getMD5() override { return "9ee108c874e4f6e8b080e872fdf0db19"; };

  };

}
#endif
