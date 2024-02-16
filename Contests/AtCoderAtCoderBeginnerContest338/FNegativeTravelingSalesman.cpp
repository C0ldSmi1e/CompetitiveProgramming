/**
 * Author: C0ldSmi1e
 * Created Time: 01/30/2024 03:55:44 PM
**/

// time-limit: 6000
// problem-url: https://atcoder.jp/contests/abc338/tasks/abc338_f
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
  const int INF = (int) 1e9;
  vector<vector<int>> g(n, vector<int>(n, INF));
  for (int i = 0; i < n; i++) {
    g[i][i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;
    g[a][b] = min(g[a][b], c);
  }
  vector<vector<int>> dist(n, vector<int>(n));
  for (int start = 0; start < n; start++) {
    vector<int> t(n, INF);
    t[start] = 0;
    vector<bool> in(n);
    vector<int> q{start};
    in[start] = true;
    for (int qq = 0; qq < (int) q.size(); qq++) {
      int u = q[qq];
      in[u] = false;
      for (int v = 0; v < n; v++) {
        if (t[v] > t[u] + g[u][v]) {
          t[v] = t[u] + g[u][v];
          if (!in[v]) {
            q.emplace_back(v);
          }
        }
      }
    }
    dist[start] = t;
  }
  vector<vector<int>> dp(1 << n, vector<int>(n, INF));
  for (int i = 0; i < n; i++) {
    dp[1 << i][i] = 0;
  }
  for (int mask = 1; mask < 1 << n; mask++) {
    for (int u = 0; u < n; u++) {
      if (dp[mask][u] == INF) {
        continue;
      }
      if ((mask >> u) & 1) {
        for (int v = 0; v < n; v++) {
          if (((mask >> v) & 1) == 0 && dist[u][v] < INF / 2) {
            dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][u] + dist[u][v]);
          }
        }
      }
    }
  }
  int res = INF;
  for (int i = 0; i < n; i++) {
    res = min(res, dp[(1 << n) - 1][i]);
  }
  if (res >= INF) {
    cout << "No\n";
  } else {
    cout << res << '\n';
  }
  return 0;
}

