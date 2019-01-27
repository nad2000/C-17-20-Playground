#include "complex.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

using namespace std;
using namespace nad2000;

TEST(ComplexNumbers, canCreate) { Complex c; }
TEST(ComplexNumbers, canCreateWithValues) { Complex c(13, 42); }
TEST(ComplexNumbers, canCreateWithOther) {
  Complex c(13, 42);
  Complex c2(c);
}
TEST(ComplexNumbers, runCopyInitialization) {
  Complex c(13, 42);
  Complex c2 = c;
}
TEST(ComplexNumbers, canAssign) {
  Complex c(13, 42);
  Complex c2;
  c2 = c;
}
TEST(ComplexNumbers, canPrintOut) {
  ostringstream out;
  out << Complex(13, 42);
  ASSERT_EQ(out.str(), "13+42i");
}
TEST(ComplexNumbers, canSumUp) {
  ostringstream out;
  auto c = Complex(13, 42) + Complex(-3, -40);
  out << c;
  ASSERT_EQ(out.str(), "10+2i");
}
TEST(ComplexNumbers, canSumUpWithReal) {
  ostringstream out;
  auto c = Complex(13, 42) + (-9.5);
  out << c;
  ASSERT_EQ(out.str(), "3.5+42i");
  out.clear();
  out.str("");
  out << -9.7 + Complex(13, 42);
  ASSERT_EQ(out.str(), "3.3+42i");
}
TEST(ComplexNumbers, canCheckIfEqual) {
  auto check = (Complex(13, 42) + Complex(-3, -40)) == Complex(10, 2);
  ASSERT_TRUE(check);
}
