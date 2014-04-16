#include <vector>
#include <iostream>

#include <iterator>
#include <algorithm>


bool less_func(const int& lhs, const int& rhs) {
  return lhs < rhs;
}

template <class less_t>
int split(int* a, int size, const less_t &less) {
  int i = 1;  
  int j = 1;
  //begin-------i--------j--------end
  
  int &value = a[0];

  for (; j < size ;) {
    if (! less(value, a[j])) {
      std::swap(a[i], a[j]);
      ++i;
      ++j;
    } else {
      ++j;
    }
  }
  std::swap(a[0], a[i - 1]);
  return i - 1;
}


template <class less_t>
void qsort(int* begin, int size, const less_t& less) {
//  std::cerr << "qsort: " << size << " - ";
//  std::copy(begin, begin + size, std::ostream_iterator<int>(std::cerr, " "));
//  std::cerr << "\n";

  if (size < 2) return;

  int pivot_pos = split(begin, size, less);

//  std::cerr << pivot_pos << std::endl;

  qsort(begin, pivot_pos, less);
  qsort(&begin[pivot_pos + 1], size - pivot_pos - 1, less);
  
  
//  std::cerr << "orted: i" << size << " - ";
//  std::copy(begin, begin + size, std::ostream_iterator<int>(std::cerr, " "));
//  std::cerr << "\n";
}


int main() {
  std::vector<int> data;

//  while (1) {
  for(;;) {    
    int value;
    std::cin >> value;

    if (std::cin.eof()) break;
    data.push_back(value);
  }

  
  qsort(&data[0], data.size(), less_func);


  for (size_t i = 0; i < data.size(); ++i) {
    std::cout << data[i] << std::endl;
  }

  return 0;

}
