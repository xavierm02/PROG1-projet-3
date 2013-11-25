#include <limits>

#include "Scene.hpp"

Scene::Scene(const rt::color& background) :
  background(background) {
}

void Scene::add_source(Source& source) {
  sources.push_back(source);
}

void Scene::add_object(Object& object) {
  Object *copy = object.clone();
  objects.push_back(copy);
}

/*std::vector<Source>::const_iterator Scene::get_sources_iterator() const {
  return sources.begin();
}

std::vector<Object*>::const_iterator Scene::get_objects_iterator() {
  return objects.begin();
}*/

// todo detect blocked light faster by stopping at first item in between

const Option< std::pair<Object*, Point> > Scene::get_incidence_point_of(const Ray& ray) const {

  double minimal_distance = std::numeric_limits<double>::infinity();
  Object *closest_intersected_object = 0;

  for (std::vector<Object*>::const_iterator it = objects.begin(); it != objects.end(); ++it) {
    Option<double> distance = (*it)->get_distance_of_incidence_point_of(ray);
    if (distance.is_defined()) {
      if (distance.get_value() < minimal_distance) {
        minimal_distance = distance.get_value();
        closest_intersected_object = *it;
      }
    }
  }
  if (closest_intersected_object == 0) {
    return Option< std::pair<Object*, Point> >(false, std::pair<Object*, Point>());
  }
  return Option< std::pair<Object*, Point> >( std::pair<Object*, Point>(closest_intersected_object, ray.get_origin() + minimal_distance * ray.get_direction()));
}

rt::color Scene::determine_color(const Ray& ray) const {
  const Option< std::pair<Object*, Point> > result = this->get_incidence_point_of(ray);
  if (! result.is_defined()) {
    return background;
  }
  std::vector< std::pair<Ray,double> > rays;/*
  rt::vector normal = this -> get_normal_vector_at(point);
  rt::vector direction = ray.get_direction();
  rt::vector normal_component = (direction|normal) * normal;
  rt::vector
  Ray reflection = Ray(point, 2*(ray.get_direction)
  rays.push_back(std::pair())*/
  return rt::color::BLUE;//object->get_color();
}
