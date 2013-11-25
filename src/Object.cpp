#include "color.hpp"

#include "Object.hpp"

Texture Object::get_texture() const {
  return texture;
}

std::vector<std::pair<Ray,double> > Object::propagate_ray(const Ray& ray, const Point& point) const {
  std::vector<std::pair<Ray,double> > rays;/*
  rt::vector normal = this -> get_normal_vector_at(point);
  rt::vector direction = ray.get_direction();
  rt::vector normal_component = (direction|normal) * normal;
  rt::vector
  Ray reflection = Ray(point, 2*(ray.get_direction)
  rays.push_back(std::pair())*/
  return rays;
}
