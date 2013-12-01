#ifndef __OBJECT_H
#define __OBJECT_H

#include "UnitVector.hpp"
#include "ObjectTexture.hpp"
#include "Ray.hpp"
#include "Option.hpp"
#include "Point.hpp"
#include <memory>

class Object {
protected:
  std::shared_ptr<ObjectTexture> texture;
  Object(std::shared_ptr<ObjectTexture> texture);
  Object(const ObjectTexture& texture);

public:
  virtual Object* clone() const = 0;

  std::shared_ptr<Object> wrap() const;

  std::shared_ptr<ObjectTexture> get_texture() const;

  virtual Option<double> get_distance_of_incidence_point_of(const Ray& ray) = 0;

  virtual UnitVector get_normal_vector_at(const Point& point) const = 0;

  Ray get_reflected_ray(const Ray& ray, const Point& point) const;

  virtual std::ostream& print(std::ostream &output_stream) const = 0;
};

std::ostream& operator<<(std::ostream &output_stream, const Object &object);

#endif
