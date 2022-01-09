/**
 * Author: Daniel
 * Created Time: 2022-01-05 19:38:44
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1621/problem/E
#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
#define ER erase
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define MP make_pair
#define MT make_tuple
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define lowbit(x) (x & -x)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define SOS(x) ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(x)

typedef long long LL;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef long double LD;
typedef vector<char> VC;
typedef vector<bool> VB;
typedef pair<LL, LL> PLL;
typedef vector<string> VS;
typedef vector<double> VD;
typedef pair<int, int> PII;
typedef unsigned long long ULL;
typedef pair<double, double> PDD;
typedef tuple<int, int, int> TIII;
typedef vector<pair<LL, LL> > VPLL;
typedef vector<pair<int, int> > VPII;
typedef vector<tuple<int, int, int> > VTIII;

template <typename A> using VE = vector<A>;
template <typename A> using USET = unordered_set<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A, typename B> using UMAP = unordered_map<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A>>;

template <typename A> A MAX(const A &a) { return a; }
template <typename A> A MIN(const A &a) { return a; }
template <typename A> A MAX(const A *a, const A *b) { return *max_element(a, b); }
template <typename A> A MIN(const A *a, const A *b) { return *min_element(a, b); }
template <typename A> int CNT(const A *a, const A *b, const A &v) { return int(count(a, b, v)); }
template <typename A, typename... B> A MAX(const A &a, const B&... b) { return max(a, MAX(b...)); }
template <typename A, typename... B> A MIN(const A &a, const B&... b) { return min(a, MIN(b...)); }
template <typename A, typename B = typename std::iterator_traits<A>::value_type> B MAX(const A &a, const A &b) { return *max_element(a, b); }
template <typename A, typename B = typename std::iterator_traits<A>::value_type> B MIN(const A &a, const A &b) { return *min_element(a, b); }
template <typename A, typename B = typename std::iterator_traits<A>::value_type> int CNT(const A &a, const A &b, const B &v) { return int(count(a, b, v)); }

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 100010, M = 1010;

class SegmentTree {
 public:
  struct Node {
    // remember to set default value
    int mn = 0, add = 0;
    void apply(int l, int r, int v) {
      // [l, r] is range of this node
      assert(l <= r);
      add += v;
      mn += v;
    }
  };

  inline Node unite(const Node &a, const Node &b) const {
    Node res{};
    res.mn = min(a.mn, b.mn);
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

// read the question carefully!!!
int main() {
  SOS(10);

  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    SegmentTree st(N);
    VI a(n);
    for (auto &u : a) {
      cin >> u;
      st.modify(0, u, 1);
    }
    VI sz(m);
    VE<VI> b(m);
    VL sum(m);
    VI v(m);
    for (int i = 0; i < m; i++) {
      cin >> sz[i];
      b[i].resize(sz[i]);
      for (auto &u : b[i]) {
        cin >> u;
        sum[i] += u;
      }
      v[i] = (int) ((sum[i] + sz[i] - 1) / sz[i]);
      st.modify(0, v[i], -1);
    }
    for (int i = 0; i < m; i++) {
      st.modify(0, v[i], 1);
      for (auto &u : b[i]) {
        int w = (int) ((sum[i] - u + sz[i] - 2) / (sz[i] - 1));
        st.modify(0, w, -1);
        cout << (st.query(0, N - 1).mn >= 0 ? '1' : '0');
        st.modify(0, w, 1);
      }
      st.modify(0, v[i], -1);
    }
    cout << '\n';
  }
  return 0;
}

// GOOD LUCK!!!
