#include <iostream>
#include "scene.hpp"
#include "ray.hpp"
#include "object.hpp"

object first_object(scene scene, ray ray) {

	double dist_mini;
	if (!(scene.empty_object())) {
		dist_mini = scene.get_object(0).dist(ray);
	}

	object closest;
	int i;

	for (i=0; i<scene.nb_objects(); i++) 
	{
		object obj = scene.get_object(i);
		
		if (obj.does_intersect(ray))
		{
			if (obj.dist(ray) >= 0 && obj.dist(ray) < dist_mini)
			{
				dist_mini = obj.dist(ray);
				closest = obj;
			}
		}
	} 
	return closest;
}


