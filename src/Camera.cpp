#include <iostream>
#include "Ray.hpp"

#include "Camera.hpp"

Camera::Camera(const rt::image& image, const Point& origin, const UnitVector& direction, const UnitVector& up, double distance, const unsigned int depth) :
  depth(depth),
  direction(direction),
  distance(distance),
  image(image),
  origin(origin),
  up(up) {
}

void Camera::render(const Scene& scene) {
  int width = image.width();
  int height = image.height();
  Point center_of_image = origin + distance*direction;
  UnitVector right = UnitVector(direction ^ up);
  Vector scaled_up = distance / height * up;
  Vector scaled_right = distance / width * right;
  Point bottom_left_corner_of_image = center_of_image - (distance / 2.0) * right + (distance / 2.0) * up;
  for (int x=0; x<width; ++x) {
    for (int y=0; y<height; ++y) {
      Point pixel_center = bottom_left_corner_of_image + x * scaled_right - y * scaled_up;
      Ray ray = Ray(origin, UnitVector(pixel_center - origin), depth);
      rt::color color = scene.determine_light_of(ray).to_color();
      image.set_pixel(x, y, color);
    }
  }
}
