/**
 * Author: C0ldSmi1e
 * Created Time: 03/06/2024 10:47:50 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc341/tasks/abc341_f
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

  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  vector<int> w(n);
  for (auto& u : w) {
    cin >> u;
  }
  vector<int> a(n);
  for (auto& u : a) {
    cin >> u;
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return w[i] < w[j];
  });
  vector<long long> cnt(n);
  for (auto& u : order) {
    vector<long long> dp(w[u]);
    vector<int> ww;
    vector<int> vv;
    for (auto& v : g[u]) {
      if (w[v] < w[u]) {
        ww.emplace_back(w[v]);
        vv.emplace_back(cnt[v]);
      }
    }
    dp[0] = 1;
    int m = (int) ww.size();
    for (int i = 0; i < m; i++) {
      auto ndp = dp;
      for (int j = 0; j < w[u]; j++) {
        if (j + ww[i] < w[u]) {
          ndp[j + ww[i]] = max(ndp[j + ww[i]], dp[j] + vv[i]);
        }
      }
      swap(ndp, dp);
    }
    cnt[u] = *max_element(dp.begin(), dp.end());
  }
  debug(cnt);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += cnt[i] * a[i];
  }
  cout << ans << '\n';
  return 0;
}
