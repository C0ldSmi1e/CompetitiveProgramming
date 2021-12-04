/**
 * Author: Daniel
 * Created Time: 2021-10-27 15:58:51
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

// Find a cycle in a undirected graph without loops and multiple edges.
vector<int> FindCycle(vector<vector<int>> &g) {
  int n = static_cast<int>(g.size());
  vector<bool> visited(n, false);
  vector<int> parent(n, -1);
  int cycleStart = -1, cycleEnd = -1;
  function<bool(int, int)> dfs = [&](int u, int fa) -> bool {
    visited[u] = true;
    for (auto &v : g[u]) {
      if (v == fa) {
        continue;
      }
      if (visited[v]) {
        cycleStart = v;
        cycleEnd = u;
        return true;
      }
      parent[v] = u;
      if (dfs(v, parent[v])) {
        return true;
      }
    }
    return false;
  };
  for (int i = 0; i < n; i++) {
    if (visited[i] == false && dfs(i, parent[i])) {
      break;
    }
  }
  vector<int> cycle;
  if (cycleStart != -1) {
    cycle.push_back(cycleStart);
    for (int i = cycleEnd; i != cycleStart; i = parent[i]) {
      cycle.push_back(i);
    }
    cycle.push_back(cycleStart);
    reverse(cycle.begin(), cycle.end());
  }
  return cycle;
}

// read the question carefully!!!
int main()
{
    SOS;

    int n, m;
    cin >> n >> m;
    VE<VI> g(n);
    for (int i = 0; i < m; i ++ )
    {
        int a, b;
        cin >> a >> b;
        a -- , b -- ;
        g[a].EB(b);
        g[b].EB(a);
    }
    auto cycle = FindCycle(g);
    if (SZ(cycle) == 0) cout << "IMPOSSIBLE\n";
    else
    {
        cout << SZ(cycle) << '\n';
        for (auto &u : cycle)
            cout << u + 1 << ' ';
        cout << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
