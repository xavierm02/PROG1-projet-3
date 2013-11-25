#include <iostream>
#include <cmath>

#include "Sphere.hpp"
#include "Utils.hpp"

Sphere::Sphere(const Point& center, double radius, const Texture& texture) :
  center(center), radius(radius) {
  this->texture = texture;
}

Sphere* Sphere::clone() const {
  return new Sphere(*this);
}
	
Point Sphere::get_center() {
  return center;
}

double Sphere::get_radius() {
  return radius;
}

rt::vector Sphere::get_normal_vector_at(const Point& point) const {
  return (point - center).unit();
}

Option<double> Sphere::get_distance_of_incidence_point_of(const Ray& ray) {

  rt::vector u = ray.get_direction();
  rt::vector v = center - ray.get_origin();

  //on cherche t tel que ||v-tu||² = Rayon²
  //mettre sous la forme at² + bt + c = 0


  double a = u|u;
  double b = -2*(u|v);
  double c = (v|v) - radius*radius;

  double delta = b*b - 4*a*c;
  //std::cout << ray.get_direction() << "\n";
  if (delta <= 0) {
    // The ray does not intersect the sphere
    return Option<double>();
  }

  double x1 = (-1*b - std::sqrt(delta))/(2*a);
  double x2 = (-1*b + std::sqrt(delta))/(2*a);

  if (x2 <= 0) {
    // The ray isn't heading towards the sphere
    return Option<double>();
  }

  return Option<double>(x1);
}

std::ostream& Sphere::print(std::ostream &os) const {
  return os << "Sphere(" << center << ", " << radius << ")";
}

/*
bool sphere::is_lighted(rt::vector p, source s) {

  rt::vector normal_vector = p - _center;
  return ( (normal_vector|(s.get_origin() - p)) > 0);
}

*/



