#include <range.hpp>
#include <zip.hpp>

#include <iostream>
#include <gtest/gtest.h>

TEST(zip_range, normal) {
  int start1 = 100;
  int start2 = 200;
  py::range r1(start1, 120);
  py::range r2(start2, 220);
  for (auto [num1, num2] : py::zip(r1, r2)) {
    EXPECT_EQ(num1, start1++);
    EXPECT_EQ(num2, start2++);
  }
}