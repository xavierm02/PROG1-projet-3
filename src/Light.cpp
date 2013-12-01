#include "Light.hpp"

#include <math.h>
#include <limits>
#include <stdexcept>
#include <iomanip>

double Light::light_component_of_color_component(unsigned char color_component) {
  return (atanh(color_component/256.0));// 256 instead of 255 to avoid infinity
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
    throw (std::logic_error("Trying to create a Light with negative component."));
  }
  if (red == std::numeric_limits<double>::infinity() || green == std::numeric_limits<double>::infinity() || blue == std::numeric_limits<double>::infinity()) {
    throw (std::logic_error("Trying to create a Light with infinite component."));
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
  return Light(
    color.get_red() / 255.0 * red,
    color.get_green() / 255.0 * green,
    color.get_blue() / 255.0 * blue
  );
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
  return Light(
    scalar * light.red,
    scalar * light.green,
    scalar * light.blue
  );
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
