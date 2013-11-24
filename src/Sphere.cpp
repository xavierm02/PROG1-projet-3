#include <iostream>
#include <cmath>

#include "Sphere.hpp"

Sphere::Sphere(const rt::vector& center, double radius) :
  center(center), radius(radius) {
}

Sphere* Sphere::clone() const {
  return new Sphere(*this);
}

rt::vector Sphere::get_center() {
  return center;
}

double Sphere::get_radius() {
  return radius;
}

bool Sphere::intersects(Ray ray, double *distance) {

  rt::vector u = ray.get_direction();
  rt::vector v = center - ray.get_origin();

  //on cherche t tel que ||v-tu||² = Rayon²
  //mettre sous la forme at² + bt + c = 0


  double a = u|u;
  double b = -2*(u|v);
  double c = (v|v) - radius*radius;

  double delta = b*b - 4*a*c;

  if (delta <= 0) {
    // The ray des not intersect the sphere
    return false;
  }
  double x1 = (-1*b - std::sqrt(delta))/(2*a);
  double x2 = (-1*b + std::sqrt(delta))/(2*a);

  if (x2 <= 0) {
    // The ray isn't heading towards the sphere
    return false;
  }

  *distance = x1;
  return true;
}

/*
bool sphere::is_lighted(rt::vector p, source s) {

  rt::vector normal_vector = p - _center;
  return ( (normal_vector|(s.get_origin() - p)) > 0);
}

*/



