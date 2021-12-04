/**
 * Author: Daniel
 * Created Time: 2021-11-04 15:19:00
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc219/tasks/abc219_e
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

// read the question carefully!!!
int main()
{
    SOS;

    int n = 4;
    VE<VI> g(n, VI(n));
    for (auto &u : g) {
      for (auto &v : u) {
        cin >> v;
      }
    }
    int res = 0;
    for (int mask = 0; mask < 1 << 16; ++mask) {
      VE<VI> a(n, VI(n, 0));
      bool flag = true;
      for (int bit = 0; bit < 16; ++bit) {
        int x = bit / 4, y = bit % 4;
        if ((mask >> bit) & 1) {
          a[x][y] = 1;
        }
        if (g[x][y] == 1 && a[x][y] == 0) {
          flag = false;
        }
      }
      if (!flag) {
        continue;
      }
      VE<VB> st(n, VB(n, false));
      const int dx[4] = {0, 0, 1, -1};
      const int dy[4] = {1, -1, 0, 0};
      Dsu d(17);
      function<void(int, int)> bfs = [&](int x, int y) -> void {
        VPII q;
        q.EB(x, y);
        for (int qq = 0; qq < SZ(q); ++qq) {
          auto [x, y] = q[qq];
          st[x][y] = true;
          for (int i = 0; i < 4; ++i) {
            int tx = dx[i] + x;
            int ty = dy[i] + y;
            if (tx < 0 || ty < 0 || tx >= n || ty >= n) {
              continue;
            }
            if (st[tx][ty] || a[tx][ty] != a[x][y]) {
              continue;
            }
            d.unite(tx * n + ty, x * n + y);
            q.EB(tx, ty);
          }
        }
      };
      int one = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (!st[i][j]) {
            bfs(i, j);
            if (a[i][j] == 1) {
              ++one;
            }
          }
        }
      }
      if (one != 1) {
        continue;
      }
      for (int i = 0; i < n; ++i) {
        if (a[i][0] == 0) {
          d.unite(i * n, 16);
        }
        if (a[i][n - 1] == 0) {
          d.unite(i * n + n - 1, 16);
        }
        if (a[n - 1][i] == 0) {
          d.unite((n - 1) * n + i, 16);
        }
        if (a[0][i] == 0) {
          d.unite(i, 16);
        }
      }
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (a[i][j] == 0 && d.get(i * n + j) != 16) {
            flag = false;
          }
        }
      }
      if (flag) {
        ++res;
      }
    }
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
