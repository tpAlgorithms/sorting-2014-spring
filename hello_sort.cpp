#include <stdint.h>
#include <iostream>
#include <algorithm>

typedef int* iterator_t;

void sort(iterator_t &begin, size_t size);

void sort(iterator_t &begin, iterator_t &end) {
  size_t length = 0;
  for (iterator_t it = begin; it != end; ++it) { ++length; }

  //length = std::distance(begin, end);

  sort(begin, length);
}

void sort(iterator_t &begin, size_t size) {
  iterator_t end = begin;
  for (size_t i = 0; i < size; ++i) { 
    ++end;
//    end = it + 1;
  }

  std::sort(begin, end);
}



int main() {
  
  size_t size;
  std::cin >> size;

  int *data = new int[size];

  for (size_t i = 0; i < size; ++i) {
    std::cin >> data[i];
  }


  std::sort(data, &data[size]);


  for (size_t i = 0; i < size; ++i) {
    std::cout << data[i] << std::endl;
  }

  return 0;
}
