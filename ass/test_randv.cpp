#include <iostream>

#include "randv.h"

int main() {
  randv rv(10);
  std::cout << rv << std::endl;
  std::cout << rv.quick_sort() << std::endl;
  std::cout << rv.shuffle() << std::endl;
  std::cout << rv.quick_sort() << std::endl;

  return 0;
}
