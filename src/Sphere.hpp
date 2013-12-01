#ifndef __SPHERE_H
#define __SPHERE_H

#include <iostream>
#include "Vector.hpp"
#include "Ray.hpp"
#include "Object.hpp"
#include <memory>

class Sphere: public Object {
private:
  Point center;
  double radius;

public:
  Sphere(const Point& center, double radius, const ObjectTexture& texture);
  std::shared_ptr<Object> clone() const;

  Point get_center();
  double get_radius();

  Option<double> get_distance_of_incidence_point_of(const Ray& ray);

  UnitVector get_normal_vector_at(const Point& point) const;

  std::ostream& print(std::ostream &output_stream) const;
};

#endif
