/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-24 08:04:11
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1901/problem/E
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

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      --u;
      --v;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    const long long INF = (long long) 1e18;
    vector<long long> dp(n, -INF);
    long long res = 0;
    auto Dfs = [&](auto& self, int u, int fa) -> void {
      vector<long long> son;
      for (auto& v : g[u]) {
        if (v != fa) {
          self(self, v, u);
          son.emplace_back(dp[v]);
        }
      }
      sort(son.rbegin(), son.rend());
      dp[u] = a[u];
      res = max(res, a[u]);
      if ((int) son.size() > 0) {
        dp[u] = max(dp[u], son[0]);
        res = max(res, son[0] + a[u]);
      }
      if ((int) son.size() > 1) {
        dp[u] = max(dp[u], a[u] + son[0] + son[1]);
        res = max(res, son[0] + son[1]);
      }
      if ((int) son.size() > 2) {
        long long ans = a[u] + son[0] + son[1] + son[2];
        for (int i = 3; i < (int) son.size(); i++) {
          ans += max(0ll, son[i]);
        }
        dp[u] = max(dp[u], ans);
        res = max(res, ans);
      }
    };
    Dfs(Dfs, 0, -1);
    cout << res << '\n';
  }
  return 0;
}
