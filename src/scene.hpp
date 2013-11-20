#ifndef __SCENE_H
#define __SCENE_H


#include "vector.hpp"
#include "camera.hpp"
#include "object.hpp"
#include "source.hpp"
#include <iostream>
#include <vector>

class scene {
  private:
    std::vector<source> _sources;
		std::vector<object> _objects;
    
  public:

		void add_source(source source);
		void add_object(object object);		
		
		int nb_sources();
		int nb_objects();
	
		source get_source(int i);
		object get_object(int i);

};

#endif
