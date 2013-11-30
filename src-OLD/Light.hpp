#ifndef __LIGHT_H
#define __LIGHT_H

#include "color.hpp"
#include <iostream>

class Light {
  private:
    double red;
    double green;
    double blue;
  public:
    Light();
    Light(double red, double green, double blue);
    Light(const rt::color& color);

    Light operator+(const Light& light) const;

    rt::color to_color() const;

    friend Light operator*(const double& k, const Light& light);

    friend Light operator^(const rt::color& color, const Light& light);

    friend std::ostream &operator<<(std::ostream &os, const Light &light);

    static Light WHITE;
    static Light BLACK;
    static Light RED;
    static Light GREEN;
    static Light BLUE;
    static Light GREY;
};

#endif
