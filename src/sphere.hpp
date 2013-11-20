#ifndef __SPHERE_H
#define __SPHERE_H

#include "object.hpp"
#include "sphere.hpp"
#include "vector.hpp"
#include "color.hpp"
#include "ray.hpp"

using namespace rt;

class sphere : public object {
private:
	vector _center;
	unsigned double _radius;
public:
	vector get_center();
	void set_center(vector c);
	unsigned double get_radius();
	void set_radius(unsigned double r);
	bool does_intersect(ray r);
	vector intersection(ray r);
	vector normal_vector(ray r);
};

#endif
