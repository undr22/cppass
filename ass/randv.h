#ifndef _RANDV_H_
#define _RANDV_H_

#include <algorithm>
#include <ostream>
#include <random>
#include <vector>

class randv {
 public:
  randv(size_t size = 0) : v(std::vector<int>(size)) {
    for (int i = 0; i < size; ++i) {
      v[i] = i;
    }
    shuffle();
  }

  randv(const std::vector<int>::iterator begin,
        const std::vector<int>::iterator end)
      : v(begin, end) {}

  std::vector<int> vec() const { return v; }

  size_t size() const { return v.size(); }

  bool empty() const { return v.empty(); }
  void clear() { v.clear(); }

  void push_back(int val) { v.push_back(val); }
  void pop_back() { v.pop_back(); }

  int operator[](size_t idx) const { return v[idx]; }
  int operator[](size_t idx) { return v[idx]; }

  randv &operator++() {
    v.push_back(v.size());
    return *this;
  }
  randv operator++(int) {
    randv tmp = *this;
    ++*this;
    return tmp;
  }

  randv &shuffle();

  randv &sort() { return quick_sort(); }
  randv &bubble_sort();
  randv &selection_sort();
  randv &insertion_sort();
  randv &merge_sort();
  randv &quick_sort();

 private:
  // helper function for merge_sort()
  void merge(const randv &, const randv &);

  // helper functions for quick_sort()
  void do_quicksort(int, int);
  int partition(int, int);

 private:
  std::vector<int> v;
};

std::ostream &operator<<(std::ostream &, const randv &);

#endif
