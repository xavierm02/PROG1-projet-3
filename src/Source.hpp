#ifndef __SOURCE_H
#define __SOURCE_H

#include "vector.hpp"
#include "color.hpp"

class Source {
  private:
    rt::color color;
    rt::vector origin;

  public:
    Source(const rt::vector& origin, const rt::color& color);

    rt::color get_color() const;
    rt::vector get_origin() const;
};

#endif