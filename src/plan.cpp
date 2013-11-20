#include "object.hpp"
#include "sphere.hpp"
#include "vector.hpp"
#include "color.hpp"
#include <iostream>

class plan : public object {
private:
  rt::vector _origin;
  rt::vector _normal_vector;
public:
  rt::vector get_origin() {return _origin;}
  void set_origin(rt::vector o) {_origin = o;}
  rt::vector get_normal_vector() {return _normal_vector;}
  void set_normal_vector(rt::vector n) {_normal_vector = n;}

  bool does_intersect(ray r) {
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

  rt::vector intersection(ray r) {

    double t = ( (_origin|_normal_vector)-(r.get_origin()|_normal_vector) )/(r.get_direction()|_normal_vector);

    return (r.get_origin()+(t*r.get_direction()));
  }

  rt::vector normal_vector(ray r) {}
};


