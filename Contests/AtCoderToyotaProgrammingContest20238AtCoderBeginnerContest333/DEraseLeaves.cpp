/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-16 16:03:45
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc333/tasks/abc333_d
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
  vector<int> cnt(n);
  auto Dfs = [&](auto& self, int u, int fa) -> void {
    cnt[u] += 1;
    for (auto& v : g[u]) {
      if (v != fa) {
        self(self, v, u);
        cnt[u] += cnt[v];
      }
    }
  };
  Dfs(Dfs, 0, -1);
  int mx = 0;
  int sum = 0;
  for (auto& u : g[0]) {
    mx = max(mx, cnt[u]);
    sum += cnt[u];
  }
  cout << sum - mx + 1 << '\n';
  return 0;
}
