#include "UnitVector.hpp"

UnitVector::UnitVector(const Vector& vector) {
  double norm = vector.norm();
  this->x = vector.get_x() / norm;
  this->y = vector.get_y() / norm;
  this->z = vector.get_z() / norm;
}

UnitVector::UnitVector(double x, double y, double z) {
  Vector vector = Vector(x, y, z);
  double norm = vector.norm();
  this->x = vector.get_x() / norm;
  this->y = vector.get_y() / norm;
  this->z = vector.get_z() / norm;
}

UnitVector UnitVector::operator-() const {
  return UnitVector(-x, -y, -z);
}
