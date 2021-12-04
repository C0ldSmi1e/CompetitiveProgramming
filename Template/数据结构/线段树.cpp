// 普通线段树
const int N = 100010, M = 1010;

int n, m, mod;
LL a[N];
struct Node {
  int l, r;
  LL v, mul, add;
} tr[N << 2];

#define lson (u << 1)
#define rson (u << 1 | 1)

void pushup(int u) {
  tr[u].v = (tr[lson].v + tr[rson].v) % mod;
}

void pushdown(int u) {
  tr[lson].v = (tr[lson].v * tr[u].mul + (tr[lson].r - tr[lson].l + 1) * tr[u].add) % mod;
  tr[rson].v = (tr[rson].v * tr[u].mul + (tr[rson].r - tr[rson].l + 1) * tr[u].add) % mod;
  tr[lson].mul = tr[lson].mul * tr[u].mul % mod;
  tr[rson].mul = tr[rson].mul * tr[u].mul % mod;
  tr[lson].add = (tr[lson].add * tr[u].mul + tr[u].add) % mod;
  tr[rson].add = (tr[rson].add * tr[u].mul + tr[u].add) % mod;
  tr[u].mul = 1, tr[u].add = 0;
}

void build(int u, int l, int r) {
  tr[u] = {l, r, 0, 1, 0};
  if (l == r) {
    tr[u].v = a[r];
  }
  else {
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(u);
  }
}

void modify(int u, int l, int r, LL mul, LL add) {
  if (tr[u].l >= l && tr[u].r <= r) {
    tr[u].v = (tr[u].v * mul + (tr[u].r - tr[u].l + 1) * add) % mod;
    tr[u].mul = tr[u].mul * mul % mod;
    tr[u].add = (tr[u].add * mul + add) % mod;
  } else {
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) {
      modify(lson, l, r, mul, add);
    }
    if (r > mid) {
      modify(rson, l, r, mul, add);
    }
    pushup(u);
  }
}

LL query(int u, int l, int r) {
  if (tr[u].l >= l && tr[u].r <= r) {
    return tr[u].v;
  }
  pushdown(u);
  LL res = 0;
  int mid = tr[u].l + tr[u].r >> 1;
  if (l <= mid) {
    res = (res + query(lson, l, r)) % mod;
  }
  if (r > mid) {
    res = (res + query(rson, l, r)) % mod;
  }
  return res;
}

int main() {
  SOS;
  cin >> n >> m >> mod;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 1, n);
  while (m--) {
    int op, l, r;
    LL k;
    cin >> op >> l >> r;
    if (op == 1) {
      cin >> k;
      modify(1, l, r, k, 0);
    } else if (op == 2) {
      cin >> k;
      modify(1, l, r, 1, k);
    } else {
      cout << query(1, l, r) << '\n';
    }
  }
  return 0;
}



// 扫描线
const int N = 100010, M = 1010;

int n, m;
VE<int> ys;
struct Seg {
  int x, y1, y2, k;
  bool operator<(const Seg &t) const {
    return x < t.x;
  }
} seg[N << 1];
struct Node {
  int l, r, cnt, len;
} tr[N << 3];

int find(int y) {
  return lower_bound(ALL(ys), y) - ys.begin();
}

#define lson (u << 1)
#define rson (u << 1 | 1)

void pushup(int u) {
  if (tr[u].cnt) {
    tr[u].len = ys[tr[u].r + 1] - ys[tr[u].l];
  } else if (tr[u].l == tr[u].r) {
    tr[u].len = 0;
  } else {
    tr[u].len = tr[lson].len + tr[rson].len;
  }
}

void build(int u, int l, int r) {
  tr[u] = {l, r, 0, 0};
  if (l != r) {
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(u);
  }
}

void modify(int u, int l, int r, int k) {
  if (tr[u].l >= l && tr[u].r <= r) {
    tr[u].cnt += k;
    pushup(u);
  } else {
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) modify(lson, l, r, k);
    if (r > mid) modify(rson, l, r, k);
    pushup(u);
  }
}

