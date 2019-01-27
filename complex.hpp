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
  Complex(const double real, const double imaginary);
  Complex(const Complex &c);
  const Complex &operator=(const Complex &c);
  // it's an overkill, the getters should be used only when there are
  // actual need for them.
  // these methods should be declared 'const'
  double getReal() const { return real; }
  double getImaginary() const { return imaginary; }
  bool operator==(const Complex &c) const;
  bool operator!=(const Complex &c) const;
  Complex operator*() const; // complex conjugate
};
std::ostream &operator<<(std::ostream &out, const Complex &c);
Complex operator+(const Complex &a, const Complex &b);
Complex operator+(const Complex &a, const double &b);
Complex operator+(const double &a, const Complex &b);
} // namespace nad2000

#endif /* COMPLEX_HCOMPLEX_H */
