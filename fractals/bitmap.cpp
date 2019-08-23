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

bool Bitmap::write(const string &filename) {

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
    if (of.fail())
      cerr << "Failed to write the bitmap file header to the file '" << filename
           << "'";
    of.write((char *)&ih, sizeof(BitmapInfoHeader));
    if (of.fail())
      cerr << "Failed to write the bitmap info header to the file '" << filename
           << "'";
    of.write((char *)pixels_.get(), size_);
    if (of.fail())
      cerr << "Failed to write the bitmap content to the file '" << filename
           << "'";
    of.flush();
    of.close();
    if (of.fail())
      cerr << "Failed to close the file '" << filename << "'";
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
    : width_(width), height_(height), total_{0}, b(width, height),
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
  total_ = 0;
  for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
    total_ += histogram[i];
}

void FractalCreator::draw_fractal() {

  RGB start_color{0, 0, 0}, end_color{0, 0, 0},
      color_diff = end_color - start_color;
  for (int y = 0; y < height_; y++) {
    for (int x = 0; x < width_; x++) {
      uint8_t red{0}, green{0}, blue{0};
      auto iterations = fractal[y][x];
      /* uint8_t color = */
      /*     (uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);
       */

      double hue = 0.0;
      if (iterations != Mandelbrot::MAX_ITERATIONS) {
        for (int i = 0; i < iterations; i++)
          hue += ((double)histogram[i]) / total_;
        red = start_color.r + color_diff.r * hue;
        green = start_color.g + color_diff.g * hue;
        blue = start_color.b + color_diff.b * hue;

        // green = pow(255, hue);
        // green = (255 * hue + pow(255, hue)) / 2;
      }
      b.set_pixel(x, y, red, green, blue);
    }
  }
}

void FractalCreator::write_bitmap(const std::string &filename) {
  b.write(filename);
}

void FractalCreator::run(const std::string &filename) {
  calc_iteration();
  draw_fractal();
  write_bitmap(filename);
}

RGB RGB::operator-(const RGB &c) { return RGB{r - c.r, g - c.g, b - c.b}; };
