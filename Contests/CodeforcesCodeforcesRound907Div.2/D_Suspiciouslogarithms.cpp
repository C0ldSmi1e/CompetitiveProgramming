/**
 * Author: C0ldSmi1e
 * Created Time: 2023-10-30 14:56:09
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1891/problem/D
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);

  vector<array<long long, 3>> a;
  for (int k = 2; k < 60; k++) {
    long long L = (1ll << k);
    long long R = (1ll << (k + 1)) - 1;
    long long x = L;
    int gL = -1;
    while (x > 0) {
      x /= k;
      gL += 1;
    }
    int gR = -1;
    x = R;
    while (x > 0) {
      x /= k;
      gR += 1;
    }
    if (gL == gR) {
      a.push_back({L, R, gL});
    } else {
      x = 1;
      for (int i = 0; i < gR; i++) {
        x *= k;
      }
      a.push_back({L, x - 1, gL});
      if (x < R) {
        a.push_back({x, R, gR});
      }
    }
  }
  int q;
  cin >> q;
  const int mod = (int) 1e9 + 7;
  debug(a);
  while (q--) {
    long long l, r;
    cin >> l >> r;
    int res = 0;
    for (auto& [L, R, c] : a) {
      long long sl = max(l, L);
      long long sr = min(r, R);
      if (sl <= sr) {
        res = (res + 1ll * (sr - sl + 1) * c) % mod;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
