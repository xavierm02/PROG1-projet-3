#ifndef __SCENE_H
#define __SCENE_H

#include "Light.hpp"
#include "UnitVector.hpp"
#include "Object.hpp"
#include "Source.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include "ObjectPoint.hpp"

class Scene {
  private:
    Light background;
    std::vector<Source> sources;
    std::vector<std::shared_ptr<Object>> objects;

  public:
    Scene(const Light& background = Light::BLACK);

    void add_source(const Source& source);
    void add_object(std::shared_ptr<Object> object);

    const std::vector<Source> get_sources() const;
    const std::vector<std::shared_ptr<Object>> get_objects() const;

    bool obstructs(const Point& beginning, const Point& end) const;
    Light determine_light_from_sources_at(const Point& point, const UnitVector normal_vector) const;
    const Option<ObjectPoint> get_incidence_point_of(const Ray& ray) const;
    Light determine_light_of(const Ray& ray) const;
};

#endif
