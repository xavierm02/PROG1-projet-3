#include <iostream>
#include <unistd.h>

#include "rt/screen.hpp"
#include "Camera.hpp"
#include "Plane.hpp"
#include "Sphere.hpp"
#include "Source.hpp"
#include "Light.hpp"
#include <limits>
#include <cmath>
#include "UniformObjectTexture.hpp"
#include "RadialObjectTexture.hpp"

int main(void)
{
  rt::screen screen = rt::screen(1000,1000);//640,480

  Camera camera = Camera(screen, Point(-1000,0,0), UnitVector(1,0,0), UnitVector(0,0,1), 100.0, 2);

  Scene scene = Scene(Light::GREY);

  // demo 1

  scene.add_object(Plane(Point(0,0,-1000), UnitVector(0,0,1), RadialObjectTexture(Point(0,0,-1000), 0.001, 0)));
  scene.add_object(Sphere(Point(100,0,0), 400, UniformObjectTexture::BLACK));
  scene.add_object(Sphere(Point(600,-1200,-200), 400, UniformObjectTexture::BLACK));
  scene.add_object(Sphere(Point(600,1200,-200), 400, UniformObjectTexture::BLACK));

  scene.add_source(Source(Point(1000,0,2000), Light::RED));
  scene.add_source(Source(Point(0,1000,2000), Light::GREEN));
  scene.add_source(Source(Point(-1000,0,2000), Light::BLUE));
  scene.add_source(Source(Point(0,-1000,2000), Light::GREY));
  scene.add_source(Source(Point(0, 0, 2000), Light::WHITE));

  // demo 2

  //scene.add_object(Sphere(Point(100,0,0), 400, UniformObjectTexture::RED));
  //scene.add_object(Sphere(Point(600,-1200,-200), 400, UniformObjectTexture::GREEN));
  //scene.add_object(Sphere(Point(600,1200,-200), 400, UniformObjectTexture::BLUE));

  //scene.add_source(Source(Point(-1000,0,2000), Light::WHITE));

  camera.render(scene);
  screen.update();
  screen.wait_quit_event();
  return 0;
}
