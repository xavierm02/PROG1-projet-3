#include "Rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(const Point& origin, const rt::vector& x_direction, const rt::vector& y_direction, double width, double height, const Texture& texture) :
  x_direction(x_direction), y_direction(y_direction), width(width), height(height) {
  this->normal_vector = x_direction ^ y_direction;
  this->origin = origin;
  this->texture = texture;
}

Rectangle* Rectangle::clone() const {
  return new Rectangle(*this);
}

Option<double> Rectangle::get_distance_of_incidence_point_of(const Ray& ray) {
  Option<double> result = Plane::get_distance_of_incidence_point_of(ray);
  if (! result.is_defined()) {
    return result;
  }
  Point point = ray.get_origin() + result.get_value() * ray.get_direction();
  if (abs((point - origin) | x_direction) >= width / 2) {
    return Option<double>();
  }
  if (abs((point - origin) | y_direction) >= height / 2) {
    return Option<double>();
  }
  return result;
}
