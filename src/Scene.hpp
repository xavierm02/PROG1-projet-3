#ifndef __SCENE_H
#define __SCENE_H

#include "color.hpp"
#include "vector.hpp"
#include "Object.hpp"
#include "Source.hpp"
#include <iostream>
#include <vector>

class Scene {
  private:
    rt::color background;
    std::vector<Source> sources;
    std::vector<Object*> objects;

  public:
    Scene(const rt::color& background);

    void add_source(Source& source);
    void add_object(Object& object);

    //std::vector<Source>::const_iterator get_sources_iterator() const;
    //std::vector<Object*>::const_iterator get_objects_iterator();

    const Option< std::pair<Object*, Point> > get_incidence_point_of(const Ray& ray) const;
    rt::color determine_color(const Ray& ray) const;
};

#endif
