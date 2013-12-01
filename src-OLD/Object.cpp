#include "color.hpp"

#include "Object.hpp"

Texture Object::get_texture() const {
  return texture;
}

Ray Object::get_reflected_ray(const Ray& ray, const Point& point) const {
  rt::vector normal = this->get_normal_vector_at(point);
  rt::vector direction = ray.get_direction();
  rt::vector normal_component = (direction|normal) * normal;
  rt::vector radial_component = direction - normal_component;
  return Ray(point, radial_component - normal_component, ray.get_propagations_left() - 1);
}

std::ostream& operator<<(std::ostream &os, const Object &object) {
  return object.print(os);
}
