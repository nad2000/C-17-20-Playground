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
ZoomList::ZoomList(int width, int height) : width_{width}, height_{height} {};
void ZoomList::add(const Zoom &zoom) {
  x_centre_ += (zoom.x - width_ / 2) * scale_;
  y_centre_ += (zoom.y - width_ / 2) * scale_;
  scale_ *= zoom.scale;

  zooms_.push_back(zoom);
}
std::pair<double, double> ZoomList::do_zoom(int x, int y) {
  return pair<double, double>{0, 0};
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
