#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    long long n, j, k;

    cin >> n >> j >> k;
    if (k == 1) {
      long long xj = 0;
      long long max = -1;

      for (int m = 0; m < n; m++) {
        long long x;
        cin >> x;
        if (x > max)
          max = x;
        if (m == j - 1)
          xj = x;
      }

      if (xj == max) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      for (int m = 0; m < n; m++) {
        long long x;
        cin >> x;
      }

      cout << "YES" << endl;
    }
  }
}