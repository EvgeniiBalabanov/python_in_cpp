#pragma once
#include <cstddef>

namespace py {

template<typename Type>
class range {
public:
  using value_type = Type;
  class iterator {
  public:
    iterator(value_type& value) : value_(value) {};
    value_type& operator*() {
      return value_;
    }
    bool operator!=(iterator other) const {
      return value_ != *other;
    }
    iterator& operator++() {
      ++value_;
      return *this;
    }
  private:
    value_type& value_;
  };

  range(value_type end) : begin_(value_type()), end_(end) {}
  range(value_type begin, value_type end) : begin_(begin), end_(end) {}

  iterator begin() {
    return iterator(begin_);
  }
  iterator end() {
    return iterator(end_);
  }
private:
  value_type begin_;
  value_type end_;
};

} // namespace py
