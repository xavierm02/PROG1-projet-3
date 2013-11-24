#ifndef __PLANE_H
#define __PLANE_H

#include "vector.hpp"
#include "Ray.hpp"
#include "Object.hpp"
#include "Option.hpp"

class Plane : public Object {
private:
  rt::vector normal_vector;
  Point origin;
public:
  Plane(const Point& origin, const rt::vector& normal_vector);

  Plane* clone() const;

  rt::vector get_normal_vector() const;
  Point get_origin() const;

  bool intersects(const Ray& ray, double *distance);
};

#endif
