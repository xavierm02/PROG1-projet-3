#include <limits>

#include "Scene.hpp"
#include "Texture.hpp"
#include <iostream>
#include <cmath>
#include "Parameters.hpp"

Scene::Scene(const rt::color& background) :
  background(background) {
}

void Scene::add_source(const Source& source) {
  sources.push_back(source);
}

void Scene::add_object(const Object& object) {
  Object *copy = object.clone();
  objects.push_back(copy);
}

const std::vector<Source> Scene::get_sources() const {
  return sources;
}

const std::vector<Object*> Scene::get_objects() const {
  return objects;
}

// todo detect blocked light faster by stopping at first item in between

const Option< std::pair<Object*, Point> > Scene::get_incidence_point_of(const Ray& ray) const {

  double minimal_distance = std::numeric_limits<double>::infinity();
  Object *closest_intersected_object = 0;

  for (std::vector<Object*>::const_iterator it = objects.begin(); it != objects.end(); ++it) {
    Option<double> distance = (*it)->get_distance_of_incidence_point_of(ray);
    if (distance.is_defined()) {
      if (distance.get_value() < minimal_distance && distance.get_value() > EPSILON) {
        minimal_distance = distance.get_value();
        closest_intersected_object = *it;
      }
    }
  }
  if (closest_intersected_object == 0) {
    return Option< std::pair<Object*, Point> >(false, std::pair<Object*, Point>());
  }

  //std::cout << ray.get_origin() + (1/(ray.get_direction() | rt::vector(1,0,0))) * ray.get_direction() << "   " << minimal_distance << "\n";
  return Option< std::pair<Object*, Point> >( std::pair<Object*, Point>(closest_intersected_object, ray.get_origin() + minimal_distance * ray.get_direction()));
}

bool Scene::obstructs(const Point& beginning, const Point& end) const {
  rt::vector vector = end - beginning;
  Ray ray = Ray(beginning, vector, 0);
  for (std::vector<Object*>::const_iterator it = objects.begin(); it != objects.end(); ++it) {
    Option<double> distance = (*it)->get_distance_of_incidence_point_of(ray);
    if (distance.is_defined()) {
      if (distance.get_value() > EPSILON && std::abs(distance.get_value() - vector.norm()) > EPSILON) {
        return true;
      }
    }
  }
  return false;
}

Light Scene::determine_light_from_sources_at(const Point& point, const rt::vector normal_vector) const {
  Light light = Light();
  for (std::vector<Source>::const_iterator it = sources.begin(); it != sources.end(); ++it) {
    if (! this->obstructs(it->get_origin(), point)) {
      light = light + std::abs((it->get_origin() - point).unit() | normal_vector) * it->get_light();
    }
  }
  return light;
}

Light Scene::determine_light_of(const Ray& ray) const {
  const Option< std::pair<Object*, Point> > result = this->get_incidence_point_of(ray);
  if (! result.is_defined()) {
    return Light(background);
  }
  std::pair<Object*, Point> pair = result.get_value();
  Object *object = pair.first;
  Point point = pair.second;
  Texture texture = object->get_texture();
  unsigned int propagations_left = ray.get_propagations_left();
  //if (propagations_left == 0) {

  //}
  //std::vector< std::pair<Ray,double> > rays;

  //Ray reflection_ray = object.get_reflected_vector(...);
  //rt::color reflection_color = this->determine_color(reflection_ray);
  return (texture.get_color() ^ this->determine_light_from_sources_at(point, object->get_normal_vector_at(point)));
}
