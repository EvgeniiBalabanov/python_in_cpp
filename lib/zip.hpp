#pragma once
#include <utility>

namespace py {

template<typename ContainerFirst, typename ContainerSecond>
class zip {
public:
  using value_type = std::pair<typename ContainerFirst::value_type, typename ContainerSecond::value_type>;
  class iterator {
  public:
    using first_iterator = typename ContainerFirst::iterator;
    using second_iterator = typename ContainerSecond::iterator;

    iterator(first_iterator first, second_iterator second) : first_(first), second_(second) {}
    value_type operator*() {
      return {*first_, *second_};
    }
    bool operator!=(iterator other) const {
      return first_ != other.first_ && second_ != other.second_;
    }
    iterator operator++() {
      ++first_;
      ++second_;
      return *this;
    }
  private:
    first_iterator first_;
    second_iterator second_;
  };
  zip(ContainerFirst& first, ContainerSecond& second) : first_(first), second_(second) {}

  iterator begin() {
    return iterator(first_.begin(), second_.begin());
  }
  iterator end() {
    return iterator(first_.end(), second_.end());
  }
private:
  ContainerFirst& first_;
  ContainerSecond& second_;
};

} // namespace py
