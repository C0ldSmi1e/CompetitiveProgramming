/**
 * Author: C0ldSmi1e
 * Created Time: 04/14/2025 05:26:29 PM
**/

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

  const int N = 100010;
  vector<vector<int>> factors(N);
  for (int i = 1; i < N; i++) {
    for (int j = 1; j <= i / j; j++) {
      if (i % j == 0) {
        factors[i].emplace_back(j);
        if (i / j != j) {
          factors[i].emplace_back(i / j);
        }
      }
    }
  }
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mp[a[i]].emplace_back(i);
    }
    while (q--) {
      int x, l, r;
      cin >> x >> l >> r;
      --l;
      --r;
      vector<int> idx;
      for (auto& u : factors[x]) {
        if (mp.count(u)) {
          auto it = lower_bound(mp[u].begin(), mp[u].end(), l);
          if (it != mp[u].end()) {
            idx.emplace_back(*it);
          }
        }
      }
      sort(idx.begin(), idx.end());
      long long ans = 0;
      int i = l;
      for (auto& j : idx) {
        if (j > r) {
          break;
        }
        ans += 1ll * (j - i) * x;
        while (x % a[j] == 0) {
          x /= a[j];
        }
        i = j;
      }
      ans += 1ll * (r + 1 - i) * x;
      cout << ans << '\n';
    }
  }
  return 0;
}
