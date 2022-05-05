#ifndef _ROS_SERVICE_ActorAction_h
#define _ROS_SERVICE_ActorAction_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Bool.h"
#include "std_msgs/Int16.h"

namespace surgical_system_service_manager
{

static const char ACTORACTION[] = "surgical_system_service_manager/ActorAction";

  class ActorActionRequest : public ros::Msg
  {
    public:
      typedef std_msgs::Int16 _actor_type;
      _actor_type actor;
      typedef std_msgs::Int16 _action_type;
      _action_type action;

    ActorActionRequest():
      actor(),
      action()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->actor.serialize(outbuffer + offset);
      offset += this->action.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->actor.deserialize(inbuffer + offset);
      offset += this->action.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return ACTORACTION; };
    virtual const char * getMD5() override { return "dacd8dd9c5de1a771187cc4c38dc73be"; };

  };

  class ActorActionResponse : public ros::Msg
  {
    public:
      typedef std_msgs::Bool _is_set_type;
      _is_set_type is_set;

    ActorActionResponse():
      is_set()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->is_set.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->is_set.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return ACTORACTION; };
    virtual const char * getMD5() override { return "66ff43df19dd120a86139c930e3f902d"; };

  };

  class ActorAction {
    public:
    typedef ActorActionRequest Request;
    typedef ActorActionResponse Response;
  };

}
#endif
