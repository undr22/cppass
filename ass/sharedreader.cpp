#include "sharedreader.h"

inline std::string make_plural(std::size_t count, const std::string &word,
                               const std::string &ending) {
  return (count > 1) ? word + ending : word;
}

SharedReader &SharedReader::operator=(const SharedReader &rhs) {
  ++*rhs.counter;

  if (--*counter == 0) {
    delete reading;
    delete counter;
  }

  reading = rhs.reading;
  counter = rhs.counter;

  return *this;
}

std::ostream &operator<<(std::ostream &os, const SharedReader &sreader) {
  os << "Book name: " << sreader.reading->name() << "\t" << sreader.count()
     << make_plural(sreader.count(), " reader", "s");
  return os;
}
