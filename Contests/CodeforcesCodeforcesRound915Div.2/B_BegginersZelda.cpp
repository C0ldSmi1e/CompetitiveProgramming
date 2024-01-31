/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-16 06:44:51
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1905/problem/B
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
    int root = 0;
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].emplace_back(b);
      g[b].emplace_back(a);
      if ((int) g[a].size() > 1) {
        root = a;
      }
      if ((int) g[b].size() > 1) {
        root = b;
      }
    }
    int cnt = 0;
    auto Dfs = [&](auto& self, int u, int fa) -> void {
      bool leaf = true;
      for (auto& v : g[u]) {
        if (v != fa) {
          self(self, v, u);
          leaf = false;
        }
      }
      if (leaf) {
        cnt += 1;
      }
    };
    Dfs(Dfs, root, -1);
    cout << (cnt + 1) / 2 << '\n';
  }
  return 0;
}
