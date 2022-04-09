/**
 * Author: Daniel
 * Created Time: 2022-03-19 11:41:47
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1651/problem/C
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



// read the question carefully!!!
int main() {
  SOS(10);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    VL a(n);
    set<LL> Sa;
    for (auto &u : a) {
      cin >> u;
      Sa.IS(u);
    }
    VL b(n);
    set<LL> Sb;
    for (auto &u : b) {
      cin >> u;
      Sb.IS(u);
    }
    const LL INF = (LL) 4e18;
    LL al = INF;
    auto it = Sb.LB(a[0]);
    if (it != Sb.end()) {
      al = min(al, abs(*it - a[0]));
    }
    if (it != Sb.begin()) {
      al = min(al, abs(*prev(it) - a[0]));
    }
    LL ar = INF;
    it = Sb.LB(a[n - 1]);
    if (it != Sb.end()) {
      ar = min(ar, abs(*it - a[n - 1]));
    }
    if (it != Sb.begin()) {
      ar = min(ar, abs(*prev(it) - a[n - 1]));
    }
    LL bl = INF;
    it = Sa.LB(b[0]);
    if (it != Sa.end()) {
      bl = min(bl, abs(*it - b[0]));
    }
    if (it != Sa.begin()) {
      bl = min(bl, abs(*prev(it) - b[0]));
    }
    LL br = INF;
    it = Sa.LB(b[n - 1]);
    if (it != Sa.end()) {
      br = min(br, abs(*it - b[n - 1]));
    }
    if (it != Sa.begin()) {
      br = min(br, abs(*prev(it) - b[n - 1]));
    }
    LL res = INF;
    res = min(res, abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]));
    res = min(res, abs(a[0] - b[0]) + ar + br);
    res = min(res, abs(a[n - 1] - b[n - 1]) + al + bl);
    res = min(res, al + bl + ar + br);
    res = min(res, abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]));
    res = min(res, abs(a[0] - b[n - 1]) + bl + ar);
    res = min(res, abs(a[n - 1] - b[0]) + br + al);
    cout << res << '\n';
  }
  return 0;
}

// GOOD LUCK!!!
