#include "UnitVector.hpp"

UnitVector::UnitVector(const Vector& vector) {
  double norm = vector.norm();
  this->x = vector.get_x() / norm;
  this->y = vector.get_y() / norm;
  this->z = vector.get_z() / norm;
}
