#include "complex.hpp"

namespace nad2000 {

Complex::Complex() : real(0), imaginary(0) {}
/* Complex &Complex::operator=(const Complex &c) { */
/*   real = c.real; */
/*   imaginary = c.imaginary; */
/*   return *this; */
/* } */
/* Complex::Complex(const double real, const double imaginary) */
/*     : real(real), imaginary(imaginary){}; */
/* Complex::Complex(const Complex &c) { *this = c; } */

/* std::ostream &operator<<(std::ostream &out, const Complex &c) { */
/*   out << c.real; */
/*   if (c.imaginary > 0.0) */
/*     out << "+"; */
/*   out << c.imaginary << "i"; */
/*   return out; */
/* } */
} // namespace nad2000

