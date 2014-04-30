#include <iostream>
using namespace std;

 
struct less_t {
  less_t(double * const & _first)
    : first(_first) {}

  bool operator() (double *const &lhs, double *const &rhs) const {
     double x1 = lhs[0] - first[0];
     double y1 = lhs[1] - first[1];
     double x2 = rhs[0] - first[0];
     double y2 = rhs[1] - first[1];

     return  y1 * x2 > y2 * x1;
  }

  double *const & first;
};
void Heapify(double**, int, int, const less_t &);
void BuildHeap( double**, int, const less_t &);

struct x_less_t;
void SearchTop(double**, int, const x_less_t &);
void PiramidSort(double**, int, const less_t &);

void Heapify(double** mas, int n, int i, const less_t &less)
{
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left >= n) {
          return; // leaf node
        }

        int smallest = left;
        if (right < n and less(mas[left], mas[right])) {
          smallest = right;
        }

        if (less(mas[i], mas[smallest])) {
          std::swap(mas[i], mas[smallest]);
          Heapify (mas, n, smallest, less);
        }
}

void BuildHeap(double** mas, int n, const less_t &less)
{
        for( int i = n/2-1; i >= 0; i-- )
        {
                Heapify(mas, n, i, less);
        }
}

struct x_less_t {
  bool operator() (double *const &lhs, double *const &rhs) const {
    if (lhs[0] < rhs[0]) return 1;
    if (lhs[0] == rhs[0] and lhs[1] < rhs[1]) return 1;
    return 0; 
  }
};

void SearchTop(double** mas, int n, const x_less_t &less)
{
        for(int i = 1; i < n; i++)
        {
                if (less(mas[i], mas[0]))
                {
                  std::swap(mas[0], mas[i]);
                }
        }
}

void PiramidSort(double** mas, int n, const less_t &less)
{
  BuildHeap(mas, n, less);
  for (int i = 1; i < n; ++i) {
    std::swap(mas[0], mas[n-i]);
    Heapify(mas, n-i, 0, less);
  }
}


int main()
{
        int n;
        cin>>n;
        double** mas = new double* [n];
        for (int i = 0; i < n; i++)
                mas[i] = new double [2];
        for (int i = 0; i < n; i++)
                for (int j = 0; j < 2; j++)
                        cin>>mas[i][j];

        SearchTop(mas, n, x_less_t());
        less_t less(mas[0]);
        PiramidSort(&mas[1], n-1, less);

        for (int i = 0; i < n; i++) {
          cout << mas[i][0] << " " << mas[i][1] << endl;
        }

        return 0;
}


