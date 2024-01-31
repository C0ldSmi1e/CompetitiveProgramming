/**
 * Author: C0ldSmi1e
 * Created Time: 01/20/2024 02:49:44 PM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1919/problem/F1
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
    long long val = 0;
    long long mx = 0;
    long long add = 0;
    void Apply(int l, int r, long long v) {
      // [l, r] is range of this node
      assert(l <= r);
      val += v;
      mx += v;
      add += v;
    }
  };

  inline Node Unite(const Node& a, const Node& b) const {
    Node res{};
    res.mx = max(a.mx, b.mx);
    return res;
  }

  inline void PushDown(int u, int l, int r) {
    assert(u >= 0 && u < 2 * n && l <= r);
    int mid = (l + r) >> 1;
    int lson = u + 1, rson = u + ((mid - l + 1) << 1);
    // [l, r] is range of tr[u]
    // pushdown from u into lson and rson
    // remember to clear lazy tag in u
    if (tr[u].add != 0) {
      tr[lson].Apply(l, mid, tr[u].add);
      tr[rson].Apply(mid + 1, r, tr[u].add);
      tr[u].add = 0;
    }
  /*
    if (tr[u].add != 0) {
      tr[lson].Apply(l, mid, tr[u].add);
      tr[rson].Apply(mid + 1, r, tr[u].add);
      tr[u].add = 0;
    }
  */
  }

  inline void PushUp(int u, int lson, int rson) {
    tr[u] = Unite(tr[lson], tr[rson]);
  }

  int n;
  vector<Node> tr;
  
  void Build(int u, int l, int r) {
    if (l == r) {
      return;
    }
    int mid = (l + r) >> 1;
    int lson = u + 1, rson = u + ((mid - l + 1) << 1);
    Build(lson, l, mid);
    Build(rson, mid + 1, r);
    PushUp(u, lson, rson);
  }

  template <typename T>
  void Build(int u, int l, int r, const vector<T> &v) {
    if (l == r) {
      tr[u].Apply(l, r, v[l]);
      return;
    }
    int mid = (l + r) >> 1;
    int lson = u + 1, rson = u + ((mid - l + 1) << 1);
    Build(lson, l, mid, v);
    Build(rson, mid + 1, r, v);
    PushUp(u, lson, rson);
  }

  inline Node Query(int u, int l, int r, int ql, int qr) {
    // [l, r] is range of tr[u]
    // [ql, qr] is range of query
    if (ql <= l && r <= qr) {
      return tr[u];
    }
    int mid = (l + r) >> 1;
    int lson = u + 1, rson = u + ((mid - l + 1) << 1);
    PushDown(u, l, r);
    Node res{};
    if (qr <= mid) {
      res = Query(lson, l, mid, ql, qr);
    } else if (ql > mid) {
      res = Query(rson, mid + 1, r, ql, qr);
    } else {
      res = Unite(Query(lson, l, mid, ql, qr), Query(rson, mid + 1, r, ql, qr));
    }
    PushUp(u, lson, rson);
    return res;
  }

  template <typename... T>
  inline void Modify(int u, int l, int r, int ml, int mr, const T&... v) {
    // [l, r] is range of tr[u]
    // [ml, mr] is range of modification
    if (ml <= l && r <= mr) {
      tr[u].Apply(l, r, v...);
      return;
    }
    int mid = (l + r) >> 1;
    int lson = u + 1, rson = u + ((mid - l + 1) << 1);
    PushDown(u, l, r);
    if (ml <= mid) {
      Modify(lson, l, mid, ml, mr, v...);
    }
    if (mr > mid) {
      Modify(rson, mid + 1, r, ml, mr, v...);
    }
    PushUp(u, lson, rson);
  }

  SegmentTree(int _n) : n(_n) {
    assert(n > 0);
    tr.resize(2 * n - 1);
    Build(0, 0, n - 1);
  }

  template <typename T>
  SegmentTree(const vector<T> &v) {
    n = (int) v.size();
    assert(n > 0);
    tr.resize(2 * n - 1);
    Build(0, 0, n - 1, v);
  }

  inline Node Query(int ql, int qr) {
    assert(ql >= 0 && ql <= qr && qr < n);
    return Query(0, 0, n - 1, ql, qr);
  }

  inline Node Query(int p) {
    assert(p >= 0 && p < n);
    return Query(0, 0, n - 1, p, p);
  }

  template <typename... T>
  inline void Modify(int ml, int mr, const T&... v) {
    assert(ml >= 0 && ml <= mr && mr < n);
    Modify(0, 0, n - 1, ml, mr, v...);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto& u : a) {
    cin >> u;
  }
  vector<int> b(n);
  for (auto& u : b) {
    cin >> u;
  }
  vector<long long> c(n - 1);
  for (auto& u : c) {
    cin >> u;
  }
  SegmentTree st(n);
  long long tot = accumulate(a.begin(), a.end(), 0ll);
  for (int i = 0; i < n; i++) {
    st.Modify(0, i, a[i] - b[i]);
  }
  while (q--) {
    int i, x, y;
    long long z;
    cin >> i >> x >> y >> z;
    --i;
    tot -= a[i];
    st.Modify(0, i, -(a[i] - b[i]));
    a[i] = x;
    b[i] = y;
    tot += a[i];
    st.Modify(0, i, a[i] - b[i]);
    cout << tot - max(0ll, st.Query(0, n - 1).mx) << '\n';
  }
  return 0;
}

