#include <iostream>
#include "Ray.hpp"
#include "Utils.hpp"

#include "Camera.hpp"

Camera::Camera(const rt::image& image, const Point& origin, const rt::vector& direction, const rt::vector& up, double distance, const unsigned int depth) :
  depth(depth), direction(direction.unit()), distance(distance), image(image), origin(origin), up(up.unit()) {
}

void Camera::render(const Scene& scene) {
  int width = image.width();
  int height = image.height();
  Point center_of_image = origin + distance*direction;
  rt::vector right = direction ^ up;
  Point bottom_left_corner_of_image = center_of_image - (width / 2.0) * right + (height / 2.0) * up;
  for (int x=0; x<width; ++x) {
    for (int y=0; y<height; ++y) {
      Point pixel_center = bottom_left_corner_of_image + x * right - y * up;
      Ray ray = Ray(origin, pixel_center - origin, depth);
      rt:: color color = scene.determine_light_of(ray).to_color();
      if (color != rt::color::WHITE && color != rt::color(127,127,127) && color != rt::color::GREEN && color != (Light::GREEN + Light::RED).to_color()) {
        //std::cout << color << "     " << (Light::GREEN + Light::RED).to_color() << std::endl;

      }
      image.set_pixel(x, y, color);
    }
  }
}
