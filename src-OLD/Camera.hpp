#ifndef __CAMERA_H
#define __CAMERA_H

#include "image.hpp"
#include "vector.hpp"
#include "Point.hpp"
#include "Scene.hpp"

class Camera {
  private:
    unsigned int depth;
    rt::vector direction;
    double distance;
    rt::image image;
    Point origin;
    rt::vector up;
  public:
    Camera(const rt::image& image, const Point& origin, const rt::vector& direction, const rt::vector& up, double distance, const unsigned int depth);
    void render(const Scene& scene);
};

#endif

