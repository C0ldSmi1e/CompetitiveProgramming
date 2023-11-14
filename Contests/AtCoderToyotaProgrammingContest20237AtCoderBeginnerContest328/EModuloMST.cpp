/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-12 11:49:23
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc328/tasks/abc328_e
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

  int n, m;
  long long k;
  cin >> n >> m >> k;
  const long long INF = (long long) 1e18;
  vector<vector<long long>> g(n, vector<long long>(n, INF));
  for (int i = 0; i < m; i++) {
    int a, b;
    long long c;
    cin >> a >> b >> c;
    --a;
    --b;
    g[a][b] = g[b][a] = c;
  }
  vector<set<long long>> dp(1 << n);
  for (int i = 0; i < n; i++) {
    dp[1 << i].emplace(0);
  }
  for (int mask = 1; mask < 1 << n; mask++) {
    for (int u = 0; u < n; u++) {
      if ((mask >> u) & 1) {
        for (int v = 0; v < n; v++) {
          if (g[u][v] == INF) {
            continue;
          }
          if (((mask >> v) & 1) == 0) {
            for (auto& x : dp[mask]) {
              dp[mask | (1 << v)].emplace((x + g[u][v]) % k);
            }
          }
        }
      }
    }
  }
  long long res = INF;
  for (auto& x : dp[(1 << n) - 1]) {
    res = min(res, x % k);
  }
  cout << res << '\n';
  return 0;
}
