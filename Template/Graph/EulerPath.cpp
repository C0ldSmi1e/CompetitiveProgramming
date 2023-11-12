// 欧拉路径
// 找到一种路径可以遍历所有边恰好一次
const int N = 2010, M = 1010;

int n = 500, m;
int deg[N];
int g[N][N];
VI path;

void dfs(int u) {
  for (int i = 1; i <= n; i ++ ) {
    if (g[u][i]) {
      g[u][i]--, g[i][u]--;
      dfs(i);
    }
  }
  path.emplace_back(u);
}

int main() {
  cin >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a][b]++, g[b][a]++;
    deg[a]++, deg[b]++;
  }
  int start = 1;
  while (!deg[start]) start++;
  for (int i = 1; i <= n; i++) {
    if (deg[i] & 1) {
      start = i;
      break;
    }
  }
  dfs(start);
  reverse(ALL(path));
  for (auto &u : path) {
    cout << u << '\n';
  }
  return 0;
}



// 欧拉回路
// 即在图中找一个环使得每条边都在环上出现恰好一次
const int N = 100010, M = 4 * N;

int type;
int n, m;
int h[N], e[M], ne[M], idx;
int din[N], dout[N];
bool st[M];
VI path;

void add_edge(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
  for (int &i = h[u]; ~i; ) {
    int j = e[i];
    if (st[i]) {
      i = ne[i];
      continue;
    }
    st[i] = true;
    if (type == 1) {
      st[i ^ 1] = true;
    }
    int t;
    if (type == 1) {
      t = i / 2 + 1;
      if (i & 1) {
        t = -t;
      }
    } else {
      t = i + 1;
    }
    i = ne[i];
    dfs(j);
    path.emplace_back(t);
  }
}

int main() {
  memset(h, -1, sizeof h);
  cin >> type >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    add_edge(a, b);
    if (type == 1) {
      add_edge(b, a);
    }
    din[b] += 1, dout[a] += 1;
  }
  bool flag = true;
  if (type == 1) {
    for (int i = 1; i <= n; i++) {
      if ((din[i] + dout[i]) & 1) {
        flag = false;
      }
    }
  } else {
    for (int i = 1; i <= n; i++) {
      if ((din[i] != dout[i])) {
        flag = false;
      }
    }
  }
  if (!flag) {
    cout << "NO\n";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (h[i] != -1) {
      dfs(i);
      break;
    }
  }
  if ((int) path.size() != m) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  reverse(path.begin(), path.end());
  for (auto &u : path) {
    cout << u << ' ';
  }
  cout << '\n';
  return 0;
}



// 给定若干单词连成长串使得首尾字母相同
const int N = 110, M = 1010;

int T;
int n;
int p[N];
int din[N], dout[N];
bool st[N];

int find(int x) {
  if (x != p[x]) p[x] = find(p[x]);
  return p[x];
}

int main() {
  cin >> T;
  while (T--) {
    memset(st, 0, sizeof st);
    memset(din, 0, sizeof din);
    memset(dout, 0, sizeof dout);
    for (int i = 0; i < N; i++) {
      p[i] = i;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      int a = s[0] - 'a', b = s.back() - 'a';
      dout[a]++, din[b]++;
      p[find(a)] = find(b);
      st[a] = st[b] = true;
    }
    bool flag = true;
    int root = -1;
    for (int i = 0; i < 26; i++) {
      if (st[i]) {
        if (root == -1) {
          root = find(i);
        } else if (root != find(i)) {
          flag = false;
        }
      }
    }
    int start = 0, end = 0;
    for (int i = 0; i < 26; i++) {
      if (st[i]) {
        if (din[i] == dout[i] + 1) {
          end++;
        } else if (din[i] + 1 == dout[i]) {
          start++;
        } else if (din[i] != dout[i]) {
          flag = false;
        }
      }
    }
    if (flag && (start == 1 && end == 1 || start == 0 && end == 0)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}


// Usage:
// Input should be a gragh and edges
// g[][] is an edge index
// Return a vector of pair(edge index, diretion)
// If it's a directed gragh, direction always is 1
// Otherwise, for edges[id] == (x, y)
// dirction == 1 indicates (x->y)
// direction == -1 indicates (y->x)
// root is the source of the path
// If root == -1, no solution
// Be careful of single point
vector<pair<int, int>> FindEulerianPath(const vector<vector<int>> &g, const vector<pair<int, int>> edges, int &root) {
  int n = static_cast<int>(g.size());
  int m = static_cast<int>(edges.size());
  vector<int> din(n), dout(n);
  // din and dout are fake for undirected gragh
  for (auto &[x, y] : edges) {
    dout[x]++, din[y]++;
  }
  root = -1;
  int odd = 0;
  for (int i = 0; i < n; i++) {
    if ((din[i] + dout[i]) & 1) {
      odd++;
      if (root == -1 || (dout[i] - din[i] > dout[root] - din[root])) {
        root = i;
      }
    }
  }
  if (odd > 2) {
    root = -1;
    return vector<pair<int, int>>();
  }
  if (root == -1) {
    root = 0;
    while (root < n && din[root] + dout[root] == 0) {
      root++;
    }
    if (root == n) {
      // return an empty path
      root = 0;
      return vector<pair<int, int>>();
    }
  }
  int stackPtr = 0, writePtr = m, v = root;
  vector<int> ptr(n, 0), balance(n, 0);
  vector<pair<int, int>> res(m);
  vector<bool> used(m, false);
  while (true) {
    bool found = false;
    while (ptr[v] < (int) g[v].size()) {
      int id = g[v][ptr[v]++];
      if (used[id]) {
        continue;
      }
      used[id] = true;
      balance[v]++;
      if (v == edges[id].second) {
        res[stackPtr++] = make_pair(id, -1);
      } else if (v == edges[id].first) {
        res[stackPtr++] = make_pair(id, 1);
      } else {
        assert(false);
      }
      v ^= edges[id].first ^ edges[id].second;
      balance[v]--;
      found = true;
      break;
    }
    if (!found) {
      if (stackPtr == 0) {
        break;
      }
      auto [id, dir] = res[--stackPtr];
      res[--writePtr] = make_pair(id, dir);
      v ^= edges[abs(id)].first ^ edges[abs(id)].second;
    }
  }
  int bad = 0;
  for (int i = 0; i < n; i++) {
    bad += abs(balance[i]);
  }
  if (writePtr != 0 || bad > 2) {
    root = -1;
    return vector<pair<int, int>>();
  }
  return res;
}

// If path[0] == path.back(), the path is a cycle
vector<int> GetVerPath(const vector<pair<int, int>> &edges, const vector<pair<int, int>> &ids) {
  int n = static_cast<int>(ids.size());
  if (n == 0) {
    return vector<int>();
  }
  vector<int> path(n + 1);
  path[0] = (ids[0].second > 0 ? edges[ids[0].first].first : edges[ids[0].first].second);
  for (int i = 0; i < n; i++) {
    if (ids[i].second > 0) {
      path[i + 1] = edges[ids[i].first].second;
    } else {
      path[i + 1] = edges[ids[i].first].first;
    }
  }
  return path;
}