int main() {
  SOS;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    seg[m++] = {x1, y1, y2, 1};
    seg[m++] = {x2, y1, y2, -1};
    ys.EB(y1);
    ys.EB(y2);
  }
  sort(ALL(ys));
  ys.erase(unique(ALL(ys)), ys.end());
  build(1, 0, SZ(ys) - 2);
  sort(seg, seg + m);
  LL res = 0;
  for (int i = 0; i < m; i++) {
    if (i) {
      res += (LL)tr[1].len * (seg[i].x - seg[i - 1].x);
    }
    modify(1, find(seg[i].y1), find(seg[i].y2) - 1, seg[i].k);
  }
  cout << res << '\n';
  return 0;
}


class SegmentTree {
 public:
  struct Node {
    // remember to set default value
    ...
    void apply(int l, int r, ... v) {
      // [l, r] is range of this node
      assert(l <= r);
      ...
    }
  };

  inline Node unite(const Node &a, const Node &b) const {
    Node res{};
    ...
    return res;
  }

  inline void pushdown(int u, int l, int r) {
    assert(u >= 0 && u < 2 * n && l <= r);
    int mid = (l + r) >> 1;
    int lson = u + 1, rson = u + ((mid - l + 1) << 1);
    // [l, r] is range of tr[u]
    // pushdown from u into lson and rson
    // remember to clear lazy tag in u
    ...
  /*
    if (tr[u].add != 0) {
      tr[lson].apply(l, mid, tr[u].add);
      tr[rson].apply(mid + 1, r, tr[u].add);
      tr[u].add = 0;
    }
  */
  }

  inline void pushup(int u, int lson, int rson) {
    tr[u] = unite(tr[lson], tr[rson]);
  }

  int n;
  vector<Node> tr;
  
  void build(int u, int l, int r) {
    if (l == r) {
      return;
    }
    int mid = (l + r) >> 1;
    int lson = u + 1, rson = u + ((mid - l + 1) << 1);
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(u, lson, rson);
  }

  template <typename T>
  void build(int u, int l, int r, const vector<T> &v) {
    if (l == r) {
      tr[u].apply(l, r, v[l]);
      return;
    }
    int mid = (l + r) >> 1;
    int lson = u + 1, rson = u + ((mid - l + 1) << 1);
    build(lson, l, mid, v);
    build(rson, mid + 1, r, v);
    pushup(u, lson, rson);
  }

  inline Node query(int u, int l, int r, int ql, int qr) {
    // [l, r] is range of tr[u]
    // [ql, qr] is range of query
    if (ql <= l && r <= qr) {
      return tr[u];
    }
    int mid = (l + r) >> 1;
    int lson = u + 1, rson = u + ((mid - l + 1) << 1);
    pushdown(u, l, r);
    Node res{};
    if (qr <= mid) {
      res = query(lson, l, mid, ql, qr);
    } else if (ql > mid) {
      res = query(rson, mid + 1, r, ql, qr);
    } else {
      res = unite(query(lson, l, mid, ql, qr), query(rson, mid + 1, r, ql, qr));
    }
    pushup(u, lson, rson);
    return res;
  }

  template <typename... T>
  inline void modify(int u, int l, int r, int ml, int mr, const T&... v) {
    // [l, r] is range of tr[u]
    // [ml, mr] is range of modification
    if (ml <= l && r <= mr) {
      tr[u].apply(l, r, v...);
      return;
    }
    int mid = (l + r) >> 1;
    int lson = u + 1, rson = u + ((mid - l + 1) << 1);
    pushdown(u, l, r);
    if (ml <= mid) {
      modify(lson, l, mid, ml, mr, v...);
    }
    if (mr > mid) {
       modify(rson, mid + 1, r, ml, mr, v...);
    }
    pushup(u, lson, rson);
  }

  SegmentTree(int _n) : n(_n) {
    assert(n > 0);
    tr.resize(2 * n - 1);
    build(0, 0, n - 1);
  }

  template <typename T>
  SegmentTree(const vector<T> &v) {
    n = (int) v.size();
    assert(n > 0);
    tr.resize(2 * n - 1);
    build(0, 0, n - 1, v);
  }

  inline Node query(int ql, int qr) {
    assert(ql >= 0 && ql <= qr && qr < n);
    return query(0, 0, n - 1, ql, qr);
  }

  inline Node query(int p) {
    assert(p >= 0 && p < n);
    return query(0, 0, n - 1, p, p);
  }

  template <typename... T>
  inline void modify(int ml, int mr, const T&... v) {
    assert(ml >= 0 && ml <= mr && mr < n);
    modify(0, 0, n - 1, ml, mr, v...);
  }
};
