#include <range.hpp>

#include <gtest/gtest.h>

TEST(range, isCompile) {
  py::range(10);
  py::range(10, 20);
  py::range(20, 10);
}

TEST(range, oneArgument) {
  for (size_t end_in_range : {0, 1, 2, 10, 1000}) {
    size_t check_index = 0;
    for (size_t index : py::range(end_in_range)) {
      EXPECT_EQ(index, check_index++);
    }
  }
}
