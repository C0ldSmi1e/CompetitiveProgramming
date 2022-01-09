/**
 * Author: Daniel
 * Created Time: 2022-01-04 21:51:25
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

template <typename A>
class Lca {
 public:
  int n, root, lg;
  vector<A> dist;
  vector<int> depth;
  vector<vector<int>> fa;

  Lca(const vector<vector<int>> &g, int root) {
    n = static_cast<int>(g.size());
    lg = 32 - __builtin_clz(n);
    fa.resize(n);
    dist.resize(n);
    depth.resize(n);
    for (int i = 0; i < n; i++) {
      fa[i].resize(lg);
    }
    depth[root] = 0;
    fa[root][0] = root;
    vector<int> q;
    q.push_back(root);
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
  SOS(10);

  int n, q;
  cin >> n >> q;
  VE<VI> g(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].EB(b);
    g[b].EB(a);
  }
  Lca<int> lca(g, 0);
  while (q--) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    int dist = lca.getDist(a, b);
    cout << (dist % 2 == 0 ? "Town\n" : "Road\n");
  }
  return 0;
}

// GOOD LUCK!!!
