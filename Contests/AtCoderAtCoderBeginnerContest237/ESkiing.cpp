/**
 * Author: Daniel
 * Created Time: 2022-02-04 16:15:15
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc237/tasks/abc237_e
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

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 100010, M = 1010;

template <typename A, typename B>
vector<A> Dijkstra(const vector<vector<pair<int, B> > > &g, int start, const A &INF) {
  int n = static_cast<int>(g.size());
  assert(start >= 0 && start < n);
  vector<A> dist(n, INF);
  dist[start] = 0;
  priority_queue<pair<A, int>, vector<pair<A, int> >, greater<pair<A, int> > > heap;
  heap.emplace(dist[start], start);
  while ((int) heap.size() > 0) {
    auto [d, u] = heap.top();
    heap.pop();
    if (dist[u] != d) {
      continue;
    }
    for (auto &[v, w] : g[u]) {
      if (dist[v] > w + dist[u]) {
        dist[v] = w + dist[u];
        heap.emplace(dist[v], v);
      }
    }
  }
  // returns INF if there's no path
  return dist;
}

// read the question carefully!!!
int main() {
  SOS(10);

  int n, m;
  cin >> n >> m;
  VI h(n);
  for (auto &u : h) {
    cin >> u;
  }
  VE<VPII> g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].EB(b, max(0, h[b] - h[a]));
    g[b].EB(a, max(0, h[a] - h[b]));
  }
  const LL INF = (LL) 2e18;
  auto dist = Dijkstra(g, 0, INF);
  LL res = -INF;
  for (int i = 0; i < n; i++) {
    res = max(res, h[0] - h[i] - dist[i]);
  }
  cout << res << '\n';
  return 0;
}

// GOOD LUCK!!!
