#ifndef __SCENE_H
#define __SCENE_H
/*
#include "color.hpp"
#include "Vector.hpp"
#include "Object.hpp"
#include "Source.hpp"
#include <iostream>
#include <vector>
#include <memory>

class Scene {
  private:
    rt::color background;
    std::vector<Source> sources;
    std::vector<std::shared_ptr<Object>> objects;

  public:
    Scene(const rt::color& background);

    void add_source(const Source& source);
    void add_object(const Object& object);

    const std::vector<Source> get_sources() const;
    const std::vector<std::shared_ptr<Object>> get_objects() const;

    bool obstructs(const Point& beginning, const Point& end) const;
    Light determine_light_from_sources_at(const Point& point, const rt::vector normal_vector) const;
    const Option< std::pair<Object*, Point> > get_incidence_point_of(const Ray& ray) const;
    Light determine_light_of(const Ray& ray) const;
};
*/
#endif
