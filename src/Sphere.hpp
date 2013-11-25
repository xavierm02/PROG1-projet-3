#ifndef __SPHERE_H
#define __SPHERE_H

#include "vector.hpp"
#include "Ray.hpp"
#include "Object.hpp"

class Sphere : public Object {
private:
  Point center;
  double radius;

public:
  Sphere(const Point& center, double radius);
  Sphere* clone() const;

  Point get_center();
  double get_radius();

  Option<double> get_distance_of_incidence_point_of(const Ray& ray);

  rt::vector get_normal_vector_at(const Point& point) const;
};

#endif
