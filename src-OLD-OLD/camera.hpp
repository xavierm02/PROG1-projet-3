#ifndef __CAMERA_H
#define __CAMERA_H

#include "vector.hpp"
#include "image.hpp"

class camera {
  private:
    rt::vector _origin;
    rt::vector _direction;
    rt::vector _up;
    rt::image _image;
    double _distance;
  public:// CAMERA A RIEN A FOUTRE DANS SCENE
    camera(const rt::vector& origin, const rt::vector& direction, const rt::vector& up, const rt::image& image, double distance);
    void update_image();
};

#endif

