#include "Camera.hpp"
#include "Ray.hpp"

Camera::Camera(const rt::image& image, const Point& origin, const rt::vector& direction, const rt::vector& up, double distance) :
  direction(direction.unit()), distance(distance), image(image), origin(origin), up(up.unit()) {
}

void Camera::update_image() {
  int width = image.width();
  int height = image.height();
  Point center_of_image = origin + distance*direction;
  rt::vector right = direction ^ up;
  Point upper_left_corner_of_image = center_of_image - (width / 2.0) * right - (height / 2.0) * up;
  for (int x=0; x<width; ++x) {
    for (int y=0; y<width; ++y) {
      Point pixel_center = upper_left_corner_of_image + x * right + y * up;
      Ray ray = Ray(origin, pixel_center - origin);
      // TODO
    }
  }
}
