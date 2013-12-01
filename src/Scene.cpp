#include <limits>

#include "Scene.hpp"
#include <iostream>
#include <cmath>
#include "Parameters.hpp"

Scene::Scene(const Light& background) :
  background(Light(background)) {
}

void Scene::add_source(const Source& source) {
  sources.push_back(Source(source));
}

void Scene::add_object(std::shared_ptr<Object> object) {
  objects.push_back(object);
}

void Scene::add_object(const Object& object) {
  add_object(object.wrap());
}

const std::vector<Source> Scene::get_sources() const {
  return sources;
}

const std::vector<std::shared_ptr<Object>> Scene::get_objects() const {
  return objects;
}

// todo detect blocked light faster by stopping at first item in between

const Option<ObjectPoint> Scene::get_incidence_point_of(const Ray& ray) const {

  double minimal_distance = std::numeric_limits<double>::infinity();
  std::shared_ptr<Object> closest_intersected_object = 0;

  for (std::vector<std::shared_ptr<Object>>::const_iterator it = objects.begin(); it != objects.end(); ++it) {
    Option<double> distance = (*it)->get_distance_of_incidence_point_of(ray);
    if (distance.is_defined()) {
      if (distance.get_value() < minimal_distance && distance.get_value() > EPSILON) {
        minimal_distance = distance.get_value();
        closest_intersected_object = *it;
      }
    }
  }
  if (!closest_intersected_object) {
    return Option<ObjectPoint>(false, ObjectPoint());
  }

  return Option<ObjectPoint>( ObjectPoint(closest_intersected_object, ray.get_origin() + minimal_distance * ray.get_direction()));
}

bool Scene::obstructs(const Point& beginning, const Point& end) const {
  Vector vector = end - beginning;
  Ray ray = Ray(beginning, vector, 0);
  for (std::vector<std::shared_ptr<Object>>::const_iterator it = objects.begin(); it != objects.end(); ++it) {
    Option<double> distance = (*it)->get_distance_of_incidence_point_of(ray);
    if (distance.is_defined()) {
      if (distance.get_value() > EPSILON && std::abs(distance.get_value() - vector.norm()) > EPSILON) {
        return true;
      }
    }
  }
  return false;
}

Light Scene::determine_light_from_sources_at(const Point& point, const UnitVector normal_vector) const {
  Light light = Light();
  for (std::vector<Source>::const_iterator it = sources.begin(); it != sources.end(); ++it) {
    if (! this->obstructs(it->get_origin(), point)) {
      light = light + std::abs(UnitVector(it->get_origin() - point) | normal_vector) * it->get_light();
    }
  }
  return light;
}

Light Scene::determine_light_of(const Ray& ray) const {
  const Option<ObjectPoint> result = this->get_incidence_point_of(ray);
  if (! result.is_defined()) {
    return Light(background);
  }
  ObjectPoint point = result.get_value();
  PointTexture texture = point.get_texture();
  unsigned int remaining_propagations = ray.get_remaining_propagations();
  //if (propagations_left == 0) {

  //}
  //std::vector< std::pair<Ray,double> > rays;

  //Ray reflection_ray = object.get_reflected_vector(...);
  //rt::color reflection_color = this->determine_color(reflection_ray);
  return (this->determine_light_from_sources_at(point, point.get_normal_vector()).reflect_on(texture.get_color()));
}
