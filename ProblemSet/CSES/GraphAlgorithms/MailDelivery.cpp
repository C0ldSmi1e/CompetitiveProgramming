/**
 * Author: Daniel
 * Created Time: 2021-11-11 19:21:22
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

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 100010, M = 1010;

vector<pair<int, int>> FindEulerianPath(const vector<vector<int>> &g, const vector<pair<int, int>> edges, int &root) {
  int n = static_cast<int>(g.size());
  int m = static_cast<int>(edges.size());
  vector<int> din(n), dout(n);
  for (auto &[x, y] : edges) {
    dout[x]++, din[y]++;
  }
  root = -1;
  int odd = 0;
  for (int i = 0; i < n; i++) {
    if ((din[i] + dout[i]) & 1) {
      odd++;
      if (root == -1 || (dout[i] - din[i] > dout[root] - din[root])) {
        root = i;
      }
    }
  }
  if (odd > 2) {
    root = -1;
    return vector<pair<int, int>>();
  }
  if (root == -1) {
    root = 0;
    while (root < n && din[root] + dout[root] == 0) {
      root++;
    }
    if (root == n) {
      // return an empty path
      root = 0;
      return vector<pair<int, int>>();
    }
  }
  int stackPtr = 0, writePtr = m, v = root;
  vector<int> ptr(n, 0), balance(n, 0);
  vector<pair<int, int>> res(m);
  vector<bool> used(m, false);
  while (true) {
    bool found = false;
    while (ptr[v] < (int) g[v].size()) {
      int id = g[v][ptr[v]++];
      if (used[id]) {
        continue;
      }
      used[id] = true;
      balance[v]++;
      if (v == edges[id].second) {
        res[stackPtr++] = make_pair(id, -1);
      } else if (v == edges[id].first) {
        res[stackPtr++] = make_pair(id, 1);
      } else {
        assert(false);
      }
      v ^= edges[id].first ^ edges[id].second;
      balance[v]--;
      found = true;
      break;
    }
    if (!found) {
      if (stackPtr == 0) {
        break;
      }
      auto [id, dir] = res[--stackPtr];
      res[--writePtr] = make_pair(id, dir);
      v ^= edges[abs(id)].first ^ edges[abs(id)].second;
    }
  }
  int bad = 0;
  for (int i = 0; i < n; i++) {
    bad += abs(balance[i]);
  }
  if (writePtr != 0 || bad > 2) {
    root = -1;
    return vector<pair<int, int>>();
  }
  return res;
}

vector<int> GetVerPath(const vector<pair<int, int>> &edges, const vector<pair<int, int>> &ids) {
  int n = static_cast<int>(ids.size());
  if (n == 0) {
    return vector<int>();
  }
  vector<int> path(n + 1);
  path[0] = (ids[0].second > 0 ? edges[ids[0].first].first : edges[ids[0].first].second);
  for (int i = 0; i < n; i++) {
    if (ids[i].second > 0) {
      path[i + 1] = edges[ids[i].first].second;
    } else {
      path[i + 1] = edges[ids[i].first].first;
    }
  }
  return path;
}

// read the question carefully!!!
int main() {
  SOS;

  int n, m;
  cin >> n >> m;
  VPII edges(m);
  VE<VI> g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    edges[i] = MP(a, b);
    g[a].EB(i);
    g[b].EB(i);
  }
  int root = -1;
  auto ids = FindEulerianPath(g, edges, root);
  if (root == -1 || SZ(ids) != m) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  auto path = GetVerPath(edges, ids);
  if ((int) count(ALL(path), 0) == 0 || path[0] != path.back()) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  for (auto &u : path) {
    cout << u + 1 << ' ';
  }
  cout << '\n';
  return 0;
}

// GOOD LUCK!!!
