/**
 * Author: C0ldSmi1e
 * Created Time: 02/14/2024 10:58:39 AM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc340/tasks/abc340_d
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

template <typename T, typename U>
vector<T> Dijkstra(const vector<vector<pair<int, U>>>& g, int start, const T INF) {
  int n = static_cast<int>(g.size());
  assert(start >= 0 && start < n);
  vector<T> dist(n, INF);
  dist[start] = 0;
  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> heap;
  heap.emplace(dist[start], start);
  while ((int) heap.size() > 0) {
    auto [d, u] = heap.top();
    heap.pop();
    if (dist[u] != d) {
      continue;
    }
    for (auto& [v, w] : g[u]) {
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
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> x(n);
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> x[i];
    --x[i];
    if (i + 1 < n) {
      g[i].emplace_back(i + 1, a[i]);
      g[i].emplace_back(x[i], b[i]);
    }
  }
  const long long INF = (long long) 1e18;
  auto dist = Dijkstra(g, 0, INF);
  cout << dist.back() << '\n';
  return 0;
}
