#include "Point.hpp"
#include "Utils.hpp"

Point::Point(rt::vector position) :
  position(position) {
}

Point::Point(double a, double b, double c) :
  position(rt::vector(a, b, c)) {
}

Point::Point() :
  position(rt::vector()) {
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

std::ostream &operator<<(std::ostream &os, const Point &point) {
  return os << "Point(" << point.position << ")";
}
