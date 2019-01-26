#ifndef COMPLEX_H
#define COMPLEX_H
#include <fstream>

namespace nad2000 {

class Complex {
private:
  double real;
  double imaginary;

public:
  Complex();
  /* Complex(const double real, const double imaginary); */
  /* Complex(const Complex &c); */
  /* Complex &operator=(const Complex &c); */
  /* friend std::ostream &operator<<(std::ostream &out, const Complex &c); */
};
} // namespace nad2000

#endif /* COMPLEX_HCOMPLEX_H */
