// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc325/tasks/abc325_c
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
  vector<string> g(n);
  for (auto& s : g) {
    cin >> s;
  }
  int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
  int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
  vector<vector<bool>> st(n, vector<bool>(m));
  auto Dfs = [&](auto& self, int x, int y) -> void {
    st[x][y] = true;
    for (int i = 0; i < 8; i++) {
      int tx = x + dx[i];
      int ty = y + dy[i];
      if (tx < 0 || ty < 0 || tx >= n || ty >= m) {
        continue;
      }
      if (g[tx][ty] != '#' || st[tx][ty]) {
        continue;
      }
      self(self, tx, ty);
    }
  };
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == '#' && !st[i][j]) {
        res += 1;
        Dfs(Dfs, i, j);
      }
    }
  }
  cout << res << '\n';
  return 0;
}
