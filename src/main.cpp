#include <iostream>
#include <unistd.h>
#include <cassert>

#include "screen.hpp"

using namespace std;

static void draw_rectangle(screen& s, int x, int y, int width, color c) {
  s.fill_rect(x, y, x + width - 1, y + width - 1, c);
}

static void draw_centered_cross(screen& s, int x, int y, int width, color c) {
  assert(width > 0);
  int my_x = x - width/2;
  int my_y = y - width/2;
  //(s, my_x, my_y, width, c);
  draw_rectangle(s, my_x, my_y, width, c);
  draw_rectangle(s, my_x + width, my_y, width, c);
  draw_rectangle(s, my_x - width, my_y, width, c);
  draw_rectangle(s, my_x, my_y + width, width, c);
  draw_rectangle(s, my_x, my_y - width, width, c);
  s.set_pixel(x, y, color::RED);
}

int main(void) {
  screen s(640,480);
  // s.draw_line(32,64,64,128,color::RED);
  // s.draw_rect(0,0,32,48,color::BLUE);
  // s.fill_rect(56,2,76,23,color::GREEN);
  // s.set_pixel(639,479,color::RED);
  // s.draw_line(0,0,639,479,color::GREEN);

  s.draw_circle(320,240,20,color::BLUE);
  s.fill_circle(200,200,100,color::GREEN);

//  draw_centered_cross(s, 200, 200, 10, color::WHITE);

  color c = color::WHITE;
  while(s.update()) {
    int x, y;

    cout << "Please, enter x and y: " << flush;
    std::cin >> x >> y;
    assert(cin.good());

    draw_centered_cross(s, x, y, 10, c);

    //      sleep(1);
  }

  return 0;
}
