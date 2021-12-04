/**
 * Author: Daniel
 * Created Time: 2021-11-12 15:48:17
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
const int N = 10, M = 1010;

int g[N][N];
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

bool check(int x, int y) {
  return (x >= 1 && x <= 8 && y >= 1 && y <= 8);
}

int getAcc(int x, int y) {
  int res = 0;
  for (int i = 0; i < 8; i++) {
    int tx = dx[i] + x;
    int ty = dy[i] + y;
    res += (int) (check(tx, ty) && !g[tx][ty]);
  }
  return res;
}

bool dfs(int cnt, int x, int y) {
  g[x][y] = cnt;
  if (cnt == 64) {
    return true;
  }
  VE<TIII> cand;
  for (int i = 0; i < 8; i++) {
    int tx = dx[i] + x;
    int ty = dy[i] + y;
    if (check(tx, ty) && !g[tx][ty]) {
      cand.EB(MT(getAcc(tx, ty), tx, ty));
    }
  }
  sort(ALL(cand));
  for (auto &[acc, tx, ty] : cand) {
    if (dfs(cnt + 1, tx, ty)) {
      return true;
    }
  }
  g[x][y] = 0;
  return false;
}

// read the question carefully!!!
int main() {
  SOS;

  int x, y;
  cin >> y >> x;
  dfs(1, x, y);
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      cout << g[i][j] << " \n"[j == 8];
    }
  }
  return 0;
}

// GOOD LUCK!!!
