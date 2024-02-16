/**
 * Author: C0ldSmi1e
 * Created Time: 02/05/2024 11:07:40 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc339/tasks/abc339_g
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
    vector<int> val;
    vector<long long> pref;
    void Apply(int l, int r, int v) {
      // [l, r] is range of this node
      assert(l <= r);
      val.resize(r - l + 1);
      val[0] = v;
      pref.resize(r - l + 2);
      pref[1] = v;
    }
  };

  inline Node Unite(const Node& a, const Node& b) const {
    Node res{};
    res.val.insert(res.val.end(), a.val.begin(), a.val.end());
    res.val.insert(res.val.end(), b.val.begin(), b.val.end());
    sort(res.val.begin(), res.val.end());
    int n = (int) res.val.size();
    res.pref.resize(n + 1);
    for (int i = 0; i < n; i++) {
      res.pref[i + 1] = res.pref[i] + res.val[i];
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

  inline long long Query(int u, int l, int r, int ql, int qr, long long x) {
    // [l, r] is range of tr[u]
    // [ql, qr] is range of query
    if (ql <= l && r <= qr) {
      int p = (int) (upper_bound(tr[u].val.begin(), tr[u].val.end(), x) - tr[u].val.begin());
      return tr[u].pref[p];
    }
    int mid = (l + r) >> 1;
    int lson = u + 1, rson = u + ((mid - l + 1) << 1);
    PushDown(u, l, r);
    long long res = 0;
    if (qr <= mid) {
      res = Query(lson, l, mid, ql, qr, x);
    } else if (ql > mid) {
      res = Query(rson, mid + 1, r, ql, qr, x);
    } else {
      res = Query(lson, l, mid, ql, qr, x) + Query(rson, mid + 1, r, ql, qr, x);
    }
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

  inline long long Query(int ql, int qr, long long x) {
    assert(ql >= 0 && ql <= qr && qr < n);
    return Query(0, 0, n - 1, ql, qr, x);
  }

  inline long long Query(int p, long long x) {
    assert(p >= 0 && p < n);
    return Query(0, 0, n - 1, p, p, x);
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

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& u : a) {
    cin >> u;
  }
  SegmentTree st(a);
  int q;
  cin >> q;
  long long res = 0;
  while (q--) {
    long long l, r, x;
    cin >> l >> r >> x;
    l ^= res;
    r ^= res;
    x ^= res;
    --l;
    --r;
    res = st.Query(l, r, x);
    cout << res << '\n';
  }
  return 0;
}

