#include "bitmap.hpp"
#include <cstdint>
#include <iostream>
#include <math.h>
#include <memory>

using namespace std;

int main(int argc, char *argv[]) {
  FractalCreator fc{};

  fc.add_zoom(Zoom{fc.WIDTH / 2, fc.HEIGHT / 2, 4.0 / fc.WIDTH});
  fc.add_zoom(Zoom{295, fc.HEIGHT - 202, 0.1});
  fc.add_zoom(Zoom{312, fc.HEIGHT - 304, 0.1});

  fc.calc_iteration();
  fc.draw_fractal();

  fc.write_bitmap("mandelbrot.bmp");
  return 0;
}
