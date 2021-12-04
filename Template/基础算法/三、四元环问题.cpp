// 三元环问题
// 在一个无向图上，统计三个点形成的环的个数
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  // 统计度数
  vector<int> d(n);
  for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      g[a].emplace_back(b);
      g[b].emplace_back(a);
      d[a]++, d[b]++;
  }
  vector<vector<int>> tg(n);
  // 两个点，度数小的连上度数大的
  // 度数相等，则编号小的连上编号大的
  for (int i = 0; i < n; i++) {
    for (auto &j : g[i]) {
      if (d[i] < d[j] || d[i] == d[j] && i < j) {
        tg[i].emplace_back(j);
      }
    }
  }
  // 方便编程，交换一下，只用 g[][]
  g.swap(tg);
  // cnt[i] 表示 i 在多少个三元环里
  vector<int> from(n, -1), cnt(n);
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (auto &u : g[i]) {
      from[u] = i;
    }
    for (auto &u : g[i]) {
      for (auto &v : g[u]) {
        if (from[v] == i) {
          cnt[i]++;
          cnt[u]++;
          cnt[v]++;
          res++;
        }
      }
    }
  }
  cout << res << '\n';
  for (auto &u : cnt) {
    cout << u << ' ';
  }
  cout << '\n';
  return 0;
}



// 四元环问题
// 在一个无向图上，统计四个点形成的环的个数
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<int> d(n);
  // 建立原图
  for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      g[a].emplace_back(b);
      g[b].emplace_back(a);
      d[a]++, d[b]++;
  }
  // 在自定的规则下排序
  vector<int> order(n);
  for (int i = 0; i < n; i ++ ) order[i] = i;
  sort(order.begin(), order.end(), [&](int a, int b) {
    return d[a] < d[b] || d[a] == d[b] && a < b;
  });
  // 得到每个点的排名
  vector<int> rank(n);
  for (int i = 0; i < n; i++) {
    rank[order[i]] = i;
  }
  // 建立新图
  vector<vector<int>> f(n);
  for (int i = 0; i < n; i++) {
    for (auto &u : g[i]) {
      if (rank[i] < rank[u]) {
        f[i].emplace_back(u);
      }
    }
  }
  int res = 0;
  // cnt[i] 表示在多少个四元环里
  vector<int> w(n), cnt(n);
  for (int i = 0; i < n; i++) {
    for (auto &u : g[i]) {
      for (auto &v : f[u]) {
        if (rank[i] < rank[v]) {
            cnt[i] += w[v];
            cnt[u] += w[v];
            cnt[v] += w[v];
            res += w[v];
            w[v]++;
        }
      }
    }
    // 要清空 w[]
    for (auto &u : g[i]) {
      for (auto &v : f[u]) {
        if (rank[i] < rank[v]) {
          w[v]--;
          cnt[u] += w[v];
        }
      }
    }
  }
  cout << res << '\n';
  for (auto &u : cnt) {
    cout << u << ' ';
  }
  cout << '\n';
  return 0;
}
