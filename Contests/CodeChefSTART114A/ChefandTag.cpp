/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-27 07:26:19
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START114A/problems/TAG
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
    if (n == 1) {
      cout << "1\n";
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].emplace_back(b);
      g[b].emplace_back(a);
    }
    vector<int> sz(n);
    vector<int> dist_root(n);
    const int INF = (int) 1e9;
    vector<int> dist_leaf(n, INF);
    int res = 0;
    auto Dfs = [&](auto self, int u, int fa) -> void {
      for (auto& v : g[u]) {
        if (v == fa) {
          continue;
        }
        dist_root[v] = dist_root[u] + 1;
        self(self, v, u);
        sz[u] += sz[v];
        dist_leaf[u] = min(dist_leaf[u], dist_leaf[v] + 1);
      }
      if ((int) g[u].size() == 1 && fa != -1) {
        // leaf
        dist_leaf[u] = 0;
        sz[u] += 1;
      }
      if (dist_leaf[u] > 0 && dist_leaf[u] <= dist_root[u]) {
        res = max(res, sz[u]);
      }
    };
    dist_root[0] = 0;
    Dfs(Dfs, 0, -1);
    cout << res << '\n';
  }
  return 0;
}
