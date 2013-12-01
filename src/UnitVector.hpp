#ifndef UNIT_VECTOR_H
#define UNIT_VECTOR_H

#include "Vector.hpp"

class UnitVector : public Vector {
  public:
    UnitVector(const Vector& vector);
    UnitVector(const UnitVector& vector);
    UnitVector(double x, double y, double z);

  UnitVector operator-() const;
  Vector operator-(const UnitVector& other) const;
};

#endif
