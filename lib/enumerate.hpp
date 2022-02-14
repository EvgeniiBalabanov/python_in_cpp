#pragma once
#include <cstddef>
#include <utility>

namespace py {

template <typename Container>
class enumerate {
 public:
  using base_iterator = typename Container::iterator;
  class iterator {
   public:
    iterator(size_t counter, base_iterator iterator)
        : counter_(counter), base_iterator_(iterator){};
    auto operator*() { return std::make_pair(counter_, *base_iterator_); }
    bool operator!=(iterator other) const {
      return base_iterator_ != other.base_iterator_;
    }
    iterator& operator++() {
      ++counter_;
      ++base_iterator_;
      return *this;
    }

   private:
    size_t counter_;
    base_iterator base_iterator_;
  };

  enumerate(Container& container) : container_(container) {}

  iterator begin() { return iterator(0, container_.begin()); }

  iterator end() { return iterator(container_.size(), container_.end()); }

 private:
  Container& container_;
};

}  // namespace py
