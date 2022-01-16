/**
 * Author: Daniel
 * Created Time: 2022-01-15 20:28:55
**/

// time-limit: 4000
// problem-url: https://atcoder.jp/contests/abc235/tasks/abc235_e
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
typedef vector<pair<LL, LL>> VPLL;
typedef vector<pair<int, int>> VPII;
typedef vector<tuple<int, int, int>> VTIII;

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

template <typename A, typename B>
string to_string(pair<A, B> p);

string to_string(const string& s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string)s); } 

string to_string(const char c) { return to_string((string)"" + c); } 

string to_string(bool b) { return (b ? "true" : "false"); }

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    } 
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
    res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A>
string to_string(priority_queue<A> heap) {
  bool first = true;
  string res = "{";
  while ((int) heap.size()) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(heap.top());
    heap.pop();
  }
  res += "}";
  return res;
}

template <typename A>
string to_string(priority_queue<A, vector<A>, greater<A> > heap) {
  bool first = true;
  string res = "{";
  while ((int) heap.size()) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(heap.top());
    heap.pop();
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

template <typename ... Ts>
string to_string(const Ts& ... ts) {
  stringstream ss;
  const char* sep = "";
  ((static_cast<void>(ss << sep << ts), sep = ", "), ...);
  return ss.str();
}

template <typename... Args>
string to_string(const std::tuple<Args...> &t) {
  string res = "(";
  apply([&](const auto&... ts) { res += to_string(ts...); }, t);
  res += ")";
  return res;
}

void debug_out() { cout << '\n'; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cout << " " << to_string(H); debug_out(T...); }

#ifdef LOCAL
#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 100010, M = 1010;

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

template <typename A>
class Lca {
 public:
  int n, root, lg;
  vector<int> depth;
  vector<vector<int>> fa;
  vector<vector<int>> mx;

  Lca(const vector<vector<pair<int, A>>> &g, int root) {
    n = static_cast<int>(g.size());
    lg = 32 - __builtin_clz(n);
    fa.resize(n);
    mx.resize(n);
    depth.resize(n);
    for (int i = 0; i < n; i++) {
      fa[i].resize(lg);
      mx[i].resize(lg);
    }
    depth[root] = 0;
    fa[root][0] = root;
    const int INF = 0x3f3f3f3f;
    mx[root][0] = -INF;
    vector<int> q;
    q.push_back(root);
    for (int qq = 0; qq < (int) q.size(); qq++) {
      int u = q[qq];
      for (int i = 1; i < lg; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        mx[u][i] = max(mx[u][i - 1], mx[fa[u][i - 1]][i - 1]);
      }
      for (auto &[v, w] : g[u]) {
        if (v == fa[u][0]) {
          continue;
        }
        depth[v] = depth[u] + 1;
        fa[v][0] = u;
        mx[v][0] = w;
        q.push_back(v);
      }
    }
  }
  int getLca(int a, int b) const {
    assert(a >= 0 && a < n && b >= 0 && b < n);
    if (depth[a] < depth[b]) {
      swap(a, b);
    }
    for (int k = lg - 1; k >= 0; k--) {
      if (depth[fa[a][k]] >= depth[b]) {
        a = fa[a][k];
      }
    }
    if (a == b) {
      return a;
    }
    for (int k = lg - 1; k >= 0; k--) {
      if (fa[a][k] != fa[b][k]) {
        a = fa[a][k];
        b = fa[b][k];
      }
    }
    return fa[a][0];
  }
  A getDist(int a, int b) const {
    assert(a >= 0 && a < n && b >= 0 && b < n);
    int anc = getLca(a, b);
    int res = 0;
    int ans = 0;
    for (int i = 0; i < lg; i++) {
      if (((depth[a] - depth[anc]) >> i) & 1) {
        res = max(res, mx[a][i]);
        a = fa[a][i];
      }
    }
    for (int i = 0; i < lg; i++) {
      if (((depth[b] - depth[anc]) >> i) & 1) {
        ans = max(ans, mx[b][i]);
        b = fa[b][i];
      }
    }
    return max(res, ans);
  }
};

// read the question carefully!!!
int main() {
  SOS(10);

  int n, m, q;
  cin >> n >> m >> q;
  VI a(m), b(m), c(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i] >> c[i];
    --a[i];
    --b[i];
  }
  VI order(m);
  iota(ALL(order), 0);
  sort(ALL(order), [&](int i, int j) { return c[i] < c[j]; });
  Dsu d(n);
  VE<VPII> g(n);
  for (auto &i : order) {
    if (d.get(a[i]) != d.get(b[i])) {
      d.unite(a[i], b[i]);
      g[a[i]].EB(b[i], c[i]);
      g[b[i]].EB(a[i], c[i]);
    }
  }
  Lca<int> lca(g, 0);
  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;
    cout << ((c < lca.getDist(a, b)) ? "Yes\n" : "No\n");
  }
  debug("hh");
  return 0;
}

// GOOD LUCK!!!
