#ifndef __SOURCE_H
#define __SOURCE_H

#include "vector.hpp"
#include "color.hpp"
#include "Point.hpp"

class Source {
  private:
    rt::color color;
    Point origin;

  public:
    Source(const Point& origin, const rt::color& color);

    rt::color get_color() const;
    Point get_origin() const;
};

#endif
