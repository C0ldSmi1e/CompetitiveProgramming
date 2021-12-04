/**
 * Author: Daniel
 * Created Time: 2021-11-13 14:45:31
**/

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
#define SOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10)

typedef long long LL;
typedef vector<LL> VL;
typedef vector<int> VI;
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

template <typename A> using VE = vector<A>;
template <typename A> using USET = unordered_set<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A, typename B> using UMAP = unordered_map<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;

template <typename A> A MAX(const A &a) { return a; }
template <typename A> A MIN(const A &a) { return a; }
template <typename A> A MAX(const A *a, const A *b) { return *max_element(a, b); }
template <typename A> A MIN(const A *a, const A *b) { return *min_element(a, b); }
template <typename A, typename... B> A MAX(const A &a, const B&... b) { return max(a, MAX(b...)); }
template <typename A, typename... B> A MIN(const A &a, const B&... b) { return min(a, MIN(b...)); }
template <typename A, typename B = typename std::iterator_traits<A>::value_type> B MAX(A a, A b) { return *max_element(a, b); }
template <typename A, typename B = typename std::iterator_traits<A>::value_type> B MIN(A a, A b) { return *min_element(a, b); }

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
  vector<A> dist;
  vector<int> depth;
  vector<vector<int> > fa;

  Lca(const vector<vector<int> > &g, VI &roots) {
    n = static_cast<int>(g.size());
    lg = 32 - __builtin_clz(n);
    fa.resize(n);
    dist.resize(n);
    depth.resize(n);
    for (int i = 0; i < n; i++) {
      fa[i].resize(lg);
    }
    vector<int> q;
    for (auto &root : roots) {
      depth[root] = 0;
      fa[root][0] = root;
      q.push_back(root);
    }
    for (int qq = 0; qq < (int) q.size(); qq++) {
      int u = q[qq];
      for (int i = 1; i < lg; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
      }
      for (auto &v : g[u]) {
        if (v == fa[u][0]) {
          continue;
        }
        depth[v] = depth[u] + 1;
        dist[v] = dist[u] + 1;
        fa[v][0] = u;
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
    return dist[a] + dist[b] - 2 * dist[anc];
  }
};

// read the question carefully!!!
int main() {
  SOS;

  int n, q;
  cin >> n >> q;
  Dsu d(n);
  VE<VI> g(n), rg(n);
  for (int i = 0; i < n; i++) {
    int j;
    cin >> j;
    j--;
    d.unite(i, j);
    g[i].EB(j);
    rg[j].EB(i);
  }
  // find roots and cycles formed by roots
  VB st(n), isRoot(n);
  VE<VI> cycle;
  VI roots;
  VPII at(n, MP(-1, -1));
  function<void(int, VI &)> dfs = [&](int u, VI &path) -> void {
    path.EB(u);
    if (st[u]) {
      return;
    }
    st[u] = true;
    for (auto &v : g[u]) {
      dfs(v, path);
    }
  };
  for (int i = 0; i < n; i++) {
    if (!st[i]) {
      VI path;
      dfs(i, path);
      reverse(ALL(path));
      while (SZ(path) > 0) {
        int v = path.back();
        if (v == path[0]) {
          path.PB();
          break;
        }
        path.PB();
      }
      if (SZ(path) > 0) {
        int id = SZ(cycle);
        cycle.EB(path);
        for (int i = 0; i < SZ(path); i++) {
          roots.EB(path[i]);
          isRoot[path[i]] = true;
          at[path[i]] = MP(id, i);
        }
      }
    }
  }
  VI depth(n), tr(n);
  function<void(int, int, int)> go = [&](int u, int root, int dep) {
    tr[u] = root;
    depth[u] = dep;
    for (auto &v : rg[u]) {
      if (!isRoot[v]) {
        go(v, root, dep + 1);
      }
    }
  };
  for (int i = 0; i < n; i++) {
    if (isRoot[i]) {
      go(i, i, 0);
    }
  }
  VE<VI> G(n);
  for (int u = 0; u < n; u++) {
    for (auto &v : rg[u]) {
      if (!isRoot[v]) {
        G[u].EB(v);
      }
    }
  }
  Lca<int> lca(G, roots);
  auto getCycleDist = [&](int x, int y) -> int {
    auto [idx, posx] = at[x];
    auto [idy, posy] = at[y];
    assert(idx == idy);
    int len = SZ(cycle[idx]);
    return (len + posx - posy) % len;
  };
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (d.get(x) != d.get(y)) {
      // not connected
      cout << "-1\n";
    } else if (isRoot[x] && isRoot[y]) {
      // both in a cycle
      cout << getCycleDist(x, y) << '\n';
    } else if (isRoot[x]) {
      // x in a cycle but y not
      cout << "-1\n";
    } else if (isRoot[y]) {
      // y in a cycle but x not
      cout << depth[x] + getCycleDist(tr[x], y) << '\n';
    } else if (tr[x] != tr[y]) {
      // x and y in different tree
      cout << "-1\n";
    } else if (tr[x] == tr[y]) {
      // x and y in a same tree
      int anc = lca.getLca(x, y);
      if (anc != y) {
        cout << "-1\n";
      } else {
        cout << depth[x] - depth[y] << '\n';
      }
    } else assert(false);
  }
  return 0;
}

// GOOD LUCK!!!
