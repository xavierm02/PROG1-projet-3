#include "Scene.hpp"

void Scene::add_source(Source& source) {
  sources.push_back(source);
}

void Scene::add_object(Object& object) {
  Object *copy = object.clone();
  objects.push_back(copy);
}

std::vector<Source>::const_iterator Scene::get_sources_iterator() const {
  return sources.begin();
}

std::vector<Object*>::const_iterator Scene::get_objects_iterator() {
  return objects.begin();
}
/*
bool scene::does_intersect(ray ray) {

  bool b(false);

  unsigned int i;

  for (i=0; i< _objects.size(); i++)
  {
    object obj = _objects[i];

    if (obj.does_intersect(ray))
    {
      b = true;
    }
  }
  return b;
}

object scene::first_object(ray ray) {

  double dist_mini = -1;

  object closest(object::DEFAULT);
  unsigned int i;

  for (i=0; i<_objects.size(); i++)
  {
    object obj = _objects[i];

    if (obj.does_intersect(ray))
    {
      if (obj.dist(ray) >= 0 && ((dist_mini == -1)||(obj.dist(ray) < dist_mini && (dist_mini != -1) )))
      {
        dist_mini = obj.dist(ray);
        closest = obj;
      }
    }
  }
  return closest;
}
rt::color scene::choose_color(rt::vector p, object obj) { //depend pas du rayon : premiere version



*/
