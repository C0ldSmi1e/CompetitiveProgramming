// Find a cycle in a directed graph
vector<int> FindCycle(vector<vector<int>> &g) {
  int n = static_cast<int>(g.size());
  vector<char> color(n, 0);
  vector<int> parent(n, -1);
  int cycleStart = -1, cycleEnd = -1;
  function<bool(int)> dfs = [&](int u) -> bool {
    color[u] = 1;
    for (auto &v : g[u]) {
      if (color[v] == 0) {
        parent[v] = u;
        if (dfs(v)) {
          return true;
        }
      } else if (color[v] == 1) {
        cycleStart = v;
        cycleEnd = u;
        return true;
      }
    }
    color[u] = 2;
    return false;
  };
  for (int i = 0; i < n; i++) {
    if (color[i] == 0 && dfs(i)) {
      break;
    }
  }
  vector<int> cycle;
  if (cycleStart != -1) {
    cycle.push_back(cycleStart);
    for (int i = cycleEnd; i != cycleStart; i = parent[i]) {
      cycle.push_back(i);
    }
    cycle.push_back(cycleStart);
    reverse(cycle.begin(), cycle.end());
  }
  return cycle;
}



// Find a cycle in a undirected graph without loops and multiple edges
vector<int> FindCycle(vector<vector<int>> &g) {
  int n = static_cast<int>(g.size());
  vector<bool> visited(n, false);
  vector<int> parent(n, -1);
  int cycleStart = -1, cycleEnd = -1;
  function<bool(int, int)> dfs = [&](int u, int fa) -> bool {
    visited[u] = true;
    for (auto &v : g[u]) {
      if (v == fa) {
        continue;
      }
      if (visited[v]) {
        cycleStart = v;
        cycleEnd = u;
        return true;
      }
      parent[v] = u;
      if (dfs(v, parent[v])) {
        return true;
      }
    }
    return false;
  };
  for (int i = 0; i < n; i++) {
    if (visited[i] == false && dfs(i, parent[i])) {
      break;
    }
  }
  vector<int> cycle;
  if (cycleStart != -1) {
    cycle.push_back(cycleStart);
    for (int i = cycleEnd; i != cycleStart; i = parent[i]) {
      cycle.push_back(i);
    }
    cycle.push_back(cycleStart);
    reverse(cycle.begin(), cycle.end());
  }
  return cycle;
}



// Find a negative cycle in a directed weighted gragh
// n is the number of vertices
template <typename A>
vector<int> FindCycle(int n, const vector<tuple<int, int, A> > &edge) {
  vector<A> dist(n);
  vector<int> parent(n, -1);
  int cycleStart = -1;
  for (int i = 0; i < n; i++) {
    cycleStart = -1;
    for (auto &[u, v, w] : edge) {
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        parent[v] = u;
        cycleStart = v;
      }
    }
  }
  vector<int> cycle;
  if (cycleStart != -1) {
    for (int i = 0; i < n; i++) {
      cycleStart = parent[cycleStart];
    }
    for (int i = cycleStart; ; i = parent[i]) {
      cycle.push_back(i);
      if (i == cycleStart && (int) cycle.size() > 1) {
        break;
      }
    }
    reverse(cycle.begin(), cycle.end());
  }
  return cycle;
}
