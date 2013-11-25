#include <iostream>
#include <unistd.h>

#include "screen.hpp"
#include "Camera.hpp"
#include "Plane.hpp"
#include "Sphere.hpp"

int main(void)
{
  rt::screen screen = rt::screen(640,480);

  Camera camera = Camera(screen, Point(0,0,0), rt::vector(1,0,0), rt::vector(0,0,1), 1.0, 2);

  Scene scene = Scene(rt::color::GREEN);

  Plane floor = Plane(Point(0,0,0), rt::vector(0,0,1), rt::color::BLUE);

  Sphere ball = Sphere(Point(2,0,0), 1.0, rt::color::BLUE);

  //scene.add_object(floor);
  scene.add_object(ball);

  camera.render(scene);
  screen.update();
  screen.wait_quit_event();
  return 0;
}
