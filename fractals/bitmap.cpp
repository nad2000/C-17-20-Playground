#include "bitmap.hpp"
#include <complex>
#include <fstream>
#include <iostream>
#include <utility>

using namespace std;

Bitmap::Bitmap(int width, int height)
    : width_{width}, height_{height}, size_{width * height * 3},
      pixels_(new uint8_t[width * height * 3]{}) {}
Bitmap::~Bitmap() {}

void Bitmap::set_pixel(int x, int y, uint8_t r, uint8_t g, uint8_t b) {
  uint8_t *pp = pixels_.get() + 3 * (y * width_ + x);
  pp[0] = b;
  pp[1] = g;
  pp[2] = r;
};

bool Bitmap::write(string filename) {

  BitmapFileHeader fh;
  BitmapInfoHeader ih;
  fh.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
  fh.fileSize = fh.dataOffset + size_;
  ih.width = width_;
  ih.height = height_;

  fstream of;
  // of outputFile; // can open w/o ios::out
  of.open(filename, ios::binary | ios::out);
  if (of.is_open()) {
    // outputFile.write((char *)&someone, sizeof(Person));
    // this is supposetly right way of
    // doing casting now...
    of.write((char *)&fh, sizeof(BitmapFileHeader));
    of.write((char *)&ih, sizeof(BitmapInfoHeader));
    of.write((char *)pixels_.get(), size_);
    of.close();
  } else {
    cerr << "Failed to open the file '" << filename << "'";
    return false;
  }

  return true;
}
ZoomList::ZoomList(int width, int height) : width_{width}, height_{height} {}
void ZoomList::add(const Zoom &zoom) {
  zooms_.push_back(zoom);

  x_centre_ += (zoom.x - width_ / 2) * scale_;
  y_centre_ += (zoom.y - height_ / 2) * scale_;
  scale_ *= zoom.scale;
}

pair<double, double> ZoomList::do_zoom(int x, int y) {
  double x_fractal = ((x - width_ / 2) * scale_ + x_centre_) / width_;
  double y_fractal = ((y - height_ / 2) * scale_ + y_centre_) / height_;
  return pair<double, double>{x_fractal, y_fractal};
}

Mandelbrot::Mandelbrot() {}
Mandelbrot::~Mandelbrot() {}

int Mandelbrot::get_iterations(double x, double y) {
  complex<double> c(x, y);
  complex<double> z = 0;

  int i;
  for (i = 0; i < MAX_ITERATIONS; i++) {
    z = z * z + c;
    if (abs(z) > 2)
      break;
  }

  return i;
}

FractalCreator::FractalCreator(int width, int height)
    : width_(width), height_(height), b(width, height),
      fractal(new unique_ptr<int[]>[height]),
      histogram(new int[Mandelbrot::MAX_ITERATIONS]{0}), zl(width, height) {}

FractalCreator::~FractalCreator(){};
void FractalCreator::add_zoom(const Zoom &zoom) { zl.add(zoom); }

void FractalCreator::calc_iteration() {
  for (int y = 0; y < height_; y++) {
    if (fractal[y] == nullptr)
      fractal[y] = unique_ptr<int[]>(new int[width_]);

    for (int x = 0; x < width_; x++) {
      // Fractals:
      pair<double, double> coords = zl.do_zoom(x, y);
      int iterations = Mandelbrot::get_iterations(coords);
      if (iterations != Mandelbrot::MAX_ITERATIONS)
        histogram[iterations]++;
      fractal[y][x] = iterations;
    }
  }
}

void FractalCreator::draw_fractal() {
  int total = 0;
  for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
    total += histogram[i];
  for (int y = 0; y < height_; y++) {
    for (int x = 0; x < width_; x++) {
      // uint8_t red{0}, green{0}, blue{0};
      uint8_t green{0};
      auto iterations = fractal[y][x];
      /* uint8_t color = */
      /*     (uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);
       */

      double hue = 0.0;
      if (iterations != Mandelbrot::MAX_ITERATIONS) {
        for (int i = 0; i < iterations; i++)
          hue += ((double)histogram[i]) / total;
        // green = 255 * hue;
        // green = pow(255, hue);
        green = (255 * hue + pow(255, hue)) / 2;
      }
      b.set_pixel(x, y, 0, green, 0);
    }
  }
}
void FractalCreator::write_bitmap(const std::string &filename) {
  b.write("mandelbrot.bmp");
}

RGB RGB::operator-(const RGB &c) { return RGB{r - c.r, g - c.g, b - c.b}; };
