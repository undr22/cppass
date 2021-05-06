#include "randv.h"

randv &randv::shuffle() {
  std::random_device rd;
  std::mt19937 g(rd());

  std::shuffle(v.begin(), v.end(), g);

  return *this;
}

randv &randv::bubble_sort() {
  if (v.empty()) return *this;

  for (int i = v.size() - 1; i > 0; --i) {
    for (int j = 0; j < i; ++j) {
      if (v[j] > v[j + 1]) std::swap(v[j], v[j + 1]);
    }
  }

  return *this;
}

randv &randv::selection_sort() {
  if (v.empty()) return *this;

  for (int i = v.size() - 1; i > 0; --i) {
    int max_idx = i;
    for (int j = 0; j < i; ++j) {
      if (v[j] > v[max_idx]) max_idx = j;
    }
    std::swap(v[max_idx], v[i]);
  }

  return *this;
}

randv &randv::insertion_sort() {
  if (v.empty()) return *this;

  for (int i = 1; i < v.size(); ++i) {
    int tmp = v[i];
    int j = 0;
    for (j = i - 1; j >= 0; --j) {
      if (v[j] > tmp) {
        v[j + 1] = v[j];
      } else {
        break;
      }
    }
    v[j + 1] = tmp;
  }

  return *this;
}

randv &randv::merge_sort() {
  if (v.size() <= 1) return *this;

  int size = v.size();
  randv rv_l(v.begin(), v.begin() + size / 2);
  randv rv_r(v.begin() + size / 2, v.end());
  merge(rv_l.merge_sort(), rv_r.merge_sort());

  return *this;
}

void randv::merge(const randv &rv_l, const randv &rv_r) {
  int idx = 0, idx_l = 0, idx_r = 0;
  while (idx < v.size()) {
    if (idx_l < rv_l.size() &&
        (idx_r == rv_r.size() || rv_l[idx_l] < rv_r[idx_r])) {
      v[idx++] = rv_l[idx_l++];
    } else {
      v[idx++] = rv_r[idx_r++];
    }
  }
}

randv &randv::quick_sort() {
  if (v.empty()) return *this;

  do_quicksort(0, v.size() - 1);

  return *this;
}

void randv::do_quicksort(int idx_l, int idx_r) {
  if (idx_l < idx_r) {
    int idx_pivot = partition(idx_l, idx_r);
    do_quicksort(idx_l, idx_pivot - 1);
    do_quicksort(idx_pivot + 1, idx_r);
  }
}

int randv::partition(int idx_l, int idx_r) {
  int res = idx_l, pivot = v[idx_r];
  for (int i = idx_l; i < idx_r; ++i) {
    if (v[i] <= pivot) std::swap(v[i], v[res++]);
  }
  std::swap(v[res], v[idx_r]);

  return res;
}

std::ostream &operator<<(std::ostream &os, const randv &rv) {
  os << '[';
  for (int i = 0; i < rv.size() - 1; ++i) {
    os << rv[i] << ", ";
  }
  os << rv[rv.size() - 1] << ']';

  return os;
}