/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-30 08:24:03
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1916/problem/E
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
    int mx = 0;
    int add = 0;
    void Apply(int l, int r, int v) {
      // [l, r] is range of this node
      assert(l <= r);
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

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
      int fa;
      cin >> fa;
      --fa;
      g[fa].emplace_back(i);
    }
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
      --u;
    }
    vector<vector<int>> G(n);
    vector<int> up(n, -1);
    vector<int> low(n, -1);
    vector<int> order;
    vector<int> in(n);
    vector<int> out(n);
    auto Dfs1 = [&](auto& self, int u) -> void {
      in[u] = (int) order.size();
      order.emplace_back(u);
      up[u] = low[a[u]];
      low[a[u]] = u;
      for (auto& v : g[u]) {
        self(self, v);
      }
      if (up[u] != -1) {
        G[up[u]].emplace_back(u);
      }
      low[a[u]] = up[u];
      out[u] = (int) order.size();
    };
    Dfs1(Dfs1, 0);
    SegmentTree st(n);
    long long res = 1;
    auto Dfs2 = [&](auto& self, int u) -> void {
      for (auto& v : g[u]) {
        self(self, v);
      }
      st.Modify(in[u], out[u] - 1, 1);
      for (auto& v : G[u]) {
        st.Modify(in[v], out[v] - 1, -1);
      }
      int mx1 = 1;
      int mx2 = 1;
      for (auto& v : g[u]) {
        int mx = st.Query(in[v], out[v] - 1).mx;
        if (mx > mx1) {
          mx2 = mx1;
          mx1 = mx;
        } else {
          mx2 = max(mx2, mx);
        }
      }
      debug(u, mx1, mx2);
      res = max(res, 1ll * mx1 * mx2);
    };
    Dfs2(Dfs2, 0);
    cout << res << '\n';
  }
  return 0;
}
