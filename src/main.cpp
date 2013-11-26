#include <iostream>
#include <unistd.h>

#include "screen.hpp"
#include "Camera.hpp"
#include "Plane.hpp"
#include "Sphere.hpp"
#include "Rectangle.hpp"
#include "Source.hpp"
#include "Light.hpp"
#include "Utils.hpp"
#include <limits>
#include <cmath>

int main(void)
{
  rt::screen screen = rt::screen(1000,1000);//640,480

  Camera camera = Camera(screen, Point(-1000,0,0), rt::vector(1,0,0), rt::vector(0,0,1), 100.0, 2);

  Scene scene = Scene(rt::color(127, 127, 127));

  Plane floor = Plane(Point(0,0,-1000), rt::vector(0,0,1), rt::color::WHITE);

  //Rectangle rect = Rectangle(Point(100,2000,-2000), rt::vector(1,0,1), rt::vector(0,1,0), 800, 800, rt::color::BLUE);

  Sphere ball = Sphere(Point(100,0000,0), 400, rt::color::BLACK);

  scene.add_object(floor);
  //scene.add_object(rect);
  scene.add_object(ball);
  scene.add_source(Source(Point(1000,0,2000), Light::RED));
  scene.add_source(Source(Point(0,1000,2000), Light::GREEN));
  scene.add_source(Source(Point(-1000,0,2000), Light::BLUE));
  scene.add_source(Source(Point(0,-1000,2000), Light::GREY));
  scene.add_source(Source(Point(0, 0,2000), Light::WHITE));

  camera.render(scene);
  screen.update();
  screen.wait_quit_event();
  return 0;
}
