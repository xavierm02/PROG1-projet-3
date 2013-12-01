#ifndef __CAMERA_H
#define __CAMERA_H

#include "rt/image.hpp"
#include "UnitVector.hpp"
#include "Point.hpp"
#include "Scene.hpp"

class Camera {
  private:
    unsigned int depth;
    UnitVector direction;
    double distance;
    rt::image image;
    Point origin;
    UnitVector up;
  public:
    Camera(const rt::image& image, const Point& origin, const UnitVector& direction, const UnitVector& up, double distance, const unsigned int depth);
    void render(const Scene& scene);
};

#endif

