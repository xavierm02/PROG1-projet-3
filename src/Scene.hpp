#ifndef __SCENE_H
#define __SCENE_H


#include "vector.hpp"
#include "Object.hpp"
#include "Source.hpp"
#include <iostream>
#include <vector>

class Scene {
  private:
    std::vector<Source> sources;
    std::vector<Object*> objects;

  public:
    void add_source(Source source);
    void add_object(Object *object);

    std::vector<Source>::const_iterator get_sources_iterator() const;
    //std::vector<source>::const_iterator get_objects_iterator();
};

#endif
