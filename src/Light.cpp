#include "Light.hpp"

#include <math.h>
#include <limits>
#include <stdexcept>
#include <iomanip>

double Light::light_component_of_color_component(unsigned char color_component) {
  return (atanh(color_component/256.0));
}

unsigned char Light::color_component_of_light_component(double light_component) {
  return (unsigned char) (tanh(light_component)*256);
}

Light::Light():
  red(0.0),
  green(0.0),
  blue(0.0) {
}

Light::Light(double red, double green, double blue):
  red(red),
  green(green),
  blue(blue) {
  if (red < 0 || green < 0 || blue < 0) {
    throw (std::logic_error("Trying to create a Light with negative components."));
  }
}

Light::Light(const rt::color& color) :
  red(light_component_of_color_component(color.get_red())),
  green(light_component_of_color_component(color.get_green())),
  blue(light_component_of_color_component(color.get_blue())) {
}

double Light::get_red() const {
  return red;
}

double Light::get_green() const {
  return green;
}

double Light::get_blue() const {
  return blue;
}

Light Light::operator+(const Light& light) const {
  return Light(red + light.red, green + light.green, blue + light.blue);
}

Light Light::reflect_on(const rt::color& color) const {
  double red = color.get_red();
  if (red != 0 ) {
    red = red / 255.0 * red;
  }
  double green = color.get_green();
  if (green != 0 ) {
    green = green / 255.0 * green;
  }
  double blue = color.get_blue();
  if (blue != 0 ) {
    blue = blue / 255.0 * blue;
  }
  return Light(red, green, blue);
}

rt::color Light::to_color() const {
  return rt::color(
    color_component_of_light_component(red),
    color_component_of_light_component(green),
    color_component_of_light_component(blue)
  );
}

Light::operator int() const {
  return 256 * (
    256 * color_component_of_light_component(get_red()) +
    color_component_of_light_component(get_green())
  ) + color_component_of_light_component(get_blue());
}

Light operator*(const double& scalar, const Light& light) {
  double red = light.red;
  if (red != 0 ) {
    red = scalar * red;
  }
  double green = light.green;
  if (green != 0 ) {
    green = scalar * green;
  }
  double blue = light.blue;
  if (blue != 0 ) {
    blue = scalar * blue;
  }
  return Light(red, green, blue);
}

Light Light::WHITE = Light(rt::color::WHITE);
Light Light::BLACK = Light(rt::color::BLACK);
Light Light::RED = Light(rt::color::RED);
Light Light::GREEN = Light(rt::color::GREEN);
Light Light::BLUE = Light(rt::color::BLUE);
Light Light::GREY = Light(rt::color(127, 127, 127));

std::ostream &operator<<(std::ostream& output_stream, const Light& light) {
  return output_stream << "Light(" << "0x" << std::setfill('0') << std::setw(6) << std::hex << (int) light << ")";
}
