#include "object.hpp"
#include "vector.hpp"
#include "ray.hpp"
#include <iostream>

using namespace rt;

class object {
protected: 
	color _color;
public:
	color get_color() {return _color;}
	void set_color(color c) {_color = c;}
	virtual bool does_intersect(ray r) = 0;
	virtual vector intersection(ray r) = 0;
	virtual vector normal_vector(ray r) = 0;
}
