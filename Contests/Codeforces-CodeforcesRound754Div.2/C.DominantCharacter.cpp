/**
 * Author: Daniel
 * Created Time: 2021-11-13 16:23:30
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1605/problem/C
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



// read the question carefully!!!
int main() {
  SOS;

  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    VI a(n + 1), b(n + 1), c(n + 1);
    for (int i = 0; i < n; i++) {
      a[i + 1] = a[i] + (int) (s[i] == 'a');
      b[i + 1] = b[i] + (int) (s[i] == 'b');
      c[i + 1] = c[i] + (int) (s[i] == 'c');
    }
    int res = -1;
    for (int len = 2; len <= 7; len++) {
      for (int r = 1; r <= n; r++) {
        int l = r - len + 1;
        if (l < 1) {
          continue;
        }
        if (a[r] - a[l - 1] > b[r] - b[l - 1] && a[r] - a[l - 1] > c[r] - c[l - 1]) {
          res = len;
        }
      }
      if (res != -1) {
        break;
      }
    }
    cout << res << '\n';
  }
  return 0;
}

// GOOD LUCK!!!
