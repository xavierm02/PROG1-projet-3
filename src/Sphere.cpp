#include <iostream>
#include <cmath>

#include "Sphere.hpp"

Sphere::Sphere(const Point& center, double radius, const ObjectTexture& texture) :
  center(Point(center)), radius(radius) {
  this->texture = texture.wrap();
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

UnitVector Sphere::get_normal_vector_at(const Point& point) const {
  return UnitVector(point - center);
}

Option<double> Sphere::get_distance_of_incidence_point_of(const Ray& ray) {

  UnitVector u = ray.get_direction();
  Vector v = center - ray.get_origin();

  //on cherche t tel que ||v-tu||² = Rayon²
  //mettre sous la forme at² + bt + c = 0


  double a = u|u;
  double b = -2*(u|v);
  double c = (v|v) - radius*radius;

  double delta = b*b - 4*a*c;

  if (delta <= 0) {
    // The ray does not intersect the sphere
    return Option<double>();
  }

  double x1 = (-b - std::sqrt(delta))/(2*a);
  double x2 = (-b + std::sqrt(delta))/(2*a);

  if (x2 <= 0) {

    // The ray isn't heading towards the sphere
    return Option<double>();
  }

  if (x1 <= 0) {
    // The origin of the ray is in the sphere
    return Option<double>(x2);
  }

  return Option<double>(x1);
}

std::ostream& Sphere::print(std::ostream &output_stream) const {
  return output_stream << "Sphere(" << center << ", " << radius << ")";
}
