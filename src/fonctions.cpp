#include <iostream>
#include "scene.hpp"
#include "ray.hpp"
#include "object.hpp"


bool does_intersect(scene scene, ray ray) {

	bool b(false);

	int i;

	for (i=0; i< scene.nb_objects(); i++)
	{
		object obj = scene.get_object(i);
		
		if (obj.does_intersect(ray)) 
		{
			b = true;
		}
	}
	return b;
}

object first_object(scene scene, ray ray) {

	double dist_mini = -1;
	
	object closest(object::DEFAULT);
	int i;

	for (i=0; i<scene.nb_objects(); i++) 
	{
		object obj = scene.get_object(i);
		
		if (obj.does_intersect(ray))
		{
			if (obj.dist(ray) >= 0 && ((dist_mini == -1)||(obj.dist(ray) < dist_mini && (dist_mini != -1) )))
			{
				dist_mini = obj.dist(ray);
				closest = obj;
			}
		}
	} 
	return closest;
}


