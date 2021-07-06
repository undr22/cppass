#include <iostream>

#include "sharedreader.h"

int main() {
  Book book_1("Bible");
  SharedReader sr1(book_1);
  std::cout << sr1 << std::endl;
  std::cout << std::endl;

  SharedReader sr2(sr1);
  std::cout << sr1 << std::endl;
  std::cout << sr2 << std::endl;
  std::cout << std::endl;

  {
    SharedReader sr3(sr2);
    std::cout << sr3 << std::endl;
    std::cout << sr2 << std::endl;
    std::cout << sr1 << std::endl;
    std::cout << std::endl;
  }

  std::cout << sr1 << std::endl;
  std::cout << sr2 << std::endl;
  std::cout << std::endl;

  Book book_2("What if?");
  SharedReader sr4(book_2);
  std::cout << sr4 << std::endl;
  sr4 = sr1;
  std::cout << sr4 << std::endl;
  std::cout << sr1 << std::endl;
  std::cout << sr2 << std::endl;

  return 0;
}
