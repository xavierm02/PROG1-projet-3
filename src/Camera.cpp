#include "Camera.hpp"

Camera::Camera(const rt::image& image, const Point& origin, const rt::vector& direction, const rt::vector& up, double distance) :
  direction(direction), distance(distance), image(image), origin(origin), up(up) {
}
/*
void camera::update_image() {
  int width = _image.width();
  int height = _image.height();
  rt::vector center_of_image = _origin + _distance*_direction;
  int x;
  int y;
  for (x=0; x<width; ++x) {
    for (y=0; y<width; ++y) {

    }
  }
}
*/
