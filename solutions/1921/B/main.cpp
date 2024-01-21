#include "../../../defs.hpp"

int main(void) {
  ii t;
  cin >> t;

  vector<char> cats;
  for (ii i = 0; i < t; i++) {
    ii l;
    cin >> l;

    for (ii j = 0; j < l; j++) {
      char q;
      cin >> q;
      cats.push_back(q);
    }

    ii n = 0;
    ii b = 0;
    for (ii j = 0; j < l; j++) {
      char q;
      cin >> q;
      dbg(q);
      dbg(cats);

      if (cats[j] == q) {
        continue;
      } else if (q == '0') {
        n += 1;
      } else if (q == '1') {
        b += 1;
      }
    }

    cout << max(n, b) << endl;

    cats.clear();
  }
}
