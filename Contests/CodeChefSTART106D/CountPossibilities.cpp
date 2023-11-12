/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-01 08:52:34
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START106D/problems/FIZZBUZZ2307
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

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> din(n);
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].emplace_back(b);
      din[b] += 1;
    }
    int root = -1;
    for (int i = 0; i < n; i++) {
      if (din[i] == 0) {
        root = i;
      }
    }
    assert(root != -1);
    vector<int> dist(n);
    vector<int> cnt(n);
    auto Dfs = [&](auto& self, int u, int d) -> void {
      cnt[u] = 1;
      dist[u] = d;
      for (auto& v : g[u]) {
        self(self, v, d + 1);
        cnt[u] += cnt[v];
      }
    };
    Dfs(Dfs, root, 0);
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      int l = dist[i];
      int r = n - cnt[i];
      res[l] += 1;
      if (r + 1 < n) {
        res[r + 1] -= 1;
      }
    }
    for (int i = 0; i < n; i++) {
      if (i - 1 >= 0) {
        res[i] += res[i - 1];
      }
      cout << res[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}
