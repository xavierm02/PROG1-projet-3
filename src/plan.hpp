#ifndef __PLAN_H
#define __PLAN_H

#include "object.hpp"
#include "vector.hpp"
#include "ray.hpp"

class plan : public object {
private:
	vector _origin;
	vector _normal_vector;
public:
	vector get_origin();
	void set_origin(vector o);
	vector get_normal_vector();
	void set_normal_vector(vector n);

	bool does_intersect(ray r);
	vector intersection(ray r);
};

#endif
