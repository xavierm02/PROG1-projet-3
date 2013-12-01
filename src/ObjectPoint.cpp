#include "ObjectPoint.hpp"

ObjectPoint::ObjectPoint(std::shared_ptr<Object> object, const Point& point):
  object(object) {
  this->x = point.get_x();
  this->y = point.get_y();
  this->z = point.get_z();
}

std::shared_ptr<Object> ObjectPoint::get_object() const {
  return object;
}
