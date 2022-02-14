#pragma once
#include <tuple>

namespace py {

namespace impl {

template <typename Iterator>
class IteratorBase : public Iterator {
 public:
  IteratorBase(Iterator iterator) : iterator_(iterator) {}

  bool operator!=(const IteratorBase& other) const {
    return iterator_ != other.iterator_;
  }

  auto operator*() const { return std::tie(*iterator_); }

  IteratorBase& operator++() {
    ++iterator_;
    return *this;
  }

 private:
  Iterator iterator_;
};

template <typename Head, typename... Iterators>
class iterator : private IteratorBase<Head>, private iterator<Iterators...> {
 public:
  iterator(Head head, Iterators... iterators)
      : iterator<Iterators...>(iterators...), IteratorBase<Head>(head){};

  bool operator!=(const iterator& other) const {
    const auto& derived = *dynamic_cast<const iterator<Iterators...>*>(&other);
    return IteratorBase<Head>::operator!=(other) &&
           iterator<Iterators...>::operator!=(derived);
  }

  auto operator*() const {
    return std::tuple_cat(IteratorBase<Head>::operator*(),
                          iterator<Iterators...>::operator*());
  }

  iterator& operator++() {
    IteratorBase<Head>::operator++();
    iterator<Iterators...>::operator++();
    return *this;
  }
};

template <typename Head>
class iterator<Head> : public IteratorBase<Head> {
 public:
  iterator(Head head) : IteratorBase<Head>(head){};
};

}  // namespace impl

template <typename... Containers>
class zip : private std::reference_wrapper<Containers>... {
 public:
  zip(Containers&... containers)
      : std::reference_wrapper<Containers>(std::ref(containers))... {}

  auto begin() {
    return impl::iterator(std::reference_wrapper<Containers>::get().begin()...);
  }

  auto end() {
    return impl::iterator(std::reference_wrapper<Containers>::get().end()...);
  }
};

}  // namespace py
