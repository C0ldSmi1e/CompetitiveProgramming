/**
 * Author: Daniel
 * Created Time: 2021-12-22 17:44:38
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1619/problem/C
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
#define CNT(x, y) ((int)count(x.begin(),x.end(), y))
#define SOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10)

typedef long long LL;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef long double LD;
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
    string b, s;
    cin >> b >> s;
    int n = SZ(b), m = SZ(s);
    string res;
    bool flag = true;
    int j = m - 1;
    for (int i = n - 1; flag && i >= 0; i--) {
      if (b[i] <= s[j]) {
        res += char(s[j] - b[i] + '0');
        j--;
      } else {
        if (j - 1 >= 0) {
          int x = (int) (b[i] - '0');
          int y = (int) (s[j - 1] - '0') * 10 + (int) (s[j] - '0');
          if (y - x < 0 || y - x >= 10) {
            flag = false;
            break;
          }
          res += char(y - x + '0');
          j -= 2;
        } else {
          flag = false;
          break;
        }
      }
    }
    while (j >= 0) {
      res += s[j];
      j--;
    }
    if (flag) {
      while (SZ(res) > 1 && res.back() == '0') {
        res.PB();
      }
      reverse(ALL(res));
      cout << res << '\n';
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}

// GOOD LUCK!!!
