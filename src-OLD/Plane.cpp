#include <cmath>

#include "Plane.hpp"
#include "Parameters.hpp"
#include "Utils.hpp"
#include <cmath>

Plane::Plane() :
  normal_vector(rt::vector()), origin(Point()) {
}

Plane::Plane(const Point& origin, const rt::vector& normal_vector, const Texture& texture) :
  normal_vector(normal_vector.unit()), origin(origin) {
  this->texture = texture;
}

Plane* Plane::clone() const {
  return new Plane(*this);
}

rt::vector Plane::get_normal_vector() const {
  return normal_vector;
}

Point Plane::get_origin() const {
  return origin;
}

rt::vector Plane::get_normal_vector_at(const Point& /*point*/) const {
  return normal_vector;
}

Option<double> Plane::get_distance_of_incidence_point_of(const Ray& ray) {
    if (std::abs(ray.get_direction() | normal_vector) < EPSILON) {
      // The ray is parallel to the plane
      return Option<double>();
    }
    double a = (origin - ray.get_origin()) | normal_vector;
    double b = ray.get_direction() | normal_vector;
    if (std::signbit(a) != std::signbit(b)) {
      // The ray isn't heading towards the plane
      return Option<double>();
    }
    return Option<double>(a / b);
}

std::ostream& Plane::print(std::ostream &os) const {
  return os << "Plane(" << origin << ", " << normal_vector << ")";
}
