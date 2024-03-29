#ifndef __PLANE_H
#define __PLANE_H

#include "vector.hpp"
#include "Ray.hpp"
#include "Object.hpp"
#include "Option.hpp"

class Plane : public Object {
protected:
  rt::vector normal_vector;
  Point origin;
public:
  Plane();
  Plane(const Point& origin, const rt::vector& normal_vector, const Texture& texture);

  Plane* clone() const;

  rt::vector get_normal_vector() const;
  Point get_origin() const;

  rt::vector get_normal_vector_at(const Point& point) const;

  Option<double> get_distance_of_incidence_point_of(const Ray& ray);

  std::ostream& print(std::ostream &os) const;
};

#endif
