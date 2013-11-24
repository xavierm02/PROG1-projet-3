#include <limits>

#include "Scene.hpp"

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

const Object* Scene::closest_intersected_object(const Ray& ray) const {

  double minimal_distance = std::numeric_limits<double>::infinity();
  Object *closest_intersected_object = 0;

  for (std::vector<Object*>::const_iterator it = objects.begin(); it != objects.end(); ++it) {
    double distance = 0;
    if ((*it)->intersects(ray, &distance)) {
      if (distance < minimal_distance) {
        minimal_distance = distance;
        closest_intersected_object = *it;
      }
    }
  }
  return closest_intersected_object;
}

rt::color Scene::determine_color(const Ray& ray) const {
  return rt::color::RED;
}
