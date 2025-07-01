#include <iostream>
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

    std::vector<int> s;
    char c;
    for (long long j = 0; j < n; j++) {
      cin >> c;
      if (c == '1')
        s.push_back(j);
    }

    bool is_bob = false;
    for (int j = 0; j + k < s.size(); j++) {
      if (s[j + k] - s[j] > k) {
        is_bob = true;
        break;
      }
    }

    if (is_bob)
      cout << "Bob" << endl;
    else
      cout << "Alice" << endl;
  }
}