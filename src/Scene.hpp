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

    const std::vector<Source> get_sources() const;
    const std::vector<Object*> get_objects() const;

    const Option< std::pair<Object*, Point> > get_incidence_point_of(const Ray& ray) const;
    rt::color determine_color(const Ray& ray) const;
};

#endif
