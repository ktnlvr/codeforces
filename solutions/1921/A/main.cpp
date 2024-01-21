#include "../../../defs.hpp"

int main(void) {
  ii t;
  cin >> t;

  for (ii i = 0; i < t; i++) {
    ii minx, miny, maxx, maxy;

    cin >> minx >> miny;
    maxx = minx;
    maxy = miny;

    for (ii j = 0; j < 3; j++) {
      ii x, y;
      cin >> x >> y;
      maxx = max(maxx, x);
      maxy = max(maxy, y);
      minx = min(minx, x);
      miny = min(miny, y);
    }

    cout << (maxx - minx) * (maxy - miny) << endl;
  }

  return 0;
}
