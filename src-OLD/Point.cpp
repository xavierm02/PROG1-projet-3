#include "Point.hpp"
#include "Utils.hpp"

Point::Point(double a, double b, double c) :
  position(rt::vector(a, b, c)) {
}

Point::Point() :
  position(rt::vector()) {
}

static Point of_vector(rt::vector vector) {
  return Point(vector.x, vector.y, vector.z);
}

bool Point::operator==(const Point& other) const {
  return position == other.position;
}

Point Point::operator+(const rt::vector& other) const {
  rt::vector vector = position + other;
  return Point(vector.x, vector.y, vector.z);
}

Point Point::operator-(const rt::vector& other) const {
  rt::vector vector = position - other;
  return Point(vector.x, vector.y, vector.z);
}

rt::vector Point::operator-(const Point& other) const {
  return position - other.position;
}

std::ostream &operator<<(std::ostream &os, const Point &point) {
  return os << "Point(" << point.position << ")";
}
