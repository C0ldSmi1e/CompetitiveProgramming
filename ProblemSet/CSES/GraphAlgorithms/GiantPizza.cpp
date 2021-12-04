/**
 * Author: Daniel
 * Created Time: 2021-11-10 18:11:17
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

class TwoSat {
 public:
  // i is in [0, n - 1]
  // 2 * i indicates (i == 0)
  // 2 * i + 1 indicates (i == 1)
  int n;
  vector<vector<int>> g;

  TwoSat(int _n) : n(_n), g(vector<vector<int>>(2 * _n)) {}

  inline void add(int x, int valX) {
    // (v[x] == valX)
    assert(x >= 0 && x < n);
    assert(valX >= 0 && valX <= 1);
    g[2 * x + (valX ^ 1)].emplace_back(2 * x + valX);
  }

  inline void add(int x, int valX, int y, int valY) {
    // (v[x] == valX || v[y] == valY)
    assert(x >= 0 && x < n && y >= 0 && y < n);
    assert(valX >= 0 && valX <= 1 && valY >= 0 && valY <= 1);
    g[2 * x + (valX ^ 1)].emplace_back(2 * y + valY);
    g[2 * y + (valY ^ 1)].emplace_back(2 * x + valX);
  }

  vector<int> findSCC(int &id) {
    int top = 0, n = (int) g.size();
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

  inline vector<int> get() {
    // if there is no answer, then return a void vector
    int cnt = 0;
    vector<int> comp = findSCC(cnt);
    assert((int) comp.size() == 2 * n);
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      if (comp[2 * i] == comp[2 * i + 1]) {
        return vector<int>();
      }
      res[i] = (((int) (comp[2 * i] < comp[2 * i + 1])) ^ 1);
    }
    return res;
  }
};

// read the question carefully!!!
int main() {
  SOS;

  int n, m;
  cin >> m >> n;
  TwoSat ts(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    char cx, cy;
    cin >> cx >> x >> cy >> y;
    x--, y--;
    int valX = (int) (cx == '+');
    int valY = (int) (cy == '+');
    ts.add(x, valX, y, valY);
  }
  auto res = ts.get();
  if (SZ(res) == 0) {
    cout << "IMPOSSIBLE\n";
  } else {
    for (auto &u : res) {
      cout << (u ? '+' : '-') << ' ';
    }
    cout << '\n';
  }
  return 0;
}

// GOOD LUCK!!!
