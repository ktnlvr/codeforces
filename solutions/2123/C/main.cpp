#include <algorithm>
#include <iostream>
#include <limits>
#include <set>
#include <vector>

using namespace std;

template <typename T> ostream &operator<<(ostream &out, vector<T> &v) {
  out << "[";
  if (v.size() != 0) {
    for (size_t i = 0; i < v.size() - 1; i++)
      out << v[i] << ", ";
    out << v[v.size() - 1];
  }
  out << "]";

  return out;
}

int main() {
  long long t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long n, k;
    cin >> n >> k;

    std::vector<int> as(n);
    for (int j = 0; j < n; j++)
      cin >> as[j];

    int mi = std::numeric_limits<int>::max(),
        ma = std::numeric_limits<int>::min();

    std::vector<int> mas(n);
    std::vector<int> mis(n);

    mis[0] = as[0];
    for (int j = 1; j < n; j++)
      mis[j] = min(as[j], mis[j - 1]);

    mas[n - 1] = as[n - 1];
    for (int j = n - 2; j >= 0; j--)
      mas[j] = max(as[j], mas[j + 1]);

    for (int j = 0; j < n; j++)
      cout << !((mis[j] < as[j]) && (as[j] < mas[j]));

    cout << endl;
  }
}