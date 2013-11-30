#ifndef __OBJECT_H
#define __OBJECT_H


#include "vector.hpp"
#include "ray.hpp"
#include "color.hpp"
#include "source.hpp"

class object {
protected:
  rt::color _color;

public:

	static object DEFAULT;

  rt::color get_color();
  void set_color(rt::color color);
  virtual bool does_intersect(ray ray);
  virtual rt::vector intersection(ray ray);
  virtual rt::vector normal_vector(ray ray);
	virtual double dist(ray ray);
	virtual bool is_lighted(rt::vector p, source s);
};

#endif
