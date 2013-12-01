#ifndef __SOURCE_H
#define __SOURCE_H

#include "Vector.hpp"
#include "rt/color.hpp"
#include "Point.hpp"
#include "Ray.hpp"
#include "Light.hpp"

class Source {
  private:
    Light light;
    Point origin;

  public:
    Source(const Point& origin, const Light& light);

    Light get_light() const;
    Point get_origin() const;

    Ray send_ray_towards(const Point& point) const;
};

#endif
