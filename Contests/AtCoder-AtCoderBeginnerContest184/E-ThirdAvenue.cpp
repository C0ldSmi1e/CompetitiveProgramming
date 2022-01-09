/**
 * Author: Daniel
 * Created Time: 2022-01-06 14:51:35
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



// read the question carefully!!!
int main() {
  SOS(10);

  int n, m;
  cin >> n >> m;
  VS g(n);
  for (auto &s : g) {
    cin >> s;
  }
  int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
  VE<VPII> cand(26);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == 'S') {
        x1 = i;
        y1 = j;
      }
      if (g[i][j] == 'G') {
        x2 = i;
        y2 = j;
      }
      if (g[i][j] >= 'a' && g[i][j] <= 'z') {
        cand[g[i][j] - 'a'].EB(i, j);
      }
    }
  }
  assert(x1 != -1 && y1 != -1 && x2 != -1 && y2 != -1);
  const int INF = 0x3f3f3f3f;
  VE<VI> dist(n, VI(m, INF));
  RHEAP<TIII> heap;
  dist[x1][y1] = 0;
  VB st(26, false);
  heap.push(MT(0, x1, y1));
  const int dx[4] = {0, 1, 0, -1};
  const int dy[4] = {1, 0, -1, 0};
  while (SZ(heap) > 0) {
    auto [d, x, y] = heap.top();
    heap.pop();
    for (int i = 0; i < 4; i++) {
      int tx = dx[i] + x;
      int ty = dy[i] + y;
      if (tx < 0 || ty < 0 || tx >= n || ty >= m) {
        continue;
      }
      if (g[tx][ty] == '#') {
        continue;
      }
      if (dist[x][y] + 1 < dist[tx][ty]) {
        dist[tx][ty] = dist[x][y] + 1;
        heap.push(MT(dist[x][y] + 1, tx, ty));
      }
    }
    if (g[x][y] >= 'a' && g[x][y] <= 'z' && !st[g[x][y] - 'a']) {
      st[g[x][y] - 'a'] = true;
      for (auto &[tx, ty] : cand[g[x][y] - 'a']) {
        if (dist[x][y] + 1 < dist[tx][ty]) {
          dist[tx][ty] = dist[x][y] + 1;
          heap.push(MT(dist[x][y] + 1, tx, ty));
        }
      }
    }
  }
  cout << (dist[x2][y2] != INF ? dist[x2][y2] : -1) << '\n';
  return 0;
}

// GOOD LUCK!!!
