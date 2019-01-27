#include "complex.hpp"

namespace nad2000 {

Complex::Complex() : real(0), imaginary(0) {}
const Complex &Complex::operator=(const Complex &c) {
  real = c.real;
  imaginary = c.imaginary;
  return *this; // to enable chaining
}
Complex::Complex(const double real, const double imaginary)
    : real(real), imaginary(imaginary){};
Complex::Complex(const Complex &c) {
  real = c.real;
  imaginary = c.imaginary;
}

std::ostream &operator<<(std::ostream &out, const Complex &c) {
  out << c.getReal();
  if (c.getImaginary() > 0.0)
    out << "+";
  out << c.getImaginary() << "i";
  return out;
}
Complex operator+(const Complex &a, const Complex &b) {
  return Complex(a.getReal() + b.getReal(),
                 a.getImaginary() + b.getImaginary());
}
Complex operator+(const Complex &a, const double &b) {
  return Complex(a.getReal() + b, a.getImaginary());
}
Complex operator+(const double &a, const Complex &b) {
  return Complex(a + b.getReal(), b.getImaginary());
}
bool Complex::operator==(const Complex &c) const {
  return real == c.real && imaginary == c.imaginary;
}
bool Complex::operator!=(const Complex &c) const {
  return real != c.real || imaginary != c.imaginary;
}
Complex Complex::operator*() const { return Complex(real, -imaginary); }
} // namespace nad2000

