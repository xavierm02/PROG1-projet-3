#include "Point.hpp"

Point::Point(rt::vector position) :
  position(position) {
}

bool Point::operator==(const Point& other) const {
  return position == other.position;
}

Point Point::operator+(const rt::vector& other) const {
  return Point(position + other);
}

Point Point::operator-(const rt::vector& other) const {
  return Point(position - other);
}

rt::vector Point::operator-(const Point& other) const {
  return position - other.position;
}
