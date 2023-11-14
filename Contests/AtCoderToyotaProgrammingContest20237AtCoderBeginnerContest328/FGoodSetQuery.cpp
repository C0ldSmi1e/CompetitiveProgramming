/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-12 14:51:37
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc328/tasks/abc328_f
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
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      sz[y] += sz[x];
      return true;
    }
    return false;
  }
  inline int getSize(int x) {
    return sz[get(x)];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);

  int n, m;
  cin >> n >> m;
  vector<array<int, 3>> edges(m);
  for (auto& [a, b, c] : edges) {
    cin >> a >> b >> c;
    --a;
    --b;
  }
  Dsu d(n);
  vector<int> bad_edges;
  set<int> S;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; i++) {
    auto [a, b, c] = edges[i];
    if (d.get(a) == d.get(b)) {
      bad_edges.emplace_back(i);
    } else {
      S.insert(i);
      d.unite(a, b);
      g[b].emplace_back(a, c);
      g[a].emplace_back(b, -c);
    }
  }
  const long long INF = (long long) 1e18;
  vector<long long> dist(n, INF);
  auto Dfs = [&](auto& self, int u, int fa, long long d) -> void {
    dist[u] = d;
    for (auto& [v, w] : g[u]) {
      if (v != fa) {
        self(self, v, u, d + w);
      }
    }
  };
  for (int i = 0; i < n; i++) {
    if (dist[i] == INF) {
      Dfs(Dfs, i, -1, 0ll);
    }
  }
  for (auto& i : bad_edges) {
    auto [a, b, c] = edges[i];
    long long da = dist[a];
    long long db = dist[b];
    if (da - db == c) {
      S.insert(i);
    }
  }
  for (auto& u : S) {
    cout << u + 1 << ' ';
  }
  cout << '\n';
  return 0;
}
