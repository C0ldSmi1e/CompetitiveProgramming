/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-01 15:20:58
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1900/problem/E
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

vector<int> FindSCC(const vector<vector<int>>& g, int& id) {
  int n = static_cast<int>(g.size());
  int top = 0;
  vector<int> comp(n, -1), in(n, -1), out(n, -1), stk(n + 1, -1), order;
  function<int(int u)> Tarjan = [&](int u) -> int {
    assert(top >= 0 && top <= n);
    stk[top++] = u;
    int low = in[u] = (int) order.size();
    order.push_back(u);
    for (auto& v : g[u]) {
      if (in[v] == -1) {
        low = min(low, Tarjan(v));
        continue;
      }
      if (comp[v] == -1) {
        low = min(low, in[v]);
      }
    }
    if (low == in[u]) {
      while (stk[top] != u) {
        assert(top >= 0 && top <= n);
        comp[stk[--top]] = id;
      }
      id++;
    }
    out[u] = (int) order.size() - 1;
    return low;
  };
  for (int i = 0; i < n; i++) {
    if (in[i] == -1) {
      Tarjan(i);
    }
  }
  return comp;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].emplace_back(b);
    }
    int scc_n = 0;
    auto comp = FindSCC(g, scc_n);
    vector<long long> tot(scc_n);
    vector<int> sz(scc_n);
    for (int i = 0; i < n; i++) {
      tot[comp[i]] += a[i];
      sz[comp[i]] += 1;
    }
    debug(comp);
    debug(tot);
    debug(sz);
    vector<vector<int>> scc_g(scc_n);
    vector<int> din(scc_n);
    for (int u = 0; u < n; u++) {
      for (auto& v : g[u]) {
        if (comp[u] != comp[v]) {
          din[comp[v]] += 1;
          scc_g[comp[u]].emplace_back(comp[v]);
        }
      }
    }
    vector<pair<int, long long>> dp(scc_n, make_pair(-1, 0));
    for (int i = 0; i < scc_n; i++) {
      if (din[i] == 0) {
        dp[i] = make_pair(sz[i], tot[i]);
      }
    }
    for (int u = scc_n - 1; u >= 0; u--) {
      for (auto& v : scc_g[u]) {
        if (dp[v].first < dp[u].first + sz[v]) {
          dp[v].first = dp[u].first + sz[v];
          dp[v].second = dp[u].second + tot[v];
        } else if (dp[v].first == dp[u].first + sz[v] && dp[u].second + tot[v] < dp[v].second) {
          dp[v].second = dp[u].second + tot[v];
        }
      }
    }
    int mx = -1;
    long long mn = 0;
    for (int i = 0; i < scc_n; i++) {
      auto [len, v] = dp[i];
      if (len > mx) {
        mx = len;
        mn = v;
      } else if (len == mx && v < mn) {
        mn = v;
      }
    }
    cout << mx << ' ' << mn << '\n';
  }
  return 0;
}

