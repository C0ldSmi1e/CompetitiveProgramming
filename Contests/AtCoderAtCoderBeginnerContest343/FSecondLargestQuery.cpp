/**
 * Author: C0ldSmi1e
 * Created Time: 03/07/2024 02:25:28 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc343/tasks/abc343_f
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
    int mx = 0, mxc = 0;
    int mxx = 0, mxxc = 0;
    inline void Apply(int l, int r, int v) {
      // [l, r] is range of this node
      assert(l <= r);
      mx = v;
      mxc = 1;
      mxx = mxxc = 0;
    }
  };

  inline Node Unite(const Node& a, const Node& b) const {
    Node res{};
    if (a.mx == b.mx) {
      res.mx = a.mx;
      res.mxc = a.mxc + b.mxc;
      if (a.mxx == b.mxx) {
        res.mxx = a.mxx;
        res.mxxc = a.mxxc + b.mxxc;
      } else if (a.mxx > b.mxx) {
        res.mxx = a.mxx;
        res.mxxc = a.mxxc;
      } else {
        res.mxx = b.mxx;
        res.mxxc = b.mxxc;
      }
    } else if (a.mx > b.mx) {
      res.mx = a.mx;
      res.mxc = a.mxc;
      if (a.mxx == b.mx) {
        res.mxx = a.mxx;
        res.mxxc = a.mxxc + b.mxc;
      } else if (a.mxx > b.mx) {
        res.mxx = a.mxx;
        res.mxxc = a.mxxc;
      } else {
        res.mxx = b.mx;
        res.mxxc = b.mxc;
      }
    } else {
      res.mx = b.mx;
      res.mxc = b.mxc;
      if (a.mx == b.mxx) {
        res.mxx = a.mx;
        res.mxxc = a.mxc + b.mxxc;
      } else if (a.mx > b.mxx) {
        res.mxx = a.mx;
        res.mxxc = a.mxc;
      } else {
        res.mxx = b.mxx;
        res.mxxc = b.mxxc;
      }
    }
    return res;
  }

  inline void PushDown(int u, int l, int r) {
    assert(u >= 0 && u < 2 * n && l <= r);
    //int mid = (l + r) >> 1;
    //int lson = u + 1, rson = u + ((mid - l + 1) << 1);
    // [l, r] is range of tr[u]
    // pushdown from u into lson and rson
    // remember to clear lazy tag in u
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
  SegmentTree st(a);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int i, x;
      cin >> i >> x;
      --i;
      st.Modify(i, i, x);
    } else {
      int l, r;
      cin >> l >> r;
      --l;
      --r;
      auto res = st.Query(l, r);
      cout << res.mxxc << '\n';
    }
  }
  return 0;
}
