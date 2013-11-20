#ifndef __OBJECT_H
#define __OBJECT_H


#include "vector.hpp"
#include "ray.hpp"
#include "color.hpp"

using namespace rt;

class object {
protected: 
	color _color;

public:
	color get_color();
	void set_color(color c);
	virtual bool does_intersect(ray r);
	virtual vector intersection(ray r);
	virtual vector normal_vector(ray r);
};

#endif
