#include "Point.hpp"

Point::Point():
  x(0.0),
  y(0.0),
  z(0.0) {
}

Point::Point(double x, double y, double z):
  x(x),
  y(y),
  z(z) {
}

double Point::get_x() const {
  return x;
}

double Point::get_y() const {
  return y;
}

double Point::get_z() const {
  return z;
}

Point Point::operator+(const Vector& vector) const {
  return Point(
    x + vector.get_x(),
    y + vector.get_y(),
    z + vector.get_z()
  );
}

Point Point::operator-(const Vector& vector) const {
  return Point(
    x - vector.get_x(),
    y - vector.get_y(),
    z - vector.get_z()
  );
}

Vector Point::operator-(const Point& point) const {
  return Vector(
    x - point.get_x(),
    y - point.get_y(),
    z - point.get_z()
  );
}

std::ostream& operator<<(std::ostream &output_stream, const Point& vector) {
  return output_stream << "(" << vector.get_x() << ", " << vector.get_y() << ", " << vector.get_z() << ")";
}
