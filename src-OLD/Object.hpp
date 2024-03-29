#ifndef __OBJECT_H
#define __OBJECT_H

#include <vector>
#include "vector.hpp"
#include "Texture.hpp"
#include "Ray.hpp"
#include "Option.hpp"
#include "Point.hpp"

class Object {
protected:
  Texture texture;

public:
  virtual Object* clone() const = 0;

  Texture get_texture() const;

  virtual Option<double> get_distance_of_incidence_point_of(const Ray& ray) = 0;

  virtual rt::vector get_normal_vector_at(const Point& point) const = 0;

  Ray get_reflected_ray(const Ray& ray, const Point& point) const;

  virtual std::ostream& print(std::ostream &os) const = 0;
};

std::ostream& operator<<(std::ostream &os, const Object &object);

#endif
