#ifndef __OBJECT_H
#define __OBJECT_H


#include "vector.hpp"
#include "ray.hpp"
#include "color.hpp"
#include "source.hpp"

class object {
protected:
  rt::color color;

public:
  rt::color get_color() const;
};

#endif
