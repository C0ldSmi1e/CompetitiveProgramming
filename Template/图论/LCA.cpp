// 判断 (a,b) 谁是祖先
const int N = 40010, M = 2 * N, K = 16;

int n, m, root;
int h[N], e[M], ne[M], idx;
int q[N], depth[N], fa[N][K];

int lca(int a, int b) {
  if (depth[a] < depth[b]) {
    swap(a, b);
  }
  for (int k = K - 1; k >= 0; k--) {
    if (depth[fa[a][k]] >= depth[b]) {
      a = fa[a][k];
    }
  }
  if (a == b) {
    return b;
  }
  for (int k = K - 1; k >= 0; k--) {
    if (fa[a][k] != fa[b][k]) {
      a = fa[a][k], b = fa[b][k];
    }
  }
  return fa[a][0];
}

void bfs(int root) {
  memset(depth, 0x3f, sizeof depth);
  depth[0] = 0;
  depth[root] = 1;
  int hh = 0, tt = -1;
  q[++tt] = root;
  while (hh <= tt) {
    int t = q[hh++];
    for (int i = h[t]; ~i; i = ne[i]) {
      int j = e[i];
      if (depth[j] > depth[t]) {
        depth[j] = depth[t] + 1;
        q[ ++ tt] = j;
        fa[j][0] = t;
        for (int k = 1; k < K; k++) {
          fa[j][k] = fa[fa[j][k - 1]][k - 1];
        }
      }
    }
  }
}

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (b == -1) root = a;
    add(a, b), add(b, a);
  }
  bfs(root);
  scanf("%d", &m);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    int p = lca(a, b);
    if (a == p) {
      puts("1");
    } else if (b == p) {
      puts("2");
    } else {
      puts("0");
    }
  }
  return 0;
}



// 判断树上两点最短距离
const int N = 100010, M = 2 * N;

int n, m;
int h[N], e[M], w[M], ne[M], idx;
int depth[N], fa[N][16];
int q[N], dist[N];
bool st[N];

void add_edge(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void bfs(int root) {
  memset(depth, 0x3f, sizeof depth);
  depth[0] = 0;
  depth[root] = 1;
  dist[root] = 0;
  int hh = 0, tt = -1;
  q[++tt ] = root;
  st[root] = true;
  while (hh <= tt) {
    int t = q[hh++];
    for (int i = h[t]; ~i; i = ne[i]) {
      int j = e[i];
      if (st[j]) {
        continue;
      }
      dist[j] = dist[t] + w[i];
      depth[j] = depth[t] + 1;
      fa[j][0] = t;
      for (int k = 1; k <= 15; k++) {
        fa[j][k] = fa[fa[j][k - 1]][k - 1];
      }
      q[++tt] = j;
      st[j] = true;
    }
  }
}

int lca(int a, int b) {
  if (depth[a] < depth[b]) {
    swap(a, b);
  }
  for (int k = 15; k >= 0; k--) {
    if (depth[fa[a][k]] >= depth[b]) {
      a = fa[a][k];
    }
  }
  if (a == b) {
    return a;
  }
  for (int k = 15; k >= 0; k--) {
    if (fa[a][k] != fa[b][k]) {
      a = fa[a][k];
      b = fa[b][k];
    }
  }
  return fa[a][0];
}

int get(int a, int b) {
  int ac = lca(a, b);
  return dist[a] + dist[b] - 2 * dist[ac];
}

// read the question carefully!!!
int main() {
  memset(h, -1, sizeof h);
  cin >> n >> m;
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    add_edge(a, b, c);
    add_edge(b, a, c);
  }
  // 注意根是 1
  bfs(1);
  while (m--) {
    int a, b;
    cin >> a >> b;
    cout << get(a, b) << '\n';
  }
  return 0;
}



// 次小生成树（非严格和严格只需要改一下 lca() ）
// 设最小生成树的边权之和为 sum 
// 严格次小生成树就是指边权之和大于 sum 的生成树中最小的一个
const int N = 100010, M = 300010, K = 17, INF = 0x3f3f3f3f;

