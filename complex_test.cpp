#include "complex.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

using namespace std;

TEST(ComplexNumbers, canCreate) { nad2000::Complex c; }
TEST(ComplexNumbers, canCreateWithValues) { nad2000::Complex c(13, 42); }
TEST(ComplexNumbers, canCreateWithOther) {
  nad2000::Complex c(13, 42);
  nad2000::Complex c2(c);
}
TEST(ComplexNumbers, runCopyInitialization) {
  nad2000::Complex c(13, 42);
  nad2000::Complex c2 = c;
}
TEST(ComplexNumbers, canAssign) {
  nad2000::Complex c(13, 42);
  nad2000::Complex c2;
  c2 = c;
}
TEST(ComplexNumbers, canPrintOut) {
  ostringstream out;
  out << nad2000::Complex c(13, 42);
  ASSERT_EQ(out.str(), "13+42i");
}
