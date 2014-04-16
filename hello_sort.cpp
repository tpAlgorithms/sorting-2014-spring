#include <stdint.h>
#include <iostream>
#include <algorithm>
#include <vector>

typedef int* iterator_t;

typedef bool (*less_func_t)(const int& a, const int& b);

bool less_func(const int& lhs, const int& rhs) {
  return lhs > rhs;
}


//template <typename less_type>
//void sort(iterator_t &begin, size_t size, less_type const &less);

//template <typename less_type>
//typedef less_func_t less_type;
void sort(iterator_t begin, iterator_t end, less_func_t less) {
  std::sort(begin, end, less);
}

/*
template <typename less_type>
void sort(iterator_t &begin, size_t size, less_t const &less) {
  iterator_t end = begin;
  for (size_t i = 0; i < size; ++i) { 
    ++end;
//    end = it + 1;
  }

  std::sort(begin, end, less);
}
*/


int main() {
  
  std::vector<int> data;

//  while (1) {
  for(;;) {    
    int value;
    std::cin >> value;

    if (std::cin.eof()) break;
    data.push_back(value);
  }

  
  sort(&data[0], &data[data.size()], less_func);


  for (size_t i = 0; i < data.size(); ++i) {
    std::cout << data[i] << std::endl;
  }

  return 0;
}
