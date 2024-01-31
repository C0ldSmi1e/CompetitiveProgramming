/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-28 07:15:16
**/

// time-limit: 4000
// problem-url: https://codeforces.com/contest/1915/problem/G
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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a].emplace_back(b, c);
      g[b].emplace_back(a, c);
    }
    vector<int> s(n);
    int mx = 0;
    for (auto& u : s) {
      cin >> u;
      mx = max(mx, u);
    }
    const long long INF = (long long) 1e18;
    vector<vector<long long>> dp(n, vector<long long>(mx + 1, INF));
    dp[0][s[0]] = 0;
    set<tuple<long long, int, int>> q;
    q.emplace(make_tuple(dp[0][s[0]], 0, s[0]));
    while ((int) q.size() > 0) {
      auto [d, u, x] = *q.begin();
      debug(d, u, x);
      q.erase(q.begin());
      for (auto& [v, w] : g[u]) {
        if (dp[v][x] > dp[u][x] + x * w) {
          dp[v][x] = dp[u][x] + x * w;
          q.emplace(make_tuple(dp[v][x], v, x));
        }
        if (dp[v][s[v]] > dp[u][x] + x * w) {
          dp[v][s[v]] = dp[u][x] + x * w;
          q.emplace(make_tuple(dp[v][s[v]], v, s[v]));
        }
      }
    }
    long long res = *min_element(dp[n - 1].begin(), dp[n - 1].end());
    cout << res << '\n';
  }
  return 0;
}

