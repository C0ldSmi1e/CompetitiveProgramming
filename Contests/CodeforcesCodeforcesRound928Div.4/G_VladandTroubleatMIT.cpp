/**
 * Author: C0ldSmi1e
 * Created Time: 02/21/2024 11:47:51 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1926/problem/G
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
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
      int p;
      cin >> p;
      --p;
      g[p].emplace_back(i);
    }
    string s;
    cin >> s;
    const int INF = (int) 1e9;
    vector<vector<long long>> dp(n, vector<long long>(3, INF));
    auto Dfs = [&](auto& self, int u) -> void {
      if (s[u] == 'P') {
        dp[u][1] = 0;
      }
      if (s[u] == 'S') {
        dp[u][2] = 0;
      }
      if (s[u] == 'C') {
        if ((int) g[u].size() == 0) {
          dp[u][0] = 0;
        } else {
          dp[u][1] = dp[u][2] = 0;
        }
      }
      for (auto& v : g[u]) {
        self(self, v);
        if (s[u] == 'P') {
          dp[u][1] += min({dp[v][0], dp[v][1], dp[v][2] + 1});
        }
        if (s[u] == 'S') {
          dp[u][2] += min({dp[v][0], dp[v][1] + 1, dp[v][2]});
        }
        if (s[u] == 'C') {
          dp[u][0] += dp[v][0];
          dp[u][1] += min({dp[v][0], dp[v][1], dp[v][2] + 1});
          dp[u][2] += min({dp[v][0], dp[v][1] + 1, dp[v][2]});
        }
      }
    };
    Dfs(Dfs, 0);
    cout << min({dp[0][0], dp[0][1], dp[0][2]}) << '\n';
  }
  return 0;
}
