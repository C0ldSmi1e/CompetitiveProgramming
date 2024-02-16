// time-limit: 2000
// problem-url: https://codeforces.com/contest/1929/problem/E
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
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].emplace_back(b);
      g[b].emplace_back(a);
    }
    int k;
    cin >> k;
    vector<int> s(n);
    for (int i = 0; i < k; i++) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      s[a] |= (1 << i);
      s[b] |= (1 << i);
    }
    set<int> choices;
    auto Dfs = [&](auto& self, int u, int par) -> void {
      for (auto& v : g[u]) {
        if (v == par) {
          continue;
        }
        self(self, v, u);
        s[u] ^= s[v];
      }
      for (auto& v : g[u]) {
        if (v == par) {
          continue;
        }
        if ((s[u] ^ s[v]) != 0) {
          choices.emplace(s[v]);
        }
      }
    };
    Dfs(Dfs, 0, -1);
    debug(choices);
    vector<int> dp(1 << k, n);
    dp[0] = 0;
    for (int mask = 0; mask < 1 << k; mask++) {
      for (auto& s : choices) {
        dp[mask | s] = min(dp[mask | s], dp[mask] + 1);
      }
    }
    cout << dp.back() << '\n';
  }
  return 0;
}