int n, m;
int h[N], e[M], w[M], ne[M], idx;
int q[N], depth[N], fa[N][K];
int d1[N][K], d2[N][K];
int p[N];
struct Edge {
  int a, b, c;
  bool f;
  bool operator<(const Edge &t) const {
    return c < t.c;
  }
} edge[M];

int lca(int a, int b, int c) {
  static int dist[M];
  int cnt = 0;
  if (depth[a] < depth[b]) swap(a, b);
  for (int k = K - 1; k >= 0; k--) {
    if (depth[fa[a][k]] >= depth[b]) {
        dist[cnt++] = d1[a][k];
        dist[cnt++] = d2[a][k];
        a = fa[a][k];
    }
  }
  if (a != b) {
    for (int k = K - 1; k >= 0; k -- ) {
      if (fa[a][k] != fa[b][k]) {
        dist[cnt++] = d1[a][k];
        dist[cnt++] = d2[a][k];
        dist[cnt++] = d1[b][k];
        dist[cnt++] = d2[b][k];
        a = fa[a][k], b = fa[b][k];
      }
    }
    dist[cnt++] = d1[a][0];
    dist[cnt++] = d1[b][0];
  }
  int dist1 = -INF, dist2 = -INF;
  for (int i = 0; i < cnt; i++) {
    int d = dist[i];
    if (d > dist1) {
      dist2 = dist1;
      dist1 = d;
    } else if (d != dist1 && d > dist2) {
      dist2 = d;
    }
  }
  if (c != dist1) {
    return c - dist1;
  }
  return c - dist2;
}

void bfs(int root) {
  memset(depth, 0x3f, sizeof depth);
  depth[0] = 0;
  depth[root] = 1;
  int hh = 0, tt = -1;
  q[++tt] = root;
  while (hh <= tt) {
    int t = q[hh++];
    for (int i = h[t]; ~i; i = ne[i]) {
      int j = e[i];
      if (depth[j] > depth[t]) {
        depth[j] = depth[t] + 1;
        q[ ++ tt] = j;
        fa[j][0] = t, d1[j][0] = w[i], d2[j][0] = -INF;
        for (int k = 1; k < K; k++) {
          int anc = fa[j][k - 1];
          fa[j][k] = fa[anc][k - 1];
          int dist[4] = {d1[j][k - 1], d2[j][k - 1], d1[anc][k - 1], d2[anc][k - 1]};
          for (int u = 0; u < 4; u++) {
            int d = dist[u];
            if (d > d1[j][k]) {
              d2[j][k] = d1[j][k], d1[j][k] = d;
            } else if (d != d1[j][k] && d > d2[j][k]) {
              d2[j][k] = d; 
            }
          }
        }
      }
    }
  }
}

int find(int x) {
  if (x != p[x]) {
    p[x] = find(p[x]);
  }
  return p[x];
}

LL Kruskal() {
  for (int i = 1; i <= n; i++) {
    p[i] = i;
  }
  sort(edge, edge + m);
  LL sum = 0;
  for (int i = 0; i < m; i++) {
    int a = edge[i].a, b = edge[i].b, c = edge[i].c;
    int pa = find(a), pb = find(b);
    if (pa != pb) {
      p[pa] = pb;
      sum += c;
      edge[i].f = true;
    }
  }
  return sum;
}

void add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void build() {
  memset(h, -1, sizeof h);
  for (int i = 0; i < m; i ++ ) {
    if (edge[i].f) {
      int a = edge[i].a, b = edge[i].b, c = edge[i].c;
      add(a, b, c), add(b, a, c);
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    edge[i] = {a, b, c};
  }
  LL sum = Kruskal();
  build();
  // 注意根是 1
  bfs(1);
  LL res = (LL) 1e18;
  for (int i = 0; i < m; i++) {
    if (!edge[i].f) {
      int a = edge[i].a, b = edge[i].b, c = edge[i].c;
      res = min(res, sum + lca(a, b, c));
    }
  }
  printf("%lld\n", res);
  return 0;
}
