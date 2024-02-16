/**
 * Author: C0ldSmi1e
 * Created Time: 02/06/2024 08:36:43 AM
**/

// time-limit: 4000
// problem-url: https://codeforces.com/contest/1927/problem/F
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
    vector<tuple<int, int, int>> edges(m);
    for (auto& [c, a, b] : edges) {
      cin >> a >> b >> c;
      --a;
      --b;
    }
    sort(edges.rbegin(), edges.rend());
    Dsu d(n);
    int mn = (int) 1e9;
    int U = -1, V = -1;
    vector<vector<int>> g(n);
    for (auto& [c, a, b] : edges) {
      if (!d.Unite(a, b)) {
        mn = c;
        U = a;
        V = b;
      } else {
        g[a].emplace_back(b);
        g[b].emplace_back(a);
      }
    }
    vector<int> cycle;
    auto Dfs = [&](auto& self, int u, int fa) -> bool {
      cycle.emplace_back(u);
      if (u == V) {
        return true;
      }
      for (auto& v : g[u]) {
        if (v == fa) {
          continue;
        }
        if (self(self, v, u)) {
          return true;
        }
      }
      cycle.pop_back();
      return false;
    };
    Dfs(Dfs, U, -1);
    cout << mn << ' ' << (int) cycle.size() << '\n';
    for (auto& u : cycle) {
      cout << u + 1 << ' ';
    }
    cout << '\n';
  }
  return 0;
}
