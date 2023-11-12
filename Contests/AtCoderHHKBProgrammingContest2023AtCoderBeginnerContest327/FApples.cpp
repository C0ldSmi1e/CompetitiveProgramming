/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-04 06:12:04
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc327/tasks/abc327_f
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

class SegmentTree {
 public:
  struct Node {
    // remember to set default value
    int add = 0;
    int mx = 0;
    int sum = 0;
    void apply(int l, int r, int v) {
      // [l, r] is range of this node
      assert(l <= r);
      add += v;
      sum += (r - l + 1) * v;
      mx += v;
    }
  };

  inline Node unite(const Node &a, const Node &b) const {
    Node res{};
    res.mx = max(a.mx, b.mx);
    res.sum = a.sum + b.sum;
    return res;
  }

  inline void pushdown(int u, int l, int r) {
    assert(u >= 0 && u < 2 * n && l <= r);
    int mid = (l + r) >> 1;
    int lson = u + 1, rson = u + ((mid - l + 1) << 1);
    // [l, r] is range of tr[u]
    // pushdown from u into lson and rson
    // remember to clear lazy tag in u
    if (tr[u].add != 0) {
      tr[lson].apply(l, mid, tr[u].add);
      tr[rson].apply(mid + 1, r, tr[u].add);
      tr[u].add = 0;
    }
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);

  int n, d, w;
  cin >> n >> d >> w;
  const int N = (int) 2e5 + 5;
  vector<vector<int>> pos(N);
  for (int i = 0; i < n; i++) {
    int t, x;
    cin >> t >> x;
    --t;
    --x;
    pos[x].emplace_back(t);
  }
  SegmentTree st(N);
  for (int i = 0; i < w - 1; i++) {
    for (auto& u : pos[i]) {
      int l = u;
      int r = min(N - 1, u + d - 1);
      st.modify(l, r, 1);
    }
  }
  int res = 0;
  for (int i = w - 1; i < N; i++) {
    for (auto& u : pos[i]) {
      int l = u;
      int r = min(N - 1, u + d - 1);
      st.modify(l, r, 1);
    }
    res = max(res, st.query(0, N - 1).mx);
    for (auto& u : pos[i - w + 1]) {
      int l = u;
      int r = min(N - 1, u + d - 1);
      st.modify(l, r, -1);
    }
  }
  cout << res << '\n';
  return 0;
}
