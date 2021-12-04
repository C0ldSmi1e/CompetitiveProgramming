#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<bool> del;
vector<vector<pair<int, int> > > g;

int GetSize(int u, int fa) {
  if (del[u]) {
    return 0;
  }
  int res = 1;
  for (auto &[v, w] : g[u]) {
    if (v != fa) {
      res += GetSize(v, u);
    }
  }
  return res;
}

int GetCenter(int u, int fa, int tot, int &center) {
  if (del[u]) {
    return 0;
  }
  int sum = 1, mx = 0;
  for (auto &[v, w] : g[u]) {
    if (v != fa) {
      int cnt = GetCenter(v, u, tot, center);
      mx = max(mx, cnt);
      sum += cnt;
    }
  }
  mx = max(mx, tot - sum);
  if (mx <= tot / 2) {
    center = u;
  }
  return sum;
}

void dfs(int u, int fa, int distance, vector<int> &inner, vector<int> &dist) {
  if (del[u]) {
    return;
  }
  dist.emplace_back(distance);
  inner.emplace_back(distance);
  for (auto &[v, w] : g[u]) {
    if (v != fa) {
      dfs(v, u, distance + w, inner, dist);
    }
  }
}

int find(vector<int> &a) {
  int res = 0, k = (int) a.size();
  for (int i = k - 1, j = 0; i >= 0; i--) {
    while (j < i && a[j] + a[i] <= m) {
      j++;
    }
    res += min(i, j);
  }
  return res;
}

int solve(int u) {
  if (del[u]) {
    return 0;
  }
  int center = -1;
  GetCenter(u, -1, GetSize(u, -1), center);
  assert(center != -1);
  del[center] = true;
  int res = 0;
  vector<int> dist;
  for (auto &[v, w] : g[center]) {
    vector<int> inner;
    dfs(v, center, w, inner, dist);
    sort(inner.begin(), inner.end());
    res -= find(inner);
  }
  sort(dist.begin(), dist.end());
  res += find(dist);
  for (auto &u : dist) {
    res += (int) (u <= m);
  }
  for (auto &[v, w] : g[center]) {
    res += solve(v);
  }
  return res;
}

void RunCase() {
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
  }
  cout << solve(0) << '\n';
}

void Init() {
  g.assign(n, vector<pair<int, int>>());
  del.assign(n, false);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  while (cin >> n >> m, n || m) {
    Init();
    RunCase();
  }
  return 0;
}




#include <bits/stdc++.h>

using namespace std;

const int N = 150010;

int n, q, A;
int age[N];
bool del[N];
vector<pair<int, int>> g[N];
// father[u] indicates u's all fathers
struct Father {
  // its father.
  int u;
  // in which of its father's subtree.
  int id;
  // distance from son to its father.
  long long dist;
};
vector<Father> father[N];
// son[u][i] indicates u's all sons when u as a center,
// and i is u's sons id.
struct Son {
  int age;
  // distance from u to its son.
  long long dist;
  bool operator<(const Son &t) const {
    return age < t.age;
  };
};
vector<Son> son[N][3];

int GetSize(int u, int fa) {
  if (del[u]) {
    return 0;
  }
  int res = 1;
  for (auto &[v, w] : g[u]) {
    if (v != fa) {
      res += GetSize(v, u);
    }
  }
  return res;
}

int GetCenter(int u, int fa, int tot, int &center) {
  if (del[u]) {
    return 0;
  }
  int res = 1, mx = 0;
  for (auto &[v, w] : g[u]) {
    if (v != fa) {
      int cnt = GetCenter(v, u, tot, center);
      res += cnt;
      mx = max(mx, cnt);
    }
  }
  mx = max(mx, tot - res);
  if (mx <= tot / 2) {
    center = u;
  }
  return res;
}

void dfs(int u, int fa, long long dist, int center, int id) {
  if (del[u]) {
    return;
  }
  father[u].emplace_back((Father) {center, id, dist});
  son[center][id].emplace_back((Son) {age[u], dist});
  for (auto &[v, w] : g[u]) {
    if (v != fa) {
      dfs(v, u, dist + w, center, id);
    }
  }
}

void solve(int u) {
  if (del[u]) {
    return;
  }
  int center = -1;
  GetCenter(u, -1, GetSize(u, -1), center);
  assert(center != -1);
  del[center] = true;
  int id = 0;
  for (auto &[v, w] : g[center]) {
    dfs(v, center, w, center, id);
    son[center][id].emplace_back((Son) {-1, 0});
    son[center][id].emplace_back((Son) {A + 1, 0});
    sort(son[center][id].begin(), son[center][id].end());
    for (int i = 1; i < (int) son[center][id].size(); i++) {
      son[center][id][i].dist += son[center][id][i - 1].dist;
    }
    id++;
  }
  assert(id <= 3);
  for (auto &[v, w] : g[center]) {
    solve(v);
  }
}

long long query(int u, int l, int r) {
  assert(u != -1 && l <= r);
  long long res = 0;
  for (auto &[u, id, dist] : father[u]) {
    if (age[u] >= l && age[u] <= r) {
      res += dist;
    }
    for (int i = 0; i < 3; i++) {
      if (i == id || (int) son[u][i].size() == 0) {
        continue;
      }
      int ll = (int) (lower_bound(son[u][i].begin(), son[u][i].end(), (Son) {l, -1}) - son[u][i].begin());
      // if use upper_bound, it should be {r, INF}
      int rr = (int) (upper_bound(son[u][i].begin(), son[u][i].end(), (Son) {r, (long long) (4e18)}) - son[u][i].begin());
      res += son[u][i][rr - 1].dist - son[u][i][ll - 1].dist;
      res += dist * (rr - ll);
    }
  }
  for (int i = 0; i < 3; i++) {
    if ((int) son[u][i].size() == 0) {
      continue;
    }
    int ll = (int) (lower_bound(son[u][i].begin(), son[u][i].end(), (Son) {l, -1}) - son[u][i].begin());
    // if use upper_bound, it should be {r, INF}
    int rr = (int) (upper_bound(son[u][i].begin(), son[u][i].end(), (Son) {r, (long long) (4e18)}) - son[u][i].begin());
    res += son[u][i][rr - 1].dist - son[u][i][ll - 1].dist;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> q >> A;
  for (int i = 0; i < n; i++) {
    cin >> age[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
  }
  solve(0);
  long long res = 0;
  for (int i = 0; i < q; i++) {
    int u, a, b;
    cin >> u >> a >> b;
    u--;
    int l = (int) ((a + res) % A), r = (int) ((b + res) % A);
    if (l > r) {
      swap(l, r);
    }
    res = query(u, l, r);
    cout << res << '\n';
  }
  return 0;
}
