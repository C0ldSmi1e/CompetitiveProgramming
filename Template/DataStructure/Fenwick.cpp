// 一维前缀和：单点修改、区间查询
// tr[] 维护的是 a[] 的前缀和

int n;
LL a[N];
LL tr[N];

#define lowbit(x) (x & -x)

void add(int x, LL c) {
  for (int i = x; i <= n; i += lowbit(i)) {
    tr[i] += c;
  }
}

LL get(int x) {
  LL res = 0;
  for (int i = x; i; i -= lowbit(i)) {
    res += tr[i];
  }
  return res;
}

LL get(int l, int r) {
  return get(r) - get(l - 1);
}

void build(int n) {
  for (int i = 1; i <= n; i++) {
    add(i, a[i]);
  }
}



// 一维前缀和：区间修改、单点查询
// tr[] 维护的是 a[] 的差分数组的前缀和
// 对 i 点增加 x ，要 add(i, x), add(i+1,-x)
int n;
LL a[N];
LL tr[N];

#define lowbit(x) (x & -x)

void add(int x, LL c) {
  for (int i = x; i <= n; i += lowbit(i)) {
    tr[i] += c;
  }
}

void add(int l, int r, LL c) {
  add(l, c);
  add(r + 1, -c);
}

LL get(int x) {
  LL res = 0;
  for (int i = x; i; i -= lowbit(i)) {
    res += tr[i];
  }
  return res;
}

// 初始化
void build(int n) {
  for (int i = 1; i <= n; i++) {
    add(i, i, a[i]);
  }
}



// 一维前缀和：区间修改、区间查询
// tr1[] 维护 a[] 的差分数组 b[] 的前缀和
// tr2[] 维护 b[i] * i 的前缀和
int n;
LL a[N];
LL tr1[N], tr2[N];

#define lowbit(x) (x & -x)

void add(LL tr[], int x, LL c) {
  for (int i = x; i <= n; i += lowbit(i)) {
    tr[i] += c;
  }
}

void add(int l, int r, LL c) {
  add(tr1, l, c);
  add(tr2, l, l * c);
  add(tr1, r + 1, -c);
  add(tr2, r + 1, (r + 1) * -c);
}

LL get(LL tr[], int x) {
  LL res = 0;
  for (int i = x; i; i -= lowbit(i)) {
    res += tr[i];
  }
  return res;
}

LL get(int l, int r) {
  return get(tr1, r) * (r + 1) - get(tr2, r) - get(tr1, l - 1) * l + get(tr2, l - 1);
}

// 初始化
void build(int n) {
  for (int i = 1; i <= n; i++) {
    add(i, i, a[i]);
  }
}



// 二维前缀和：单点修改、区间查询
// 原始数组大小为 n*m
int n, m;
LL a[N][N];
LL tr[N][N];

#define lowbit(x) (x & -x)

void add(int x, int y, LL c) {
  for (int i = x; i <= n; i += lowbit(i)) {
    for (int j = y; j <= m; j += lowbit(j)) {
      tr[i][j] += c;
    }
  }
}

LL get(int x, int y) {
  LL res = 0;
  for (int i = x; i; i -= lowbit(i)) {
    for (int j = y; j; j -= lowbit(j)) {
      res += tr[i][j];
    }
  }
  return res;
}

LL get(int x1, int y1, int x2, int y2) {
  return get(x2, y2) - get(x2, y1 - 1) - get(x1 - 1, y2) + get(x1 - 1, y1 - 1);
}

void build(int n, int m) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      add(i, j, a[i][j]);
    }
  }
}



// 二维前缀和：区间修改、单点查询
// 原始数组大小为 n*m
int n, m;
LL a[N][N];
LL tr[N][N];

#define lowbit(x) (x & -x)

void add(int x, int y, LL c) {
  for (int i = x; i <= n; i += lowbit(i)) {
    for (int j = y; j <= m; j += lowbit(j)) {
      tr[i][j] += c;
    }
  }
}

void add(int x1, int y1, int x2, int y2, LL c) {
  add(x1, y1, c);
  add(x1, y2 + 1, -c);
  add(x2 + 1, y1, -c);
  add(x2 + 1, y2 + 1, c);
}

