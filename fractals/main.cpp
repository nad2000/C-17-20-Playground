#include "bitmap.hpp"
#include <cstdint>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

  int const WIDTH = 800;
  int const HEIGHT = 600;
  Bitmap b(WIDTH, HEIGHT);

  double min = 999999;
  double max = -999999;

  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      // Fractals:
      double xf = (x - WIDTH / 2 - 200) * 2.0 / HEIGHT;
      double yf = (y - HEIGHT / 2) * 2.0 / HEIGHT;

      int iterations = Mandelbrot::get_iterations(xf, yf);
      uint8_t color =
          (uint8_t)(257 * (double)iterations / Mandelbrot::MAX_ITERATIONS);
      color = color * color * color;
      b.set_pixel(x, y, 0, color, 0);

      if (color < min)
        min = color;
      if (color > max)
        max = color;
    }
  }

  b.write("mandelbrot.bmp");
  cout << "min: " << min << ", max: " << max << endl;
  return 0;
}
