/**
 * Author: C0ldSmi1e
 * Created Time: 06/11/2024 09:21:07 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1985/problem/H1
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
    vector<string> g(n);
    for (auto& s : g) {
      cin >> s;
    }
    Dsu d(n * m);
    vector<vector<bool>> st(n, vector<bool>(m));
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};
    auto Dfs = [&](auto& self, int x, int y) -> void {
      st[x][y] = true;
      for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx < 0 || ty < 0 || tx >= n || ty >= m) {
          continue;
        }
        if (g[tx][ty] != '#' || st[tx][ty]) {
          continue;
        }
        d.Unite(tx * m + ty, x * m + y);
        self(self, tx, ty);
      }
    };
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (g[i][j] == '#' && !st[i][j]) {
          Dfs(Dfs, i, j);
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      set<int> S;
      for (int j = 0; j < m; j++) {
        if (g[i][j] == '#') {
          S.insert(d.Get(i * m + j));
        } else {
          sum += 1;
        }
        for (int k = 0; k < 4; k++) {
          int tx = i + dx[k];
          int ty = j + dy[k];
          if (tx < 0 || ty < 0 || tx >= n || ty >= m) {
            continue;
          }
          if (g[tx][ty] == '#') {
            S.insert(d.Get(tx * m + ty));
          }
        }
      }
      for (auto& u : S) {
        sum += d.GetSize(u);
      }
      ans = max(ans, sum);
    }
    for (int j = 0; j < m; j++) {
      int sum = 0;
      set<int> S;
      for (int i = 0; i < n; i++) {
        if (g[i][j] == '#') {
          S.insert(d.Get(i * m + j));
        } else {
          sum += 1;
        }
        for (int k = 0; k < 4; k++) {
          int tx = i + dx[k];
          int ty = j + dy[k];
          if (tx < 0 || ty < 0 || tx >= n || ty >= m) {
            continue;
          }
          if (g[tx][ty] == '#') {
            S.insert(d.Get(tx * m + ty));
          }
        }
      }
      for (auto& u : S) {
        sum += d.GetSize(u);
      }
      ans = max(ans, sum);
    }
    cout << ans << '\n';
  }
  return 0;
}
