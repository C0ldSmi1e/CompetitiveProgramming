/**
 * Author: C0ldSmi1e
 * Created Time: 03/06/2024 04:37:43 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc342/tasks/abc342_e
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
  vector<vector<array<int, 5>>> rg(n);
  for (int i = 0; i < m; i++) {
    int l, d, k, c, a, b;
    cin >> l >> d >> k >> c >> a >> b;
    --a;
    --b;
    rg[b].push_back({a, l, d, k, c});
  }
  const long long INF = (long long) 2e18;
  vector<long long> f(n, -INF);
  f[n - 1] = INF;
  priority_queue<pair<long long, int>> heap;
  heap.push(make_pair(INF, n - 1));
  while ((int) heap.size() > 0) {
    auto [t, u] = heap.top();
    heap.pop();
    if (t != f[u]) {
      continue;
    }
    debug(t, u);
    for (auto& [v, l, d, k, c] : rg[u]) {
      if (l + c <= f[u]) {
        long long ans = l + d * min(k - 1ll, (f[u] - c - l) / d);
        if (ans > f[v]) {
          f[v] = ans;
          heap.push(make_pair(f[v], v));
        }
      }
    }
  }
  for (int i = 0; i < n - 1; i++) {
    if (f[i] >= 0) {
      cout << f[i] << '\n';
    } else {
      cout << "Unreachable\n";
    }
  }
  return 0;
}
