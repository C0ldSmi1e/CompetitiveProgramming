/**
 * Author: Daniel
 * Created Time: 2021-10-30 11:58:53
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

vector<int> FindSCC(const vector<vector<int>> &g, int &id) {
  int n = static_cast<int>(g.size());
  int top = 0;
  vector<int> comp(n, -1), in(n, -1), out(n, -1), stk(n + 1, -1), order;
  function<int(int u)> tarjan = [&](int u) -> int {
    assert(top >= 0 && top <= n);
    stk[top++] = u;
    int low = in[u] = (int) order.size();
    order.push_back(u);
    for (auto &v : g[u]) {
      if (in[v] == -1) {
        low = min(low, tarjan(v));
        continue;
      }
      if (comp[v] == -1) {
        low = min(low, in[v]);
      }
    }
    if (low == in[u]) {
      while (stk[top] != u) {
        assert(top >= 0 && top <= n);
        comp[stk[--top]] = id;
      }
      id++;
    }
    out[u] = (int) order.size() - 1;
    return low;
  };
  for (int i = 0; i < n; i++) {
    if (in[i] == -1) {
      tarjan(i);
    }
  }
  return comp;
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
    }
    int id = 0;
    auto comp = FindSCC(g, id);
    if (id == 1) cout << "YES\n";
    else
    {
        cout << "NO\n";
        int x = -1, y = -1;
        for (int i = 0; i < n; i ++ )
        {
            if (comp[i] == 0) x = i;
            if (comp[i] == 1) y = i;
        }
        assert(x != -1 && y != -1);
        if ((int) count(ALL(g[x]), y) != 0) swap(x, y);
        cout << x + 1 << ' ' << y + 1 << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
