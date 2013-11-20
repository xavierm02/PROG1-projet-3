#ifndef __CAMERA_H
#define __CAMERA_H

#include "vector.hpp"

class camera {
  private:
    rt::vector _origin;
    rt::vector _direction;
  public:
    camera(const rt::vector& origin, const rt::vector& direction);
};

#endif

