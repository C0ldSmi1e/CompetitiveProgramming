/**
 * Author: Daniel
 * Created Time: 2021-11-29 22:29:51
**/

// time-limit: 4000
// problem-url: https://codeforces.com/contest/1614/problem/D2
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
const int N = 20000010, M = 1010;



// read the question carefully!!!
int main() {
  SOS;

  VI primes;
  VB st(N, false);
  for (int i = 2; i < N; i++) {
    if (!st[i]) {
      primes.EB(i);
    }
    for (int j = 0; primes[j] <= (N - 1) / i; j++) {
      st[primes[j] * i] = true;
      if (i % primes[j] == 0) {
        break;
      }
    }
  }
  int n;
  cin >> n;
  VL cnt(N);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x] += 1;
  }
  for (auto &p : primes) {
    for (int i = (N - 1) / p; i >= 1; i--) {
      cnt[i] += cnt[i * p];
    }
  }
  VL f(N);
  f[1] = cnt[1];
  for (int i = 1; i < N; i++) {
    for (auto &p : primes) {
      if (p <= (N - 1) / i) {
        f[i * p] = max(f[i * p], f[i] + (i * p - i) * cnt[i * p]);
      } else {
        break;
      }
    }
  }
  cout << MAX(ALL(f)) << '\n';
  return 0;
}

// GOOD LUCK!!!
