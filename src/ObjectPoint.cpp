#include "ObjectPoint.hpp"

ObjectPoint::ObjectPoint():
  object(std::shared_ptr<Object>()) {
  this->x = 0.0;
  this->y = 0.0;
  this->z = 0.0;
}

ObjectPoint::ObjectPoint(std::shared_ptr<Object> object, const Point& point):
  object(object) {
  this->x = point.get_x();
  this->y = point.get_y();
  this->z = point.get_z();
}

std::shared_ptr<Object> ObjectPoint::get_object() const {
  return object;
}

PointTexture ObjectPoint::get_texture() const {
  return object->get_texture()->get_point_texture_at(*this);
}

UnitVector ObjectPoint::get_normal_vector() const {
  return object->get_normal_vector_at(*this);
}
