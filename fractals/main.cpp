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
      double xf = (x - WIDTH / 2) * 2.0 / WIDTH;
      double yf = (y - HEIGHT / 2) * 2.0 / HEIGHT;

      int iterations = Mandelbrot::get_iterations(xf, yf);
      uint8_t r =
          (uint8_t)(257 * (double)iterations / Mandelbrot::MAX_ITERATIONS);
      b.set_pixel(x, y, r, r, r);

      if (r < min)
        min = r;
      if (r > max)
        max = r;
    }
  }

  b.write("mandelbrot.bmp");
  cout << "min: " << min << ", max: " << max << endl;
  return 0;
}
