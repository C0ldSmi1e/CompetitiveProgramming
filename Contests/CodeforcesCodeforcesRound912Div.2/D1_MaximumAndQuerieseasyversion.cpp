/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-30 11:02:13
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1903/problem/D1
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n, q;
  cin >> n >> q;
  vector<long long> a(n);
  for (auto& u : a) {
    cin >> u;
  }
  while (q--) {
    long long k;
    cin >> k;
    vector<bool> alive(n, true);
    long long res = 0;
    for (int bit = 62; bit >= 0; bit--) {
      long long need = 0;
      vector<int> cand;
      for (int i = 0; i < n; i++) {
        if (need > k) {
          break;
        }
        if (!alive[i]) {
          need += (1ll << bit);
          continue;
        }
        if (((a[i] >> bit) & 1) == 0) {
          need += (1ll << bit) - (((1ll << bit) - 1) & a[i]);
          cand.emplace_back(i);
        }
      }
      if (k >= need) {
        res |= (1ll << bit);
        k -= need;
        for (auto& u : cand) {
          alive[u] = false;
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}
