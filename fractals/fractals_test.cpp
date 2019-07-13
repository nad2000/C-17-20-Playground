#include "bitmap.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <stdio.h>

using namespace std;

inline bool file_exists(const string &name) {
  return (access(name.c_str(), F_OK) != -1);
}

TEST(Bitmap, canCreate) { Bitmap b(10, 12); }
TEST(Bitmap, canWrite) {
  auto filename = "test000.bmp";
  remove(filename);
  Bitmap b(10, 12);
  ASSERT_TRUE(b.write(filename));
  ASSERT_TRUE(file_exists(filename));
}
TEST(Bitmap, canSetAPixel) {
  auto filename = "test001.bmp";
  remove(filename);
  Bitmap b(100, 100);
  for (int i = 0; i < 100; i++) {
    b.set_pixel(i, i, 255, 255, 255);
    b.set_pixel(i, 100 - i, 255, 255, 0);
    b.set_pixel(i, 49, 0, 255, 255);
    b.set_pixel(49, i, 255, 0, 255);
  }
  ASSERT_TRUE(b.write(filename));
  ASSERT_TRUE(file_exists(filename));
}
TEST(Mandelbrot, canCreate) { Mandelbrot b{}; }
TEST(Mandelbrot, canGetIterations) {
  Mandelbrot b{};
  auto i = b.get_iterations(1.0, 1.0);
  ASSERT_TRUE(i > 0);
}

/* TEST(BitmapNumbers, runCopyInitialization) { */
/*   Bitmap c(13, 42); */
/*   Bitmap c2 = c; */
/* } */
/* TEST(BitmapNumbers, canAssign) { */
/*   Bitmap c(13, 42); */
/*   Bitmap c2; */
/*   c2 = c; */
/* } */
/* TEST(BitmapNumbers, canPrintOut) { */
/*   ostringstream out; */
/*   out << Bitmap(13, 42); */
/*   ASSERT_EQ(out.str(), "13+42i"); */
/* } */
/* TEST(BitmapNumbers, canSumUp) { */
/*   ostringstream out; */
/*   auto c = Bitmap(13, 42) + Bitmap(-3, -40); */
/*   out << c; */
/*   ASSERT_EQ(out.str(), "10+2i"); */
/* } */
/* TEST(BitmapNumbers, canSumUpWithReal) { */
/*   ostringstream out; */
/*   auto c = Bitmap(13, 42) + (-9.5); */
/*   out << c; */
/*   ASSERT_EQ(out.str(), "3.5+42i"); */
/*   out.clear(); */
/*   out.str(""); */
/*   out << -9.7 + Bitmap(13, 42); */
/*   ASSERT_EQ(out.str(), "3.3+42i"); */
/* } */
/* TEST(BitmapNumbers, canCheckIfEqual) { */
/*   ASSERT_TRUE((Bitmap(13, 42) + Bitmap(-3, -40)) == Bitmap(10, 2)); */
/*   ASSERT_FALSE((Bitmap(13, 42) + Bitmap(-3, -40)) == Bitmap(10, 12)); */
/*   ASSERT_FALSE((Bitmap(13, 42) + Bitmap(-3, -40)) == Bitmap(1, 3)); */
/* } */
/* TEST(BitmapNumbers, canCheckIfNotEqual) { */
/*   ASSERT_FALSE((Bitmap(13, 42) + Bitmap(-3, -40)) != Bitmap(10, 2)); */
/*   ASSERT_TRUE((Bitmap(13, 42) + Bitmap(-3, -40)) != Bitmap(10, 12)); */
/*   ASSERT_TRUE((Bitmap(13, 42) + Bitmap(-3, -40)) != Bitmap(1, 3)); */
/* } */
/* TEST(BitmapNumbers, complexConjugate) { */
/*   ASSERT_EQ(*Bitmap(13, 42), Bitmap(13, -42)); */
/* } */
