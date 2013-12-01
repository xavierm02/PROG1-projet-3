#include "ObjectPoint.hpp"

ObjectPoint::ObjectPoint():
  Point(),
  object(std::shared_ptr<Object>()) {
}

ObjectPoint::ObjectPoint(std::shared_ptr<Object> object, const Point& point):
  Point(point),
  object(object) {
}

ObjectPoint::ObjectPoint(const Object& object, const Point& point):
  ObjectPoint(object.wrap(), point) {
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
