#ifndef _ROS_r2p_Velocity_h
#define _ROS_r2p_Velocity_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace r2p
{

  class Velocity : public ros::Msg
  {
    public:
      float x;
      float y;
      float w;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_w;
      u_w.real = this->w;
      *(outbuffer + offset + 0) = (u_w.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_w.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_w.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_w.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->w);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_w;
      u_w.base = 0;
      u_w.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_w.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_w.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_w.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->w = u_w.real;
      offset += sizeof(this->w);
     return offset;
    }

    const char * getType(){ return "r2p/Velocity"; };
    const char * getMD5(){ return "fc16a6b45aaa44f2dd9023be467748ee"; };

  };

}
#endif