/**
 * Author: Daniel
 * Created Time: 2021-10-27 16:01:29
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

// Find a negative cycle in a directed weighted gragh.
// n is the number of vertices.
template <typename A>
vector<int> FindCycle(int n, const vector<tuple<int, int, A> > &edge) {
  vector<A> dist(n);
  vector<int> parent(n, -1);
  int cycleStart = -1;
  for (int i = 0; i < n; i++) {
    cycleStart = -1;
    for (auto &[u, v, w] : edge) {
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        parent[v] = u;
        cycleStart = v;
      }
    }
  }
  vector<int> cycle;
  if (cycleStart != -1) {
    for (int i = 0; i < n; i++) {
      cycleStart = parent[cycleStart];
    }
    for (int i = cycleStart; ; i = parent[i]) {
      cycle.push_back(i);
      if (i == cycleStart && (int) cycle.size() > 1) {
        break;
      }
    }
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
    VE<tuple<int, int, LL>> edge(m);
    for (auto &[x, y, z] : edge)
    {
        cin >> x >> y >> z;
        x -- , y -- ;
    }
    auto cycle = FindCycle(n, edge);
    if (SZ(cycle) == 0) cout << "NO\n";
    else
    {
        cout << "YES\n";
        for (auto &u : cycle)
            cout << u + 1 << ' ';
        cout << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
