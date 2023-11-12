// 维护集合元素个数
// p[] 存储每个点的祖宗节点, size[] 只有祖宗节点的有意义，表示祖宗节点所在集合中的点的数量
int p[N], size[N];
// 返回 x 的祖宗节点
int find(int x) {
  if (p[x] != x) {
    p[x] = find(p[x]);
  }
  return p[x];
}

// 初始化，假定节点编号是 1~n
for (int i = 1; i <= n; i++) {
  p[i] = i;
  size[i] = 1;
}
// 合并 a 和 b 所在的两个集合：
size[find(b)] += size[find(a)];
p[find(a)] = find(b);



// 维护到祖宗节点距离
int p[N], d[N];
// p[] 存储每个点的祖宗节点, d[x] 存储x到 p[x] 的距离
// 返回x的祖宗节点
int find(int x) {
  if (p[x] != x) {
    int u = find(p[x]);
    d[x] += d[p[x]];
    p[x] = u;
  }
  return p[x];
}

// 初始化，假定节点编号是1~n
for (int i = 1; i <= n; i++) {
  p[i] = i;
  d[i] = 0;
}

// 合并a和b所在的两个集合：
p[find(a)] = find(b);
d[find(a)] = distance; // 根据具体问题，初始化find(a)的偏移量

class Dsu {
 public:
  vector<int> p, sz;
  int n;
  Dsu(int _n) {
    n = _n + 1;
    p.resize(n);
    sz.assign(n, 1);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      sz[y] += sz[x];
      return true;
    }
    return false;
  }
  inline int getSize(int x) {
    return sz[get(x)];
  }
};
