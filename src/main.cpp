#include <iostream>
#include <unistd.h>

#include "screen.hpp"
#include "Camera.hpp"
#include "Plane.hpp"
#include "Sphere.hpp"

int main(void)
{
  rt::screen screen = rt::screen(500,500);//640,480

  Camera camera = Camera(screen, Point(-1000,0,0), rt::vector(1,0,0), rt::vector(0,0,1), 100.0, 2);

  Scene scene = Scene(rt::color::GREEN);

  Plane floor = Plane(Point(0,0,-1), rt::vector(-1,0,1), rt::color::BLUE);

  Plane back = Plane(Point(100,2000,2000), rt::vector(1,0,10000), rt::color::WHITE);

  Sphere ball = Sphere(Point(100,2000,2000), 100, rt::color::BLACK);

  scene.add_object(floor);
  scene.add_object(back);
  scene.add_object(ball);

  //std::cout << ball << "\n";
  const std::vector<Object*> objects = scene.get_objects();
  for (std::vector<Object*>::const_iterator it = objects.begin(); it != objects.end(); ++it) {
    //std::cout << **it << "\n";
  }

  camera.render(scene);
  screen.update();
  screen.wait_quit_event();
  return 0;
}
