#ifndef __OBJECT_H
#define __OBJECT_H


#include "vector.hpp"
#include "ray.hpp"
#include "color.hpp"
#include "source.hpp"
#include "option.hpp"

class object {
protected:
  rt::color color;

public:
  rt::color get_color() const;

  virtual option<rt::vector> get_point_of_incidence_of(ray ray) = 0;
};

#endif
