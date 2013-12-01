#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "vector.hpp"

class Point {
  private:
    rt::vector position;

  public:
    Point(double a, double b, double c);
    Point();

    static Point of_vector(rt::vector vector);

    bool operator==(const Point& other) const;

    rt::vector operator-(const Point& other) const;

    Point operator+(const rt::vector& other) const;

    Point operator-(const rt::vector& other) const;

    friend std::ostream &operator<<(std::ostream &os, const Point &point);
};

#endif
