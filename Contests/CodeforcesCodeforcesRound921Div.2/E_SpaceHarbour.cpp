/**
 * Author: C0ldSmi1e
 * Created Time: 01/31/2024 07:50:26 PM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1925/problem/E
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
    long long sum = 0;
    long long b = 0;
    long long k = 0;
    long long i = -1;
    void Apply(int l, int r, long long _b, long long _k) {
      // [l, r] is range of this node
      assert(l <= r);
      b = _b;
      k = _k;
      sum = (r - l + 1) * b - i * k;
    }
  };

  inline Node Unite(const Node& a, const Node& b) const {
    Node res{};
    res.sum = a.sum + b.sum;
    res.i = a.i + b.i;
    return res;
  }

  inline void PushDown(int u, int l, int r) {
    assert(u >= 0 && u < 2 * n && l <= r);
    int mid = (l + r) >> 1;
    int lson = u + 1, rson = u + ((mid - l + 1) << 1);
    // [l, r] is range of tr[u]
    // pushdown from u into lson and rson
    // remember to clear lazy tag in u
    if (tr[u].b != 0) {
      tr[lson].Apply(l, mid, tr[u].b, tr[u].k);
      tr[rson].Apply(mid + 1, r, tr[u].b, tr[u].k);
      tr[u].b = tr[u].k = 0;
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
      tr[u].i = l;
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

  int n, m, q;
  cin >> n >> m >> q;
  vector<int> x(m);
  for (auto& u : x) {
    cin >> u;
    --u;
  }
  vector<int> v(m);
  for (auto& u : v) {
    cin >> u;
  }
  map<int, int> mp;
  for (int i = 0; i < m; i++) {
    mp[x[i]] = v[i];
  }
  SegmentTree st(n);
  for (int i = 0; i < n; i++) {
    auto it = mp.lower_bound(i);
    if ((*it).first == i) {
      st.Modify(i, i, 1ll * (*it).first * (*it).second, (*it).second);
    } else {
      int ri = (*it).first;
      assert(it != mp.begin());
      --it;
      st.Modify(i, i, 1ll * (*it).second * ri, (*it).second);
    }
  }
  //for (int i = 0; i < n; i++) {
  //  cout << st.Query(i, i).sum << " \n"[i == n - 1];
  //}
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, v;
      cin >> x >> v;
      --x;
      mp[x] = v;
      auto it = mp.lower_bound(x);
      {
        assert(it != mp.end());
        auto rit = next(it);
        st.Modify(x + 1, (*rit).first, 1ll * v * (*rit).first, v);
      }
      {
        assert(it != mp.begin());
        auto lit = prev(it);
        st.Modify((*lit).first + 1, x, 1ll * (*lit).second * x, (*lit).second);
      }
    } else {
      int l, r;
      cin >> l >> r;
      --l;
      --r;
      cout << st.Query(l, r).sum << '\n';
    }
    //for (int i = 0; i < n; i++) {
    //  cout << st.Query(i, i).sum << " \n"[i == n - 1];
    //}
  }
  return 0;
}
