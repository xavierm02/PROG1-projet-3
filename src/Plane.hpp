#ifndef __PLANE_H
#define __PLANE_H

#include "UnitVector.hpp"
#include "Ray.hpp"
#include "Object.hpp"
#include "Option.hpp"

class Plane: public Object {
protected:
  UnitVector normal_vector;
  Point origin;
public:
  Plane(const Point& origin, const UnitVector& normal_vector, const ObjectTexture& texture);

  std::shared_ptr<Object> clone() const;

  UnitVector get_normal_vector() const;
  Point get_origin() const;

  UnitVector get_normal_vector_at(const Point& point) const;

  Option<double> get_distance_of_incidence_point_of(const Ray& ray);

  std::ostream& print(std::ostream &output_stream) const;
};

#endif
