/**
 * Author: Daniel
 * Created Time: 2021-06-24 10:09:07
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

/*
 * hash seed:
 * 131, 13331, 146527, 19260817, 378551
 * 63689, 1315423911, 5381, 65599, 131313
 * mod:
 * 1000000007, 1000000009, 998244353
*/

#define STRING_HASH_MOD

class StringHash {
 public:
  int n;
  unsigned long long seed, mod;
  vector<unsigned long long> p, h;
 
  StringHash(const string &s, unsigned long long _seed = 13331, unsigned long long _mod = 998244353) : seed(_seed), mod(_mod) {
    n = static_cast<int>(s.size());
    p.resize(n + 1);
    h.resize(n + 1);
    p[0] = 1;
    for (int i = 0; i < n; i++) {
#ifdef STRING_HASH_MOD
      p[i + 1] = p[i] * seed % mod;
      h[i + 1] = (h[i] * seed + s[i]) % mod;
#else
      p[i + 1] = p[i] * seed;
      h[i + 1] = h[i] * seed + s[i];
#endif
    }
  }
  // return hash code [l, r)
  inline unsigned long long get(int l, int r) {
    assert(l >= 0 && r <= n && l <= r);
#ifdef STRING_HASH_MOD
    return (h[r] - h[l] * p[r - l] % mod + mod) % mod;
#else
    return h[r] - h[l] * p[r - l];
#endif
  }
};

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 100010, M = 1010;



// read the question carefully!!!
int main()
{
    SOS;

    string s;
    cin >> s;
    int n = SZ(s);
    StringHash sh(s);
    for (int i = 1; i < n; i ++ )
        if (sh.get(0, i) == sh.get(n - i, n))
            cout << i << ' ';
    cout << '\n';
    return 0;
}

// GOOD LUCK!!!
