#include <enumerate.hpp>

#include <vector>
#include <string>
#include <iostream>
#include <gtest/gtest.h>

TEST(enumerate, standart) {
  std::vector<std::string> words{"Hello", "World", "!"};
  for (auto [counter, word] : py::enumerate(words)) {
    std::cout << counter << ". " << word << std::endl;
  }
}
