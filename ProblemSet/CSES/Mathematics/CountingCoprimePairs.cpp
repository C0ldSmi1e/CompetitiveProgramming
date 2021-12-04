/**
 * Author: Daniel
 * Created Time: 2021-11-18 17:49:16
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
const int N = 1000010, M = 1010;

vector<int> primes;
int minp[N];
int cnt[N];
bool st[N];

void init(int n) {
  st[1] = true;
  for (int i = 2; i <= n; i++) {
    if (!st[i]) {
      minp[i] = i;
      primes.emplace_back(i);
    }
    for (int j = 0; primes[j] <= n / i; j++) {
      int t = primes[j] * i;
      st[t] = true;
      minp[t] = primes[j];
      if (i % primes[j] == 0) {
        break;
      }
    }
  }
}

// read the question carefully!!!
int main() {
  SOS;

  init(N - 1);
  int n;
  cin >> n;
  VI a(n);
  for (auto &u : a) {
    cin >> u;
  }
  LL res = (LL) n * (n - 1) / 2;
  for (auto &u : a) {
    int x = u;
    VI fac;
    while (x > 1) {
      int p = minp[x];
      fac.EB(p);
      while (x % p == 0) {
        x /= p;
      }
    }
    int k = SZ(fac);
    for (int mask = 1; mask < 1 << k; mask++) {
      int s = 1;
      for (int bit = 0; bit < k; bit++) {
        if ((mask >> bit) & 1) {
          s *= fac[bit];
        }
      }
      int sign = ((__builtin_popcount(mask) & 1) ? 1 : -1);
      res -= cnt[s] * sign;
      cnt[s]++;
    }
  }
  cout << res << '\n';
  return 0;
}

// GOOD LUCK!!!
