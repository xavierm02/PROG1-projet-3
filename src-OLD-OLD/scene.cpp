#include "scene.hpp"

#include "vector.hpp"
#include "camera.hpp"
#include "object.hpp"

#include <iostream>
#include <vector>

void scene::add_source(source source) {
  _sources.push_back(source);
}

void scene::add_object(object object) {
  _objects.push_back(object);
}

int scene::nb_sources() {
  return _sources.size();
}

int scene::nb_objects() {
  return _objects.size();
}

source scene::get_source(int i) {
  return _sources[i];
}

object scene::get_object(int i) {
  return _objects[i];
}

bool scene::empty_object() {
  return _objects.empty();
}



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
/*
rt::color scene::choose_color(rt::vector p, object obj) { //depend pas du rayon : premiere version



*/
