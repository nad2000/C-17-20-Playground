#ifndef RING_H
#define RING_H

#include <vector>

template <typename T> class ring {
private:
  int s; // size
  int c; // current
  T *v;  // values

public:
  class iterator;
  ring(int size) : s(size), c(0) { v = new T[size]; };
  virtual ~ring() { delete[] v; };
  void add(const T &el) {
    v[c++] = el;
    if (c == s)
      c = 0;
  }
  T &get(int i) const { return v[i]; }
  int size() { return s; }
  iterator begin() { return iterator(0, *this); }
  iterator end() { return iterator(s, *this); }
};

template <typename T> class ring<T>::iterator {
private:
  int pos;
  const ring &r;

public:
  iterator(int pos, const ring<T> &r) : pos(pos), r(r) {}
  // postfix ++
  iterator &operator++(int) {
    pos++;
    return *this;
  }
  // prefix ++
  iterator &operator++() {
    pos++;
    return *this;
  }
  T &operator*() { return r.get(pos); }
  bool operator!=(const iterator &other) const { return pos != other.pos; }
  bool operator==(const iterator &other) const { return pos == other.pos; }
};

#endif /* RING_H */
