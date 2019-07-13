#ifndef BITMAP_H
#define BITMAP_H

#include <cstdint>
#include <memory>
#include <string>

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
  bool write(std::string filename);
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
};

#endif /* BITMAP_H */
