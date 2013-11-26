#include "Rectangle.hpp"

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
  return Plane::get_distance_of_incidence_point_of(ray);
}
