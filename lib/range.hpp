#pragma once
#include <cstddef>

namespace py {

class range {
public:
  class iterator {
  public:
    iterator(size_t value) : value_(value) {};
    size_t operator*() const {
      return value_;
    }
    bool operator!=(iterator other) {
      return value_ != *other;
    }
    bool operator++() {
      return value_++;
    }
  private:
    size_t value_;
  };

  range(size_t end) : begin_(0), end_(end) {}
  range(size_t begin, size_t end) : begin_(begin), end_(end) {}

  iterator begin() const {
    return iterator(begin_);
  }
  iterator end() const {
    return iterator(end_);
  }
private:
  size_t begin_;
  size_t end_;
};

} // namespace py
