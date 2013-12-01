#ifndef __RECTANGLE_H
#define __RECTANGLE_H

#include "vector.hpp"
#include "Ray.hpp"
#include "Object.hpp"
#include "Option.hpp"
#include "Plane.hpp"

class Rectangle : public Plane {
private:
  rt::vector x_direction;
  rt::vector y_direction;
  double width;
  double height;
public:
  Rectangle(const Point& origin, const rt::vector& x_direction, const rt::vector& y_direction, double width, double height, const Texture& texture);

  Rectangle* clone() const;

  Option<double> get_distance_of_incidence_point_of(const Ray& ray);
};

#endif

