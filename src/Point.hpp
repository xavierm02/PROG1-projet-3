#ifndef POINT_H
#define POINT_H

#include "vector.hpp"

class Point {
  private:
    rt::vector position;

  public:
    Point(rt::vector position);

    bool operator==(const Point& other) const;

    rt::vector operator-(const Point& other) const;

    Point operator+(const rt::vector& other) const;

    Point operator-(const rt::vector& other) const;
};

#endif
