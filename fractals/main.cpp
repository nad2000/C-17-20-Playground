#include "bitmap.hpp"
#include <cstdint>
#include <iostream>
#include <math.h>
#include <memory>

using namespace std;

int main(int argc, char *argv[]) {

  int const WIDTH = 800;
  int const HEIGHT = 600;
  Bitmap b(WIDTH, HEIGHT);

  double min = 999999;
  double max = -999999;

  unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{0});
  unique_ptr<unique_ptr<int[]>[]> fractal(new unique_ptr<int[]>[HEIGHT]);
  ZoomList zl(WIDTH, HEIGHT);
  zl.add(Zoom{WIDTH / 2, HEIGHT / 2, 1.0});

  for (int y = 0; y < HEIGHT; y++) {
    fractal[y] = unique_ptr<int[]>(new int[WIDTH]);

    for (int x = 0; x < WIDTH; x++) {
      // Fractals:
      double xf = (x - WIDTH / 2 - 200) * 2.0 / HEIGHT;
      double yf = (y - HEIGHT / 2) * 2.0 / HEIGHT;

      int iterations = Mandelbrot::get_iterations(xf, yf);
      if (iterations != Mandelbrot::MAX_ITERATIONS)
        histogram[iterations]++;
      fractal[y][x] = iterations;
    }
  }
  int total = 0;
  for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
    total += histogram[i];
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      uint8_t red{0}, green{0}, blue{0};
      auto iterations = fractal[y][x];
      uint8_t color =
          (uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);

      double hue = 0.0;
      if (iterations != Mandelbrot::MAX_ITERATIONS) {
        for (int i = 0; i < iterations; i++)
          hue += ((double)histogram[i]) / total;
        green = pow(255, hue);
      }
      b.set_pixel(x, y, 0, green, 0);
    }
  }

  b.write("mandelbrot.bmp");
  cout << "min: " << min << ", max: " << max << endl;
  return 0;
}
