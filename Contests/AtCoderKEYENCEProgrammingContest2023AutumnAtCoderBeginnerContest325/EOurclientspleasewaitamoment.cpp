/**
 * Author: C0ldSmi1e
 * Created Time: 2023-10-22 16:39:10
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc325/tasks/abc325_e
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

template <typename T, typename U>
vector<T> Dijkstra(const vector<vector<pair<int, U> > > &g, int start, const T &INF) {
  int n = static_cast<int>(g.size());
  assert(start >= 0 && start < n);
  vector<T> dist(n, INF);
  dist[start] = 0;
  priority_queue<pair<T, int>, vector<pair<T, int> >, greater<pair<T, int> > > heap;
  heap.emplace(dist[start], start);
  while ((int) heap.size() > 0) {
    auto [d, u] = heap.top();
    heap.pop();
    if (dist[u] != d) {
      continue;
    }
    for (auto &[v, w] : g[u]) {
      if (dist[v] > w + dist[u]) {
        dist[v] = w + dist[u];
        heap.emplace(dist[v], v);
      }
    }
  }
  // returns INF if there's no path
  return dist;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);

  int n, a, b, c;
  cin >> n >> a >> b >> c;
  vector<vector<int>> d(n, vector<int>(n));
  for (auto& u : d) {
    for (auto& v : u) {
      cin >> v;
    }
  }
  vector<vector<vector<pair<int, long long>>>> g(2, vector<vector<pair<int, long long>>>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      g[0][i].emplace_back(j, 1LL * a * d[i][j]);
      g[1][i].emplace_back(j, 1LL * b * d[i][j] + c);
    }
  }
  vector<vector<long long>> dist(2);
  const long long INF = (long long) 1e18;
  dist[0] = Dijkstra(g[0], 0, INF);
  dist[1] = Dijkstra(g[1], n - 1, INF);
  vector<long long> pref(n);
  for (int i = 0; i < n; i++) {
    pref[i] = dist[0][i];
    if (i > 0) {
      pref[i] += pref[i - 1];
    }
  }
  long long res = INF;
  for (int i = 0; i < n; i++) {
    res = min(res, dist[0][i] + dist[1][i]);
  }
  cout << res << '\n';
  return 0;
}
