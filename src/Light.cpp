#include "Light.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
#include <limits>
#include "Utils.hpp"

/*char f(double x) {
  return (unsigned char) (atan(x)/M_PI*2*255);
}

double g(unsigned char x) {
  return tan(x*M_PI/2/255);// way too slow
}*/

char f(double x) {
  return (unsigned char) (tanh(x/2)*255);
}

double g(unsigned char x) {
  return (atanh(x/255.0)*2);
}

Light::Light() :
  red(0.0), green(0.0), blue(0.0) {
}

Light::Light(double red, double green, double blue) :
  red(red), green(green), blue(blue) {
}

Light::Light(const rt::color& color) :
  red(g(color.get_red())), green(g(color.get_green())), blue(g(color.get_blue())) {
}

Light Light::operator+(const Light& light) const {
  return Light(red + light.red, green + light.green, blue + light.blue);
}

Light operator*(const double& k, const Light& light) {
  double red = light.red;
  if (red != 0 ) {
    red = k * red;
  }
  double green = light.green;
  if (green != 0 ) {
    green = k * green / 255.0;
  }
  double blue = light.blue;
  if (blue != 0 ) {
    blue = k * blue / 255.0;
  }
  return Light(red, green, blue);
}

rt::color Light::to_color() const {
  return rt::color(f(red), f(green), f(blue));
}

Light operator^(const rt::color& color, const Light& light) {
  double red = color.get_red();
  if (red != 0 ) {
    red = red / 255.0 * light.red;
  }
  double green = color.get_green();
  if (green != 0 ) {
    green = green / 255.0 * light.green;
  }
  double blue = color.get_blue();
  if (blue != 0 ) {
    blue = blue / 255.0 * light.blue;
  }
  return Light(red, green, blue);
}

std::ostream &operator<<(std::ostream& os, const Light& light) {
  return os << "Light(" << light.red << ", " << light.green << ", " << light.blue << ")";
}

Light Light::WHITE = Light(rt::color::WHITE);
Light Light::BLACK = Light(rt::color::BLACK);
Light Light::RED = Light(rt::color::RED);
Light Light::GREEN = Light(rt::color::GREEN);
Light Light::BLUE = Light(rt::color::BLUE);
Light Light::GREY = Light(rt::color(127, 127, 127));


