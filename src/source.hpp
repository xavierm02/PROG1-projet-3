#ifndef __SOURCE_H
#define __SOURCE_H

#include "vector.hpp"
#include "color.hpp"

class source {
  private:
    rt::vector _origin;
    rt::color _color;
		double _intensity;
  public:

		source(rt::vector origin, rt::color color, double intensity);
		source(rt::vector origin);

    rt::vector get_origin();
		rt::color get_color();
		double get_intensity();

		void set_origin(rt::vector origin);
		void set_color(rt::color color);
		void set_intensity(double intensity); 
};

#endif
