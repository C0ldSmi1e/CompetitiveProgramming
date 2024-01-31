/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-19 08:31:21
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1914/problem/F
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
      int fa;
      cin >> fa;
      --fa;
      g[fa].emplace_back(i);
    }
    vector<int> sz(n);
    auto Dfs1 = [&](auto& self, int u) -> void {
      sz[u] += 1;
      for (auto& v : g[u]) {
        self(self, v);
        sz[u] += sz[v];
      }
    };
    Dfs1(Dfs1, 0);
    auto Dfs2 = [&](auto& self, int u) -> int {
      int mx = 0;
      int mxv = -1;
      for (auto& v : g[u]) {
        if (sz[v] > mx) {
          mx = sz[v];
          mxv = v;
        }
      }
      if (mxv == -1) {
        return 0;
      }
      int t = self(self, mxv);
      if (mx - 2 * t <= sz[u] - 1 - mx) {
        return t + (sz[u] - 1 - 2 * t) / 2;
      }
      return t + (sz[u] - 1 - mx);
    };
    cout << Dfs2(Dfs2, 0) << '\n';
  }
  return 0;
}
