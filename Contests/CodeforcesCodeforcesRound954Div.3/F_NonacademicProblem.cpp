// time-limit: 2000
// problem-url: https://codeforces.com/contest/1986/problem/F
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

  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].emplace_back(b, i);
      g[b].emplace_back(a, i);
    }
    vector<pair<bool, pair<int, int>>> bridge(m);
    vector<int> dfn(n, -1);
    vector<int> low(n);
    int time_stamp = 0;
    auto Tarjan = [&](auto& self, int u, int fa) -> void {
      dfn[u] = low[u] = time_stamp++;
      // id is edge's id
      for (auto& [v, id] : g[u]) {
        if (v != fa) {
          if (dfn[v] == -1) {
            self(self, v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) {
              // id is a bridge
              bridge[id] = make_pair(true, make_pair(u, v));
            }
          } else {
            low[u] = min(low[u], dfn[v]);
          }
        }
      }
    };
    Tarjan(Tarjan, 0, -1);
    Dsu d(n);
    for (int i = 0; i < n; i++) {
      for (auto& [j, id] : g[i]) {
        if (!bridge[id].first) {
          d.Unite(i, j);
        }
      }
    }
    map<int, int> mp;
    vector<int> sz;
    int nn = 0;
    for (int i = 0; i < n; i++) {
      if (d.Get(i) == i) {
        sz.emplace_back(d.GetSize(i));
        mp[d.Get(i)] = nn++;
      }
    }
    vector<vector<int>> tr(nn);
    for (int i = 0; i < m; i++) {
      if (bridge[i].first) {
        auto [u, v] = bridge[i].second;
        u = mp[d.Get(u)];
        v = mp[d.Get(v)];
        if (u != v) {
          tr[u].emplace_back(v);
          tr[v].emplace_back(u);
        }
      }
    }
    long long ans = 1ll * (n - 1) * n / 2;
    long long mx = 0;
    vector<int> cnt(nn);
    debug(tr);
    debug(sz);
    auto Dfs = [&](auto& self, int u, int par) -> void {
      cnt[u] += sz[u];
      for (auto& v : tr[u]) {
        if (v != par) {
          self(self, v, u);
          cnt[u] += cnt[v];
        }
      }
      mx = max(mx, 1ll * cnt[u] * (n - cnt[u]));
    };
    Dfs(Dfs, 0, -1);
    cout << ans - mx << '\n';
  }
  return 0;
}
