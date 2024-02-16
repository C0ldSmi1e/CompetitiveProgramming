/**
 * Author: C0ldSmi1e
 * Created Time: 02/13/2024 07:22:16 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1931/problem/F
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

// Note: if there is a cycle, the size of the return will be less than n.
vector<int> TopologicalSort(const vector<vector<int>>& g) {
  int n = static_cast<int>(g.size());
  vector<int> din(n, 0), order;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (int) g[i].size(); j++) {
      din[g[i][j]]++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (din[i] == 0) {
      order.emplace_back(i);
    }
  }
  for (int i = 0; i < (int) order.size(); i++) {
    int u = order[i];
    for (int j = 0; j < (int) g[u].size(); j++) {
      if (--din[g[u][j]] == 0) {
        order.emplace_back(g[u][j]);
      }
    }
  }
  return order;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    while (k--) {
      vector<int> a(n);
      for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
        if (i > 1) {
          g[a[i - 1]].emplace_back(a[i]);
        }
      }
    }
    auto order = TopologicalSort(g);
    cout << ((int) order.size() == n ? "YES\n" : "NO\n");
  }
  return 0;
}
