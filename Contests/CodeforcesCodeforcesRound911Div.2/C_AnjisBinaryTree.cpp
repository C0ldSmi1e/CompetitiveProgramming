/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-26 07:32:55
**/

// time-limit: 2500
// problem-url: https://codeforces.com/contest/1900/problem/C
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
    string s;
    cin >> s;
    vector<vector<pair<int, int>>> g(n);
    vector<bool> leaf(n);
    for (int i = 0; i < n; i++) {
      int ls, rs;
      cin >> ls >> rs;
      --ls;
      --rs;
      if (ls >= 0) {
        g[i].emplace_back(0, ls);
      }
      if (rs >= 0) {
        g[i].emplace_back(1, rs);
      }
      if (ls == -1 && rs == -1) {
        leaf[i] = true;
      }
    }
    const int INF = (int) 1e9;
    vector<int> dp(n, INF);
    dp[0] = 0;
    auto Dfs = [&](auto& self, int u) -> void {
      for (auto& [t, v] : g[u]) {
        if (t == 0) {
          dp[v] = min(dp[v], dp[u] + (int) (s[u] != 'L'));
        } else {
          dp[v] = min(dp[v], dp[u] + (int) (s[u] != 'R'));
        }
        self(self, v);
      }
    };
    Dfs(Dfs, 0);
    int res = INF;
    for (int i = 0; i < n; i++) {
      if (leaf[i]) {
        res = min(res, dp[i]);
      }
    }
    cout << res << '\n';
  }
  return 0;
}