LL get(int x, int y) {
  LL res = 0;
  for (int i = x; i; i -= lowbit(i)) {
    for (int j = y; j; j -= lowbit(j)) {
      res += tr[i][j];
    }
  }
  return res;
}

void build(int n, int m) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      add(i, j, i, j, a[i][j]);
    }
  }
}



// 二维前缀和：区间修改、区间查询
// 原始数组大小为 n*m
// 推导的思路和一维相似，但有些复杂
int n, m;
LL a[N][N];
LL tr1[N][N], tr2[N][N], tr3[N][N], tr4[N][N];

#define lowbit(x) (x & -x)

void add(int x, int y, LL c) {
  for (int i = x; i <= n; i += lowbit(i)) {
    for (int j = y; j <= m; j += lowbit(j)) {
      tr1[i][j] += c;
      tr2[i][j] += c * x;
      tr3[i][j] += c * y;
      tr4[i][j] += c * x * y;
    }
  }
}

void add(int x1, int y1, int x2, int y2, LL c) {
  add(x1, y1, c);
  add(x1, y2 + 1, -c);
  add(x2 + 1, y1, -c);
  add(x2 + 1, y2 + 1, c);
}

LL get(int x, int y) {
  LL res = 0;
  for (int i = x; i; i -= lowbit(i)) {
    for (int j = y; j; j -= lowbit(j)) {
      res += (x + 1) * (y + 1) * tr1[i][j];
      res -= (y + 1) * tr2[i][j];
      res -= (x + 1) * tr3[i][j];
      res += tr4[i][j];
    }
  }
  return res;
}

LL get(int x1, int y1, int x2, int y2) {
  return get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1);
}

void build(int n, int m) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      add(i, j, i, j, a[i][j]);
    }
  }
}



// O(n) 建树
// 可以在建树阶段稍作优化
void build() {
  for (int i = 1; i <= n; ++i) {
    tr[i] += a[i];
    int j = i + lowbit(i);
    if (j <= n) {
      tr[j] += tr[i];
    }
  }
}



// 时间戳优化
int mark[N], tr[N], timestamp;

// 处理每组数据前先更新时间戳
void reset() {
	timestamp ++ ;
}

void add(int x, int c) {
  for (int i = x; i <= n; i += lowbit(i)) {
    if (mark[i] != timestamp) {
      tr[i] = 0;
    }
    mark[i] = timestamp;
    tr[i] += c;
  }
}

int get(int x) {
  int res = 0;
  for (int i = x; i; i -= lowbit(i)) {
    if (mark[x] == timestamp) {
      res += tr[x];
    }
  }
  return res;
}



// 树状数组求最值


/**
 * 树状数组维护区间最值可以支持静态区间查询或者单点修改+区间查询，一般静态可以用 ST 表，动态可以用线段树，但其实也挺好用的，它会比 ST 表更加省空间，每次询问的时间复杂度是 O(logn) ，会比线段树容易写。
 * 
 * 这里有几道可以验证代码的模板题：
 * 
 * 1. [Balanced Lineup](https://vjudge.net/problem/POJ-3264) 
 * 2. [天才的记忆](https://www.acwing.com/problem/content/1275/) 
 * 3. [P3865 【模板】ST表](https://www.luogu.com.cn/problem/P3865) 
**/

// 最大值模板
// 其中 a[] 是原始数组, n 为原始数组大小
// 且原始数组的下标从 1 开始

// 若不需要动态修改，可以直接 build() + query()
// 若需要动态修改，则用 update() + query()

// 此模板需要同时维护一个原始数组 a[]

#define lowbit(x) (x & -x)

void build(int n) {
  for (int i = 1; i <= n; i++) {
    tr[i] = a[i];
    for (int j = 1; j < lowbit(i); j <<= 1) {
      tr[i] = max(tr[i], tr[i - j]);
    }
  }
}

void update(int x) {
  for (int i = x; i <= n; i += lowbit(i)) {
		tr[i] = a[i];
    int len = lowbit(i);
    for (int j = 1; j < len; j <<= 1) {
			tr[i] = max(tr[i], tr[i - j]);
    }
	}
}

