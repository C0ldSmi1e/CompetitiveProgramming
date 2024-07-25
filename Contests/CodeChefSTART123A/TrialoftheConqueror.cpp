/**
 * Author: C0ldSmi1e
 * Created Time: 02/28/2024 07:08:58 AM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START123A/problems/CONQUEROR
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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].emplace_back(b);
      g[b].emplace_back(a);
    }
    vector<int> mnd(n, n);
    vector<vector<int>> dp(n, vector<int>(2));
    auto Dfs = [&](auto& self, int u, int par, int d) -> void {
      bool leaf = true;
      for (auto& v : g[u]) {
        if (v == par) {
          continue;
        }
        leaf = false;
        self(self, v, u, d + 1);
        mnd[u] = min(mnd[u], mnd[v]);
      }
      if (leaf) {
        mnd[u] = d;
        dp[u][0] = dp[u][1] = 1;
        return;
      }
      for (auto& v : g[u]) {
        if (v == par) {
          continue;
        }
        if (d + k >= mnd[v]) {
          dp[u][1] += dp[v][1];
        }
      }
      for (auto& v : g[u]) {
        if (v == par) {
          continue;
        }
        int t = dp[u][1];
        if (d + k >= mnd[v]) {
          t -= dp[v][1];
        }
        dp[u][0] = max(dp[u][0], t + dp[v][0]);
      }
    };
    Dfs(Dfs, 0, -1, 0);
    cout << dp[0][0] << '\n';
  }
  return 0;
}
