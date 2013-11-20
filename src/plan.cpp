#include "object.hpp"
#include "sphere.hpp"
#include "vector.hpp"
#include "color.hpp"
#include <iostream>

using namespace rt;

class plan : public object {
private:
	vector _origin;
	vector _normal_vector;
public:
	vector get_origin() {return _origin;}
	void set_origin(vector o) {_origin = o;}
	vector get_normal_vector() {return _normal_vector;}
	void set_normal_vector(vector n) {_normal_vector = n;}	

	bool does_intersect(ray r) {
		if ( (r.get_direction()|_normal_vector)=0)
		{
			rerturn false; //rayon parallèle au plan	
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

	vector intersection(ray r) {

		double t = ( (_origin|_normal_vector)-(r.get_origin()|_normal_vector) )/(r.get_direction()|_normal_vector);

		return (r.get_origin()+(t*r.get_direction()));
	}

	vector normal_vector(ray r) {}
}


