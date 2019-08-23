#include "bitmap.hpp"
#include <cstdint>
#include <iostream>
#include <math.h>
#include <memory>

using namespace std;

int main(int argc, char *argv[]) {
  //   int const WIDTH = 100, HEIGHT = 100;
  int const WIDTH = 800, HEIGHT = 600;

  FractalCreator fc{WIDTH, HEIGHT};

  /*   fc.add_zoom(Zoom{WIDTH / 2, HEIGHT / 2, 3.0}); */
  /*   fc.add_zoom(Zoom{WIDTH - WIDTH / 3, HEIGHT / 3, 300.0 / WIDTH}); */
  /*   fc.add_zoom(Zoom{(int)(WIDTH - WIDTH / 2.4), HEIGHT / 2, 300.0 / WIDTH});
   */

  /* fc.add_zoom(Zoom{WIDTH / 2, HEIGHT / 2, 1.1 / WIDTH}); */
  /* fc.add_zoom(Zoom{55, HEIGHT - 30, 0.1}); */
  /* fc.add_zoom(Zoom{55, HEIGHT - 44, 0.1}); */
  /* int const WIDTH = 800, HEIGHT = 600; */

  /* FractalCreator fc{WIDTH, HEIGHT}; */

  /* fc.add_zoom(Zoom{WIDTH / 2, HEIGHT / 2, 4.0 / WIDTH}); */
  /* fc.add_zoom(Zoom{295, HEIGHT - 202, 0.1}); */
  /* fc.add_zoom(Zoom{312, HEIGHT - 304, 0.1}); */

  /* fc.calc_iteration(); */
  /* fc.draw_fractal(); */

  fc.add_zoom(Zoom{295, 202, 0.1});
  // fc.add_zoom(Zoom{312, HEIGHT - 304, 0.1});
  fc.run("mandelbrot.bmp");
  return 0;
}
