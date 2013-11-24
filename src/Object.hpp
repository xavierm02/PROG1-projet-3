#ifndef __OBJECT_H
#define __OBJECT_H


#include "vector.hpp"
#include "color.hpp"
#include "Ray.hpp"
#include "Option.hpp"

class Object {
protected:
  rt::color color;

public:
  virtual Object* clone() const = 0;

  rt::color get_color() const;

  virtual rt::vector get_point_of_incidence_of(Ray ray) = 0;
};

#endif
