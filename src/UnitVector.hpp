#ifndef UNIT_VECTOR_H
#define UNIT_VECTOR_H

#include "Vector.hpp"

class UnitVector : public Vector {
  public:
    UnitVector(const Vector& vector);
    UnitVector(const UnitVector& vector);
    UnitVector(double x, double y, double z);

    friend UnitVector operator-(const UnitVector& vector);
};

#endif
