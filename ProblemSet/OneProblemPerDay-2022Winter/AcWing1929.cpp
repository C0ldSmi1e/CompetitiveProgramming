/**
 * Author: Daniel
 * Created Time: 2022-01-18 12:04:53
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

int n, m;
VS g;
int res;

void dfs(int x, int y, int dir, int steps) {
  res = max(res, steps);
  int tx = -1, ty = -1, td = -1;
  if (dir == 0) {
    // L
    if (g[x][y] == '\\') {
      tx = x - 1, ty = y, td = 2;
    }
    if (g[x][y] == '/') {
      tx = x + 1, ty = y, td = 3;
    }
  }
  if (dir == 1) {
    // R
    if (g[x][y] == '\\') {
      tx = x + 1, ty = y, td = 3;
    }
    if (g[x][y] == '/') {
      tx = x - 1, ty = y, td = 2;
    }
  }
  if (dir == 2) {
    // U
    if (g[x][y] == '\\') {
      tx = x, ty = y - 1, td = 0;
    }
    if (g[x][y] == '/') {
      tx = x, ty = y + 1, td = 1;
    }
  }
  if (dir == 3) {
    // D
    if (g[x][y] == '\\') {
      tx = x, ty = y + 1, td = 1;
    }
    if (g[x][y] == '/') {
      tx = x, ty = y - 1, td = 0;
    }
  }
  if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
    dfs(tx, ty, td, steps + 1);
  }
}

// read the question carefully!!!
int main() {
  SOS(10);

  cin >> n >> m;
  g.resize(n);
  for (auto &s : g) {
    cin >> s;
  }
//  int res = 0;
  for (int i = 0; i < n; i++) {
    dfs(i, 0, 1, 1);
    dfs(i, m - 1, 0, 1);
  }
  for (int j = 0; j < m; j++) {
    dfs(0, j, 3, 1);
    dfs(n - 1, j, 2, 1);
  }
  cout << res << '\n';
  return 0;
}

// GOOD LUCK!!!
