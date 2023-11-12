/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-01 09:00:57
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START106D/problems/FIZZBUZZ2309
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].emplace_back(b);
      g[b].emplace_back(a);
    }
    const int INF = (int) 1e9;
    vector<vector<int>> dist(n, vector<int>(2, INF));
    dist[0][0] = 0;
    vector<pair<int, int>> q;
    q.emplace_back(make_pair(0, 0));
    for (int qq = 0; qq < (int) q.size(); qq++) {
      auto [u, t] = q[qq];
      debug(u, t, dist[u][t]);
      for (auto& v : g[u]) {
        if (dist[v][t ^ 1] > dist[u][t] + 1) {
          dist[v][t ^ 1] = dist[u][t] + 1;
          q.emplace_back(make_pair(v, t ^ 1));
        }
      }
    }
    debug(dist);
    int mx0 = 0;
    int mx1 = 0;
    for (int i = 0; i < n; i++) {
      mx0 = max(mx0, dist[i][0]);
      mx1 = max(mx1, dist[i][1]);
    }
    int res = min(mx0, mx1);
    cout << (res >= INF ? -1 : res) << '\n';
  }
  return 0;
}
