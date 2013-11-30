#include "Vector.hpp"

#include <cmath>

Vector::Vector():
  x(0.0),
  y(0.0),
  z(0.0) {
}

Vector::Vector(double x, double y, double z):
  x(x),
  y(y),
  z(z) {
}

double Vector::get_x() const {
  return x;
}

double Vector::get_y() const {
  return y;
}

double Vector::get_z() const {
  return z;
}

Vector Vector::operator-() const {
  return Vector(-x, -y, -z);
}

bool Vector::operator==(const Vector& other) const {
  return
    x == other.x &&
    y == other.y &&
    z == other.z;
}

Vector Vector::operator+(const Vector& other) const {
  return Vector(
    x + other.x,
    y + other.y,
    z + other.z
  );
}

Vector Vector::operator-(const Vector& other) const {
  return Vector(
    x - other.x,
    y - other.y,
    z - other.z
  );
}

Vector Vector::operator^(const Vector& other) const {
  return Vector(
    y*other.z - z*other.y,
    z*other.x - x*other.z,
    x*other.y - y*other.x
  );
}

double Vector::operator|(const Vector& other) const {
  return
    x * other.x +
    y * other.y +
    z * other.z;
}

double Vector::norm() const {
  return std::sqrt(x*x + y*y + z*z);
}

Vector operator*(double scalar, const Vector& vector) {
  return Vector(
    scalar * vector.get_x(),
    scalar * vector.get_y(),
    scalar * vector.get_z()
  );
}

Vector operator/(const Vector& vector, double scalar) {
  return Vector(
    vector.get_x() / scalar,
    vector.get_y() / scalar,
    vector.get_z() / scalar
  );
}
