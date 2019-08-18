#ifndef BITMAP_H
#define BITMAP_H

#include <cstdint>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#pragma pack(2) // makes to align data stucture with 2 bytes
// preventing extra padding.

struct BitmapFileHeader {
  char header[2]{'B', 'M'};
  int32_t fileSize;
  int32_t reserved{0};
  int32_t dataOffset;
};

struct BitmapInfoHeader {
  int32_t headerSize{40};
  int32_t width;
  int32_t height;
  int16_t planes{1};
  int16_t bitsPerPixel{24};
  int32_t compression{0};
  int32_t dataSize{0};
  int32_t horizontalResolution{2400};
  int32_t verticalResolution{2400};
  int32_t colors{0};
  int32_t importantColors{0};
};

#pragma pack()

class Bitmap {
private:
  int width_{0};
  int height_{0};
  int size_{0};
  std::unique_ptr<uint8_t[]> pixels_;

public:
  Bitmap(int width, int height);
  bool write(const std::string &filename);
  void set_pixel(int x, int y, uint8_t r, uint8_t g, uint8_t b);
  virtual ~Bitmap();
};

class Mandelbrot {
public:
  static const int MAX_ITERATIONS = 1000;

public:
  Mandelbrot();
  virtual ~Mandelbrot();

  static int get_iterations(double x, double y);
  static int get_iterations(std::pair<double, double> const &c) {
    return get_iterations(c.first, c.second);
  }
};

struct Zoom {
  int x{0};
  int y{0};
  double scale{0.0};
};

class ZoomList {
private:
  int width_{0}, height_{0};
  double x_centre_{0}, y_centre_{0}, scale_{1.0};
  std::vector<Zoom> zooms_;

public:
  ZoomList(int width, int height);
  void add(const Zoom &zoom);
  std::pair<double, double> do_zoom(int x, int y);
};

class FractalCreator {
private:
  int width_, height_;
  Bitmap b;
  std::unique_ptr<std::unique_ptr<int[]>[]> fractal;
  std::unique_ptr<int[]> histogram;
  ZoomList zl;

public:
  inline int get_width() { return width_; }
  inline int get_height() { return height_; }
  FractalCreator(int width, int hight);
  virtual ~FractalCreator();
  void calc_iteration();
  void draw_fractal();
  void add_zoom(const Zoom &zoom);
  void write_bitmap(const std::string &filename);
};

struct RGB {
  double r, g, b;
  RGB operator-(const RGB &c);
};

#endif /* BITMAP_H */
