#include "sphere.hpp"
#include <iostream>

class sphere {
private:
	vector _center;
	unsigned double _radius;
	color _color;
public:
	bool does_intersect(ray r) {
			
	}

	vector intersection(ray r);
	vector normal_vector(ray r);
};

}
