#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

struct less_func_t {
  bool operator()(const int &lhs, const int &rhs) const {
    return lhs < rhs;
  }
};

template <typename less_t>
void merge(int *a_data, int a_size, int *b_data, int b_size, int *result, const less_t &less) {
  int i = 0;
  int j = 0;
  for (; i < a_size && j < b_size; ) {
    if (less(b_data[j], a_data[i])) {
      result[i + j] = b_data[j];
      ++j;
    } else {
      result[i + j] = a_data[i];
      ++i;
    }
  }
  for (; i < a_size; ++i) { result[i+j] = a_data[i]; }
  for (; j < b_size; ++j) { result[i+j] = b_data[j]; }
}

template <typename less_t>
void merge_sort(int *data, size_t size, const less_t &less) {
  int * tmp = new int[size];
  size_t iter_counter = 0;
  for(size_t chunk_size = 1;  chunk_size < size; chunk_size *= 2, ++iter_counter) {
    for(size_t offset = 0; offset + chunk_size < size; offset += 2 * chunk_size) {
      //(offset, offset + chunk_size);
      //(offset + chunk_size, std::min(size, offset + 2 * chunk_size));
      size_t second_size = std::min(size, offset + 2 * chunk_size) - offset - chunk_size;
      merge(&data[offset], chunk_size, &data[offset + chunk_size], second_size, &tmp[offset], less);
    }
    std::swap(data, tmp);
  }
  if (iter_counter % 2) {
    std::swap(data, tmp);
    memcpy(&data[0], &tmp[0], size * sizeof(int));
  }
  delete [] tmp;
}

int main() {
  std::vector<int> data;
  int value;
  while(1==scanf("%d", &value)) {
    data.push_back(value);
  }

//  less_func_t less;
  merge_sort(&data[0], data.size(), less_func_t());

  for(int i = 0;i < data.size(); ++i) {
    printf("%d\n", data[i]);
  }
  return 0;
};
