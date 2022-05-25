#ifndef _ROS_SERVICE_FirmwareUpdateEthercat_h
#define _ROS_SERVICE_FirmwareUpdateEthercat_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rokubimini_msgs
{

static const char FIRMWAREUPDATEETHERCAT[] = "rokubimini_msgs/FirmwareUpdateEthercat";

  class FirmwareUpdateEthercatRequest : public ros::Msg
  {
    public:
      typedef const char* _file_name_type;
      _file_name_type file_name;
      typedef const char* _file_path_type;
      _file_path_type file_path;
      typedef uint32_t _password_type;
      _password_type password;

    FirmwareUpdateEthercatRequest():
      file_name(""),
      file_path(""),
      password(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_file_name = strlen(this->file_name);
      varToArr(outbuffer + offset, length_file_name);
      offset += 4;
      memcpy(outbuffer + offset, this->file_name, length_file_name);
      offset += length_file_name;
      uint32_t length_file_path = strlen(this->file_path);
      varToArr(outbuffer + offset, length_file_path);
      offset += 4;
      memcpy(outbuffer + offset, this->file_path, length_file_path);
      offset += length_file_path;
      *(outbuffer + offset + 0) = (this->password >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->password >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->password >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->password >> (8 * 3)) & 0xFF;
      offset += sizeof(this->password);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_file_name;
      arrToVar(length_file_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file_name-1]=0;
      this->file_name = (char *)(inbuffer + offset-1);
      offset += length_file_name;
      uint32_t length_file_path;
      arrToVar(length_file_path, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file_path; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file_path-1]=0;
      this->file_path = (char *)(inbuffer + offset-1);
      offset += length_file_path;
      this->password =  ((uint32_t) (*(inbuffer + offset)));
      this->password |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->password |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->password |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->password);
     return offset;
    }

    virtual const char * getType() override { return FIRMWAREUPDATEETHERCAT; };
    virtual const char * getMD5() override { return "4057152a8f9029e0d6a6de4a64158492"; };

  };

  class FirmwareUpdateEthercatResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;

    FirmwareUpdateEthercatResponse():
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    virtual const char * getType() override { return FIRMWAREUPDATEETHERCAT; };
    virtual const char * getMD5() override { return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class FirmwareUpdateEthercat {
    public:
    typedef FirmwareUpdateEthercatRequest Request;
    typedef FirmwareUpdateEthercatResponse Response;
  };

}
#endif
