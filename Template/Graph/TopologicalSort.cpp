// 拓扑排序
// 时间复杂度为 O(n+m)
// 广搜
bool topsort() {
  int hh = 0, tt = -1;
  // d[i] 存储点i的入度
  for (int i = 1; i <= n; i++) {
    if (!d[i]) {
      q[++tt] = i;
    }
  }
  while (hh <= tt) {
    int t = q[hh ++ ];
    for (int i = h[t]; i != -1; i = ne[i]) {
      int j = e[i];
      if (-- d[j] == 0) {
        q[++tt] = j;
      }
    }
  }
  // 如果所有点都入队了，说明存在拓扑序列；否则不存在拓扑序列。
  return tt == n - 1;
}
// 深搜
vector<int> ord;  // 保存拓扑序
int p[N];  // p[i]表示i点在拓扑序中的位置
bool st[N];  // 是否遍历过

void dfs(int u) {
  st[u] = true;
  for (int i = h[u]; ~i; i = ne[i]) {
    int j = e[i];
    if (!st[j]) {
      dfs(j);
    }
  }
  ord.PB(u);
}

for (int i = 1; i <= n; i++) {
  if (!st[i]) {
    dfs(i);
  }
}

reverse(ord.begin(), ord.end());

// 现在ord保存的是拓扑序

// 以下可以判断两点之间的拓扑序
for (int i = 0; i < n; i++) {
  p[ord[i]] = i;
}

// 本方法无论图中是否有环，都会保存所有的点
// 可以通过以下方法判断是否存在环
bool exist_circle = false;
for (int t = 1; t <= n; t++) {
  for (int i = h[t]; ~i; i = ne[i]) {
    int j = e[i];
    if (p[j] < p[t]) {
      exist_circle = true;
    }
  }
}
