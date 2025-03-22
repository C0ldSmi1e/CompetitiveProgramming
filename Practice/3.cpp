/**
 * Author: C0ldSmi1e
 * Created Time: 03/11/2025 07:31:50 AM
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

  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (auto& u : c) {
      cin >> u;
    }
    vector<bool> st(n);
    for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      --x;
      st[x] = true;
    }
    vector<vector<int>> g(n);
    vector<int> din(n);
    for (int i = 0; i < n; i++) {
      int m;
      cin >> m;
      vector<int> b(m);
      for (int j = 0; j < m; j++) {
        int x;
        cin >> x;
        --x;
        g[x].emplace_back(i);
        din[i] += 1;
      }
    }
    vector<int> q;
    const long long INF = (long long) 1e18;
    vector<long long> ans(n, INF);
    for (int i = 0; i < n; i++) {
      if (!din[i]) {
        if (st[i]) {
          ans[i] = 0;
        } else {
          ans[i] = c[i];
        }
        q.emplace_back(i);
      }
    }
    for (int qq = 0; qq < (int) q.size(); qq++) {
      int u = q[qq];
      for (auto& v : g[u]) {
        if (ans[v] == INF) {
          ans[v] = 0;
        }
        ans[v] += ans[u];
        if (--din[v] == 0) {
          q.emplace_back(v);
          ans[v] = min(ans[v], 1ll * c[v]);
          if (st[v]) {
            ans[v] = 0;
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}
