#include <zip.hpp>

#include <string>
#include <gtest/gtest.h>
#include <iostream>

TEST(zip, isCompile) {
  // py::zip(std::string("Simple text"), std::string("Simple text"));
  // py::zip(std::string("Any text"), std::string("Different text"));
  // py::zip(std::string("Any text"), std::vector<size_t>{0,5,4,3,5});
}

TEST(zip, normal) {
  std::vector<int> arr{1,2,5,10};
  std::string str("abcd");
  for (auto [num, letter] : py::zip(arr, str)) {
    std::cout << std::string(num, letter) << std::endl;
  }
}