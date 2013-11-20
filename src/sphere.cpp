#include "object.hpp"
#include "sphere.hpp"
#include "vector.hpp"
#include "color.hpp"
#include "ray.hpp"
#include <iostream>
#include <cmath>

using namespace rt;

class sphere : public object {
private:
	vector _center;
	unsigned double _radius;
public:
	vector get_center() {return _center;}
	void set_center(vector c) {_center = c;}
	unsigned double get_radius() {return _radius;}
	void set_radius(unsigned double r) {_radius = r;}

	bool sphere::does_intersect(ray r) { 

		vector u = r.get_direction();
		vector v = _center - r.get_origin();

		//on cherche t tel que ||v-tu||² = Rayon²
		//mettre sous la forme at² + bt + c = 0
		
		double a = (u.norm())*(u.norm());
		double b = -2*(u|v);
		double c = (v.norm())*(v.norm()) - _radius*_radius;

		double delta = b*b - 4*a*c;
	
		if (delta <= 0) 
		{
			return false; // pas d'intersection ou racine double
		}
		else 
		{
			double x1 = (-1*b - std::sqrt(delta))/(2*a);
			double x2 = (-1*b + std::sqrt(delta))/(2*a);
	
			if (x2 <= 0) 
			{
				return false; // la sphere est derrière la camera
			}
			else	
			{
				return true;
			}
				
		}
			
	}

	vector sphere::intersection(ray r) {
		vector u = r.get_direction();
		vector v = _center - r.get_origin();
		
		double a = (u.norm())*(u.norm());
		double b = -2*(u|v);
		double c = (v.norm())*(v.norm()) - _radius*_radius;

		double delta = b*b - 4*a*c;

		double t1 = (-1*b - std::sqrt(delta))/(2*a);
		double t2 = (-1*b + std::sqrt(delta))/(2*a);
		
		if (t1 > 0) 
		{
			double t = t1;	//on prend le t le plus petit
		}
		else
		{
			double t = t2;		
		}
				
		return (r.get_origin() + t*u);		
	}

	vector sphere::normal_vector(ray r) {}
}


