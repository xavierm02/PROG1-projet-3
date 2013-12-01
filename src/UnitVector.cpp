#include "UnitVector.hpp"

UnitVector::UnitVector(const Vector& vector) : Vector(vector / vector.norm()) {
}

UnitVector::UnitVector(const UnitVector& vector) : Vector(vector) {
}

UnitVector::UnitVector(double x, double y, double z) : UnitVector(Vector(x, y, z)) {
}

UnitVector operator-(const UnitVector& vector) {
  return UnitVector(-vector.x, -vector.y, -vector.z);
}
