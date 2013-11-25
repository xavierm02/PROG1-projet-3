#include <iostream>
#include "scene.hpp"
#include "ray.hpp"
#include "object.hpp"

/*
bool is_lighted(object obj, rt::vector p, scene s) { // p : le point de l'objet obj dont on souhaite savoir s'il est éclairé par une des sources de la scene 

  int i,j;
  bool b;

  for (i=0; i < s.nb_sources(); i++)
  {
    ray ray(s.get_source(i).get_origin(), p - s.get_source(i).get_origin());
    b = true;

    for(j=0; j < s.nb_objects(); j++)
    {
      if (s.get_object(j).does_intersect(ray))
      {
        b = false;
      }
    }
    if (b) {return true;}
  }
  return false;
}

rt::color color_returned(object obj, rt::vector p, scene s) {
  if (is_lighted(object obj, rt::vector p, scene s)) {return (obj.get_color());}
  else {return rt::color::BLACK;}
}
*/

