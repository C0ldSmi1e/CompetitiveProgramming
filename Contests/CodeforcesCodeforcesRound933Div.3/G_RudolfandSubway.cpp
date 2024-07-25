/**
 * Author: C0ldSmi1e
 * Created Time: 03/13/2024 02:08:30 PM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1941/problem/G
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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a].emplace_back(b, c);
      g[b].emplace_back(a, c);
    }
    int src, dst;
    cin >> src >> dst;
    --src;
    --dst;
    const int INF = (int) 1e9;
    vector<int> dist(n, INF);
    dist[src] = 0;
    vector<set<int>> S(n);
    vector<int> q;
    for (auto& [v, c] : g[src]) {
      dist[v] = 1;
      q.emplace_back(v);
      S[v].insert(c);
    }
    deque<int> q;
    while ((int) q.size() > 0) {
      int u = q.front();
      q.pop_front();
      for (auto& [v, c] : g[u]) {
        int dd = dist[u] + (int) (S[u].count(c) == 0);
        if (dd < dist[v]) {
          dist[v] = dd;
          S[v].clear();
          S[v].insert(c);
          q.emplace_back(v);
        } else if (dd == dist[v]) {
          S[v].insert(c);
        }
      }
    }
    cout << dist[dst] << '\n';
  }
  return 0;
}

