#ifndef UNIT_VECTOR_H
#define UNIT_VECTOR_H

#include "Vector.hpp"

class UnitVector : public Vector {
  public:
    UnitVector(const Vector& vector);
};

#endif
