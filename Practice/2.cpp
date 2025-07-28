/**
 * Author: C0ldSmi1e
 * Created Time: 05/31/2025 05:38:39 AM
**/

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
  debug(dist);
  vector<bool> st(n);
  while ((int) heap.size() > 0) {
    auto [d, u] = heap.top();
    heap.pop();
    if (dist[u] != d || st[u]) {
      continue;
    }
    st[u] = true;
    for (auto& [v, w] : g[u]) {
      if (dist[v] > w | dist[u]) {
        dist[v] = w | dist[u];
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
  const int INF = (int) 2e9;
  auto d = Dijkstra(g, 0, INF);
  cout << d.back() << '\n';
  return 0;
}
