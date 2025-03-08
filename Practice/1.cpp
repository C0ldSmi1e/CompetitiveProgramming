/**
 * Author: C0ldSmi1e
 * Created Time: 03/08/2025 06:26:25 AM
**/

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

  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    edges[i] = make_pair(a, b);
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  vector<int> s(n, -1);
  bool flag = true;
  auto Dfs = [&](auto& self, int u, int c) -> void {
    s[u] = c;
    for (auto& v : g[u]) {
      if (s[v] == -1) {
        self(self, v, c ^ 1);
        continue;
      }
      flag &= ((c ^ 1) == s[v]);
    }
  };
  Dfs(Dfs, 0, 0);
  if (!flag) {
    cout << "NO\n";
    return 0;
  }
  string ans(m, '#');
  for (int i = 0; i < m; i++) {
    auto [a, b] = edges[i];
    ans[i] = (char) ('0' + s[a]);
  }
  cout << "YES\n";
  cout << ans << '\n';
  return 0;
}
