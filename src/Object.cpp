#include "Object.hpp"

Object::Object(std::shared_ptr<ObjectTexture> texture):
  texture(texture) {
}

Object::Object(const ObjectTexture& texture):
  Object(texture.wrap()) {
}

std::shared_ptr<Object> Object::wrap() const {
  return std::shared_ptr<Object>(this->clone());
}

std::shared_ptr<ObjectTexture> Object::get_texture() const {
  return texture;
}

Ray Object::get_reflected_ray(const Ray& ray, const Point& point) const {
  UnitVector normal = this->get_normal_vector_at(point);
  UnitVector direction = ray.get_direction();
  Vector normal_component = (direction|normal) * normal;
  Vector radial_component = direction - normal_component;
  return Ray(point, radial_component - normal_component, ray.get_remaining_propagations() - 1);
}

std::ostream& operator<<(std::ostream &output_stream, const Object &object) {
  return object.print(output_stream);
}
