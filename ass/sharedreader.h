#ifndef _SHARED_READER_
#define _SHARED_READER_

#include <cstddef>
#include <ostream>
#include <string>

class Book {
 public:
  explicit Book(const std::string &name) : book_name(name) {}

  std::string name() const { return book_name; }

 private:
  std::string book_name;
};

class SharedReader {
 public:
  explicit SharedReader(const Book &book)
      : reading(new Book(book.name())), counter(new std::size_t(1)) {}

  SharedReader(const SharedReader &sreader)
      : reading(sreader.reading), counter(sreader.counter) {
    ++*counter;
  }

  SharedReader &operator=(const SharedReader &);

  ~SharedReader() {
    --*counter;
    if (*counter == 0) {
      delete reading;
      delete counter;
    }
  }

 public:
  std::size_t count() const { return *counter; }

 public:
  Book *reading;

 private:
  std::size_t *counter;
};

std::ostream &operator<<(std::ostream &, const SharedReader &);

#endif
