#ifndef __PLAN_H
#define __PLAN_H

#include "object.hpp"
#include "vector.hpp"
#include "ray.hpp"

class plan : public object {
private:
  rt::vector _origin;
  rt::vector _normal_vector;
public:
  rt::vector get_origin();
  void set_origin(rt::vector o);
  rt::vector get_normal_vector();
  void set_normal_vector(rt::vector n);

  bool does_intersect(ray r);
  rt::vector intersection(ray r);
	double dist(ray r);
};

#endif