// 求 [l,r] 最大值
int query(int l, int r) {
	int res = a[r];
  while (true) {
		res = max(res, a[r]);
    if (l == r) {
      break;
    }
    for (r--; r - lowbit(r) >= l; r -= lowbit(r)) {
      res = max(res, tr[r]);
    }
	}
	return res;
}

// 最小值模板

#define lowbit(x) (x & -x)

void build(int n) {
  for (int i = 1; i <= n; i++) {
    tr[i] = a[i];
    for (int j = 1; j < lowbit(i); j <<= 1) {
      tr[i] = min(tr[i], tr[i - j]);
    }
  }
}

void update(int x) {
  for (int i = x; i <= n; i += lowbit(i)) {
    tr[i] = a[i];
    int len = lowbit(i);
    for (int j = 1; j < len; j <<= 1) {
      tr[i] = min(tr[i], tr[i - j]);
    }
  }
}

// 求 [l,r] 最小值
int query(int l, int r) {
  int res = a[r];
  while (true) {
    res = min(res, a[r]);
    if (l == r) {
      break;
    }
    for (r--; r - lowbit(r) >= l; r -= lowbit(r)) {
      res = min(res, tr[r]);
    }
  }
  return res;
}

// 如果不想维护原始数组，直接在树状数组上操作则如下（以最大值为例）
void update(int x, int c) {
  for (int i = x; i <= n; i += lowbit(i)) {
    tr[i] = max(tr[i], c);
    int len = lowbit(i);
    for (int j = 1; j < len; j <<= 1) {
      tr[i] = max(tr[i], tr[i - j]);
    }
  }
}
 
int query(int l, int r) {
  int res = -INF;
  while (true) {
    res = max(res, tr[r]);
    if (l == r) {
      break;
    }
    for (r -- ; r - lowbit(r) >= l; r -= lowbit(r)) {
      res = max(res, tr[r]);
    }
  }
  return res;
}


// 求第 k 小值
// 建立权值树状数组，统计每个元素出现的次数
// MAX_VAL 为可能出现的最大值
int FindKthMin(int k) {
  int cnt = 0, x = 0;
  for (int i = log2(MAX_VAL); i >= 0; i--) {
    x += (1 << i);
    if (x >= MAX_VAL || cnt + tr[x] >= k) {
      x -= (1 << i);
    } else {
      cnt += tr[x];
    }
  }
  return x + 1;
}

// 用法（输出第 k 小值）
cout << FindKthMin(k) << endl;



// 求第 k 大值
// 建立权值树状数组，统计每个元素出现的次数
// MAX_VAL 为可能出现的最大值
int FindKthMax(int k) {
  // 第 k 大即第 n-k+1 小， n 为序列元素个数
  k = n - k + 1;
  int cnt = 0, x = 0;
  for (int i = log2(MAX_VAL); i >= 0; i--) {
    x += (1 << i);
    if (x >= MAX_VAL || cnt + tr[x] >= k) {
      x -= (1 << i);
    } else {
      cnt += tr[x];
    }
  }
  return x + 1;
}

// 用法（输出第 k 大值）
cout << FindKthMax(k) << endl;



// 如下标从 0 开始，只需要在处理时先将坐标加 1



