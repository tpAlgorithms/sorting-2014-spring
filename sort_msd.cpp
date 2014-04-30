#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

struct less_t {
  less_t(const size_t &_offset) :offset(_offset) {}
  bool operator() (const std::string &lhs, const std::string &rhs) const {
    return lhs.c_str()[offset] < rhs.c_str()[offset];
  }

  size_t offset;
};

void counting_sort(std::string *data, int size, const less_t &less) {
  std::sort(data, data + size, less);
}


void msd_sort_(std::string *data, int size, size_t offset);

void msd_sort(std::string *data, int size) {
  return msd_sort_(data, size, 0);
}

void ignore_(std::string *data, int size, size_t offset) {
  std::cout << "ignore_(" << data << ", " << size << ", " << offset << std::endl;
  for (size_t i = 0; i < size; ++i) {
    std::cout << data[i] << std::endl;
  }
  std::cout << "}}}}" << std::endl;;
}
 
void msd_sort_(std::string *data, int size, size_t offset) {
  std::cout << "msd_sort_(" << data << ", " << size << ", " << offset << std::endl;
  for (size_t i = 0; i < size; ++i) {
    std::cout << data[i] << std::endl;
  }
  std::cout << "}}}}" << std::endl;;
  
  counting_sort(data, size, less_t(offset));
  
  size_t start_pos = 0 ;
  char ch = data[0].c_str()[offset];
  for (size_t i = 1; i < size + 1; ++i) {
    if (i == size or data[i].c_str()[offset] != ch) {
      if (i - start_pos > 1 and ch != '\0') {
        msd_sort_(&data[start_pos], i - start_pos, offset + 1);
      } else {
        ignore_(&data[start_pos], i - start_pos, offset + 1);
      }
      start_pos = i;
      ch = data[i].c_str()[offset];
    }
  }
}

int main() {

  std::vector<std::string> pool;
  while(std::cin.good()) {
    std::string str;
    std::getline(std::cin, str);
    if (str.empty() and std::cin.eof()) break;
    pool.push_back(str);
  }

  msd_sort(&pool[0], pool.size());
 
  for (size_t i = 0; i < pool.size(); ++i) {
    std::cout << pool[i] << std::endl;
  }

  return 0;
}














