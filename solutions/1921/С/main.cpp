#include "../../../defs.hpp"

void solve(ii _) {
  ll time = 0;
  ll n, f, a, b;
  cin >> n >> f >> a >> b;

  // Could be optimized to have memory O(1) but I'm lazy :p
  vll ms;
  for (ii i = 0; i < n; i++) {
    ll m;
    cin >> m;
    ms.pb(m);
  }

  for (auto &m : ms) {
    ll duration = m - time;

    ll charge_spend_on = duration * a;
    ll charge_spend_off = b;
    f -= min(charge_spend_off, charge_spend_on);

    if (f <= 0) {
      NO;
      return;
    }

    time = m;
  }

  YES
}

int main() {
  ii t;
  cin >> t;

  for (ii _ = 0; _ < t; _++) {
    solve(_);
  }
}