// 面向对象写法
// 普通树状数组
template <typename T>
class Fenwick {
 public:
  vector<T> fenw;
  int n;
  Fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }
  inline void add(int x, T v) {
    assert(x >= 0 && x < n);
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
  inline T get(int x) {
    T res{};
    while (x >= 0) {
      res += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return res;
  }
  inline T get(int l, int r) {
    assert(l >= 0 && l < n && r >= 0 && r < n);
    T res = get(r);
    if (l - 1 >= 0) {
      res -= get(l - 1);
    }
    return res;
  }
  inline int kthMin(int k) {
    // kthMax = n - kthMin + 1
    assert(k >= 1 && k <= n);
    int cnt = 0, x = 0;
    for (int i = (int) log2(n); i >= 0; i--) {
      x += (1 << i);
      if (x >= n || cnt + fenw[x - 1] >= k) {
        x -= (1 << i);
      } else {
        cnt += fenw[x - 1];
      }
    }
    return x;
  }
};

// struct Node {
//   int a = ...; // don't forget to set default value
//   inline void operator += (Node &other) {
//     ...
//   }
// };



// 求区间最值，支持单点修改和区间查询，可以代替RMQ
// usage:
//   auto fun = [&](int i, int j) { return min(i, j); };
//   Fenwick<int, decltype(fun)> fen(a, fun);
// or:
//   Fenwick<int> fen(a, [&](int i, int j) { return min(i, j); });
#define lowbit(x) (x&(-x))
template <typename T, class F = function<T(const T&, const T&)>>
class Fenwick {
 public:
  int n;
  vector<T> val, fenw;
  F func;
  Fenwick (const vector<T>& a, const F& f) : func(f) {
    n = static_cast<int>(a.size());
    val.resize(n);
    fenw.resize(n);
    for (int i = 1; i <= n; i++) {
      val[i - 1] = fenw[i - 1] = a[i - 1];
      int len = lowbit(i);
      for (int j = 1; j < len; j <<= 1) {
        fenw[i - 1] = func(fenw[i - 1], fenw[i - j - 1]);
      }
    }
  }
  // change value at k to v
  // k is [0, n)
  inline void Modify(int k, T v) {
    assert(k >= 0 && k < n);
    val[k] = v;
    for (int i = k + 1; i <= n; i += lowbit(i)) {
      fenw[i - 1] = val[i - 1];
      int len = lowbit(i);
      for (int j = 1; j < len; j <<= 1) {
        fenw[i - 1] = func(fenw[i - 1], fenw[i - j - 1]);
      }
    }
  }
  // l and r are [0, n)
  // ask for [l, r]
  inline T Query(int l, int r) {
    assert(l >= 0 && l < n);
    assert(r >= 0 && r < n);
    ++l, ++r;
    T res = val[r - 1];
    while (true) {
      res = func(res, val[r - 1]);
      if (l == r) break;
      for (--r; r - lowbit(r) >= l; r -= lowbit(r)) {
        res = func(res, fenw[r - 1]);
      }
    }
    return res;
  }
};



// 二维
// 2D Fenwick
template <typename T>
class Fenwick {
 public:
  vector<vector<T> > fenw;
  int n, m;
  Fenwick(int _n, int _m) : n(_n), m(_m) {
    fenw.resize(n + 1);
    for (int i = 0; i < n; i++) {
      fenw[i].resize(m);
    }
  }
  // Change value at (x, y) to v
  inline void add(int x, int y, T v) {
    assert(x >= 0 && x < n && y >= 0 && y < m);
    for (int i = x + 1; i <= n; i += lowbit(i)) {
      for (int j = y + 1; j <= m; j += lowbit(j)) {
        fenw[i - 1][j - 1] += v;
      }
    }
  }
  inline T get(int x, int y) {
    assert(x >= 0 && x < n && y >= 0 && y < m);
    T res{};
    for (int i = x + 1; i >= 1; i -= lowbit(i)) {
      for (int j = y + 1; j >= 1; j -= lowbit(j)) {
        res += fenw[i - 1][j - 1];
      }
    }
    return res;
  }
  // ask for [x1, x2] and [y1, y2]
  inline T get(int x1, int y1, int x2, int y2) {
    assert (x1 <= x2 && y1 <= y1);
    assert(x1 >= 0 && x1 < n && x2 >= 0 && x2 < n);
    assert(y1 >= 0 && y1 < m && y2 >= 0 && y2 < m);
    T res = get(x2, y2);
    if (x1 - 1 >= 0) {
      res -= get(x1 - 1, y2);
    }
    if (y1 - 1 >= 0) {
      res -= get(x2, y1 - 1);
    }
    if (x1 - 1 >= 0 && y1 - 1 >= 0) {
      res += get(x1 - 1, y1 - 1);
    }
    return res;
  }
};

// struct Node {
//   int a = ...; // don't forget to set default value
//   inline void operator += (Node &other) {
//     ...
//   }
// };
