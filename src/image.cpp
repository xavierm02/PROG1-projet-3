#include <cmath>
#include "image.hpp"

image::image() {
}

image::image(int width, int height) {
  data = SDL_CreateRGBSurface(SDL_SWSURFACE,width,height,32,0,0,0,0);
}

image::image(const image& img) {
  data = img.data;
  data->refcount++;
}

image::~image() {
  if(data != NULL)
    SDL_FreeSurface(data);
}

image image::copy() const {
  image cpy(width(),height());
  blit(cpy,0,0);
  return cpy;
}

color image::get_pixel(int x, int y) const {
  if(x < 0 || y < 0 || x >= width() || y >= height())
    return color(0,0,0,0);
  char* pixel = ((char*)data->pixels) + y*data->pitch + x*4;
  return color(pixel[0], pixel[1], pixel[2], pixel[3]);
}

void image::set_pixel(int x, int y, const color& c) {
  if(x < 0 || y < 0 || x >= width() || y >= height()) return;
  uint32_t col = SDL_MapRGB(data->format,
                            c.get_red(),
                            c.get_green(),
                            c.get_blue());
  char* pixel = ((char*)data->pixels) + y*data->pitch + x*4;
  *(uint32_t*)pixel = col;
}

void image::blit(image& dst, const rect& srcrect, int dstx, int dsty) const {
  SDL_Rect dstrect;
  dstrect.x = dstx;
  dstrect.y = dsty;
  SDL_BlitSurface(data, (SDL_Rect*)(&srcrect), dst.data, &dstrect);
}

void image::blit(image& dst, int dstx, int dsty) const {
  rect srcrect;
  srcrect.x = 0;
  srcrect.y = 0;
  srcrect.w = dst.data->w;
  srcrect.h = dst.data->h;
  blit(dst,srcrect,dstx,dsty);
}

void image::draw_line(int x1, int y1, int x2, int y2, const color& c) {
  int x,y;
  int dx,dy;
  int xincr,yincr;
  int erreur;
  int i;

  set_pixel(x1,y1,c);

  dx = abs(x2-x1);
  dy = abs(y2-y1);
  if(x1<x2)
    xincr = 1;
  else
    xincr = -1;
  if(y1<y2)
    yincr = 1;
  else
    yincr = -1;

  x = x1;
  y = y1;
  if(dx>dy) {
    erreur = dx/2;
    for(i=0; i<dx; i++) {
      x += xincr;
      erreur += dy;
      if(erreur > dx) {
        erreur -= dx;
        y += yincr;
      }
      set_pixel(x,y,c);
    }
  } else {
    erreur = dy/2;
    for(i=0; i<dy; i++) {
      y += yincr;
      erreur += dx;

      if(erreur>dy) {
        erreur -= dy;
        x += xincr;
      }
      set_pixel(x,y,c);
    }
  }
}

void image::draw_rect(int x1, int y1, int x2, int y2, const color& c) {
  draw_line(x1,y1,x1,y2,c);
  draw_line(x1,y1,x2,y1,c);
  draw_line(x2,y2,x1,y2,c);
  draw_line(x2,y2,x2,y1,c);
}

void image::fill_rect(int x1, int y1, int x2, int y2, const color& c) {
  SDL_Rect r = {x1, y1, (x2-x1+1), (y2-y1+1)};
  SDL_FillRect(data, &r, SDL_MapRGBA(data->format,
                                     c.get_red(),
                                     c.get_green(),
                                     c.get_blue(),
                                     c.get_alpha()
                                    ));
}

void image::draw_circle(int icx, int icy, int radius, const color& c) {
  double error = (double)-radius;
  double x = (double)radius-0.5;
  double y = (double)0.5;
  double cx = icx - 0.5;
  double cy = icy - 0.5;

  while (x >= y) {
    set_pixel((int)(cx + x), (int)(cy + y), c);
    set_pixel((int)(cx + y), (int)(cy + x), c);

    if (x != 0) {
      set_pixel((int)(cx - x), (int)(cy + y), c);
      set_pixel((int)(cx + y), (int)(cy - x), c);
    }

    if (y != 0) {
      set_pixel((int)(cx + x), (int)(cy - y), c);
      set_pixel((int)(cx - y), (int)(cy + x), c);
    }

    if (x != 0 && y != 0) {
      set_pixel((int)(cx - x), (int)(cy - y), c);
      set_pixel((int)(cx - y), (int)(cy - x), c);
    }

    error += y;
    ++y;
    error += y;

    if (error >= 0) {
      --x;
      error -= x;
      error -= x;
    }
  }
}

void image::fill_circle(int cx, int cy, int radius, const color& c) {
  double r = (double)radius;

  for (double dy = 1; dy <= r; dy += 1.0) {
    double dx = floor(sqrt((2.0 * r * dy) - (dy * dy)));
    int x = cx - dx;

    Uint8 *target_pixel_a =
      (Uint8 *)data->pixels + ((int)(cy + r - dy)) * data->pitch + x*4;
    Uint8 *target_pixel_b =
      (Uint8 *)data->pixels + ((int)(cy - r + dy)) * data->pitch + x*4;

    for (; x <= cx + dx; x++) {
      int ic = (int)c;
      memcpy(target_pixel_a,&ic,4);
      memcpy(target_pixel_b,&ic,4);
      target_pixel_a += 4;
      target_pixel_b += 4;
    }
  }
}
