/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-04 05:23:04
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc327/tasks/abc327_d
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);

  int m, n;
  cin >> n >> m;
  vector<int> a(m);
  for (auto& u : a) {
    cin >> u;
    --u;
  }
  vector<int> b(m);
  for (auto& u : b) {
    cin >> u;
    --u;
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    g[a[i]].emplace_back(b[i]);
    g[b[i]].emplace_back(a[i]);
  }
  vector<int> color(n, -1);
  bool flag = true;
  auto Dfs = [&](auto& self, int u, int c) -> void {
    color[u] = c;
    for (auto& v : g[u]) {
      if (color[v] == -1) {
        self(self, v, c ^ 1);
      } else if (color[v] == c) {
        flag = false;
        return;
      }
    }
  };
  for (int i = 0; flag && i < n; i++) {
    if (color[i] == -1) {
      Dfs(Dfs, i, 0);
    }
  }
  debug(color);
  cout << (flag ? "Yes\n" : "No\n");
  return 0;
}
