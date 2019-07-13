#include "bitmap.hpp"
#include <fstream>
#include <iostream>

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

Mandelbrot::Mandelbrot() {}
Mandelbrot::~Mandelbrot() {}

int Mandelbrot::get_iterations(double x, double y) { return 0; }
