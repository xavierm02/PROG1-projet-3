#ifndef __RAY_H
#define __RAY_H

#include <iostream>
#include "UnitVector.hpp"
#include "Point.hpp"

class Ray {
  private:
    UnitVector direction;
    Point origin;
    unsigned int remaining_propagations;

  public:
    Ray(const Point& origin, const UnitVector& direction, unsigned int remaining_propagations);

    UnitVector get_direction() const;
    Point get_origin() const;
    unsigned int get_remaining_propagations() const;
};

std::ostream& operator<<(std::ostream &output_stream, const Ray& ray);

#endif
