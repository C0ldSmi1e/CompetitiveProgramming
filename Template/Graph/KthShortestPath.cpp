// FindKthShortestPath using Dijkstra and A-Star.
// If k-th path is not exist, return -1.
// If start and end are the same, k += 1.
template <typename A, typename B>
void Dijkstra(const vector<vector<pair<int, B> > > &g, int start, vector<A> &dist) {
  int n = static_cast<int>(g.size());
  assert(start >= 0 && start < n);
  dist[start] = 0;
  priority_queue<pair<A, int>, vector<pair<A, int> >, greater<pair<A, int> > > heap;
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
}

template <typename A, typename B>
A FindKthShortestPath(const vector<vector<pair<int, B> > > &g, const vector<vector<pair<int, B> > > &rg, int start, int end, int k, const A &INF) {
  int n = static_cast<int>(g.size());
  assert(start >= 0 && start < n);
  assert(end >= 0 && end < n);
  vector<A> dist(n, INF);
  Dijkstra(rg, end, dist);
  priority_queue<tuple<A, A, int>, vector<tuple<A, A, int> >, greater<tuple<A, A, int> > > heap;
  heap.emplace(dist[start], 0, start);
  vector<int> cnt(n, 0);
  while ((int) heap.size() > 0) {
    auto [x, d, u] = heap.top();
    heap.pop();
    cnt[u] += 1;
    if (cnt[end] == k) {
      assert(end == u);
      return d;
    }
    for (auto &[v, w] : g[u]) {
      if (cnt[v] < k) {
        heap.emplace(d + w + dist[v], d + w, v);
      }
    }
  }
  return -1;
}
