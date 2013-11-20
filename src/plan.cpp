#include "object.hpp"
#include "sphere.hpp"
#include "vector.hpp"
#include "color.hpp"
#include "ray.hpp"
#include <iostream>

#include "plan.hpp"


rt::vector plan::get_origin() {
	return _origin;
}

void plan::set_origin(rt::vector o) {
	_origin = o;
}

rt::vector plan::get_normal_vector() {
	return _normal_vector;
}

void plan::set_normal_vector(rt::vector n) {
	_normal_vector = n;
}

bool plan::does_intersect(ray r) {
    if ( (r.get_direction()|_normal_vector)==0)
    {
      return false; //rayon parallèle au plan
    }
    else
    {
      double t = ( (_origin|_normal_vector)-(r.get_origin()|_normal_vector) )/(r.get_direction()|_normal_vector);

      if (t <= 0)
      {
        return false; // plan derrière la caméra
      }
      else
      {
        return true;
      }
    }
}

rt::vector plan::intersection(ray r) {

    double t = ( (_origin|_normal_vector)-(r.get_origin()|_normal_vector) )/(r.get_direction()|_normal_vector);
	return (r.get_origin()+(t*r.get_direction()));
}

double plan::dist(ray r) {
    double t = ( (_origin|_normal_vector)-(r.get_origin()|_normal_vector) )/(r.get_direction().unit()|_normal_vector);
	return t;
}







