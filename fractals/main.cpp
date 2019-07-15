#include "bitmap.hpp"
#include <cstdint>
#include <iostream>
#include <math.h>
#include <memory>

using namespace std;

int main(int argc, char *argv[]) {
  int const WIDTH = 800, HEIGHT = 600;

  FractalCreator fc{WIDTH, HEIGHT};

  fc.add_zoom(Zoom{WIDTH / 2, HEIGHT / 2, 4.0 / WIDTH});
  fc.add_zoom(Zoom{295, HEIGHT - 202, 0.1});
  fc.add_zoom(Zoom{312, HEIGHT - 304, 0.1});

  fc.calc_iteration();
  fc.draw_fractal();

  fc.write_bitmap("mandelbrot.bmp");
  return 0;
}
