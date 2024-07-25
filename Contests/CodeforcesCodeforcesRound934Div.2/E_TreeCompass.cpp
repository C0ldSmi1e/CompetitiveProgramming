/**
 * Author: C0ldSmi1e
 * Created Time: 03/16/2024 09:07:00 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1944/problem/E
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
    const int INF = (int) 1e9;
    vector<int> dist(n, INF);
    auto Dfs1 = [&](auto& self, int u, int par, int d) -> void {
      dist[u] = d;
      for (auto& v : g[u]) {
        if (v == par) {
          continue;
        }
        self(self, v, u, d + 1);
      }
    };
    Dfs1(Dfs1, 0, -1, 0);
    int mxp = (int) (max_element(dist.begin(), dist.end()) - dist.begin());
    vector<int> nodes;
    vector<int> path;
    dist = vector<int>(n, INF);
    int mx = -1;
    auto Dfs2 = [&](auto& self, int u, int par, int d) -> void {
      dist[u] = d;
      path.emplace_back(u);
      if (dist[u] > mx) {
        mx = dist[u];
        nodes = path;
      }
      for (auto& v : g[u]) {
        if (v == par) {
          continue;
        }
        self(self, v, u, d + 1);
      }
      path.pop_back();
    };
    Dfs2(Dfs2, mxp, -1, 0);
    int sz = (int) nodes.size();
    debug(nodes);
    if (sz & 1) {
      cout << sz / 2 + 1 << '\n';
      for (int i = 0; i < sz / 2 + 1; i++) {
        cout << nodes[sz / 2] + 1 << ' ' << i << '\n';
      }
    } else {
      vector<pair<int, int>> ans;
      for (int i = 1; i <= sz / 2; i += 2) {
        ans.emplace_back(nodes[sz / 2 - 1] + 1, i);
        ans.emplace_back(nodes[sz / 2] + 1, i);
      }
      cout << (int) ans.size() << '\n';
      for (auto& [x, y] : ans) {
        cout << x << ' ' << y << '\n';
      }
    }
  }
  return 0;
}

