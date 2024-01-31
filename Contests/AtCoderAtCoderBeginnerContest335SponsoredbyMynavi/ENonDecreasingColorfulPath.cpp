/**
 * Author: C0ldSmi1e
 * Created Time: 01/07/2024 11:53:49 AM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc335/tasks/abc335_e
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

class Dsu {
 public:
  vector<int> p, sz;
  int n;
  Dsu(int _n) {
    n = _n + 1;
    p.resize(n);
    sz.assign(n, 1);
    iota(p.begin(), p.end(), 0);
  }
  inline int Get(int x) {
    return (x == p[x] ? x : (p[x] = Get(p[x])));
  }
  inline bool Unite(int x, int y) {
    x = Get(x);
    y = Get(y);
    if (x != y) {
      p[x] = y;
      sz[y] += sz[x];
      return true;
    }
    return false;
  }
  inline int GetSize(int x) {
    return sz[Get(x)];
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto& u : a) {
    cin >> u;
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  Dsu d(n);
  for (int u = 0; u < n; u++) {
    for (auto& v : g[u]) {
      if (a[v] == a[u]) {
        d.Unite(u, v);
      }
    }
  }
  vector<vector<int>> G(n);
  for (int u = 0; u < n; u++) {
    for (auto& v : g[u]) {
      if (d.Get(u) != d.Get(v)) {
        G[d.Get(u)].emplace_back(d.Get(v));
        G[d.Get(v)].emplace_back(d.Get(u));
      }
    }
  }
  const int INF = (int) 1e9;
  vector<int> dp(n, -1);
  auto Dfs = [&](auto& self, int u) -> int {
    if (dp[u] != -1) {
      return dp[u];
    }
    if (u == d.Get(0)) {
      return dp[u] = 1;
    }
    int ans = -INF;
    for (auto& v : G[u]) {
      if (a[u] > a[v]) {
        ans = max(ans, self(self, v) + 1);
      }
    }
    return dp[u] = ans;
  };
  cout << max(0, Dfs(Dfs, d.Get(n - 1))) << '\n';
  return 0;
}

