#include "Ray.hpp"

Ray::Ray(const Point& origin, const UnitVector& direction, unsigned int remaining_propagations):
  direction(UnitVector(direction)),
  origin(Point(origin)),
  remaining_propagations(remaining_propagations) {
}

UnitVector Ray::get_direction() const {
  return direction;
}

Point Ray::get_origin() const {
  return origin;
}

unsigned int Ray::get_remaining_propagations() const {
  return remaining_propagations;
}

std::ostream& operator<<(std::ostream &output_stream, const Ray& ray) {
  return output_stream << "Ray(" << ray.get_origin() << ", " << ray.get_direction() << ", " << ray.get_remaining_propagations() << ")";
}
