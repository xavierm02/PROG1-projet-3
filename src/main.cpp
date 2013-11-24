#include <iostream>
#include <unistd.h>

#include "screen.hpp"
#include "Camera.hpp"

int main(void)
{
  rt::screen screen = rt::screen(640,480);

  rt::vector camera_origin = rt::vector(0,0,0);
  rt::vector camera_direction = rt::vector(1,0,0);
  rt::vector camera_up = rt::vector(0,0,1);
  double camera_distance = 1.0;
  Camera camera = Camera(screen, camera_origin, camera_direction, camera_up, camera_distance);

  screen.update();
  while(screen.wait_quit_event()) {
    // wait for an input from user
  }

  return 0;
}
