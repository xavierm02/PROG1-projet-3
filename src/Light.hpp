#ifndef __LIGHT_H
#define __LIGHT_H

#include "rt/color.hpp"
#include <iostream>

class Light {
  private:
    double red;
    double green;
    double blue;
  public:
    static double light_component_of_color_component(unsigned char color_component);
    static unsigned char color_component_of_light_component(double light_component);

    Light();
    Light(double red, double green, double blue);
    Light(const rt::color& color);

    double get_red() const;
    double get_green() const;
    double get_blue() const;

    Light operator+(const Light& light) const;

    Light reflect_on(const rt::color& color) const;

    rt::color to_color() const;

    operator int() const;

    friend Light operator*(const double& scalar, const Light& light);

    //friend Light operator/(const Light& light, const double& scalar);

    static Light WHITE;
    static Light BLACK;
    static Light RED;
    static Light GREEN;
    static Light BLUE;
    static Light GREY;
};

std::ostream &operator<<(std::ostream &output_stream, const Light &light);

#endif
