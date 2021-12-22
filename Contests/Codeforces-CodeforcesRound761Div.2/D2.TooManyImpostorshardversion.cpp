/**
 * Author: Daniel
 * Created Time: 2021-12-17 15:13:40
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1617/problem/D2
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

  auto ask = [&](int a, int b, int c) -> int {
    cout << "? " << a << ' ' << b << ' ' << c << endl;
    cin >> a;
    return a;
  };
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    VI p(n + 1, -1);
    for (int i = 1; i <= n; i += 3) {
      p[i] = ask(i, i + 1, i + 2);
    }
    VI role(n + 1, -1);
    int xx = -1, yy = -1;
    // xx is impostor, yy is crewmate
    for (int i = 1; i + 3 <= n; i += 3) {
      assert(p[i] != -1);
      assert(p[i + 3] != -1);
      if (p[i] != p[i + 3]) {
        p[i + 1] = ask(i + 1, i + 2, i + 3);
        p[i + 2] = ask(i + 2, i + 3, i + 4);
        for (int j = i; j <= i + 2; j++) {
          if (p[j] != p[j + 1]) {
            if (p[j] == 1) {
              xx = j + 3;
              yy = j;
            } else {
              xx = j;
              yy = j + 3;
            }
          }
        }
        break;
      }
    }
    assert(xx != -1 && yy != -1);
    role[xx] = 0;
    role[yy] = 1;
    for (int i = 1; i <= n; i += 3) {
      if (i == xx || i + 1 == xx || i + 2 == xx || i == yy || i + 1 == yy || i + 2 == yy) {
        for (int j = i; j <= i + 2; j++) {
          if (role[j] == -1) {
            role[j] = ask(xx, yy, j);
          }
        }
        continue;
      }
      assert(p[i] != -1);
      if (p[i] == 1) {
        if (ask(xx, i, i + 1) == 1) {
          role[i] = role[i + 1] = 1;
          role[i + 2] = ask(xx, yy, i + 2);
        } else {
          role[i] = ask(xx, yy, i);
          role[i + 1] = 1 - role[i];
          role[i + 2] = 1;
        }
      } else {
        if (ask(yy, i, i + 1) == 0) {
          role[i] = role[i + 1] = 0;
          role[i + 2] = ask(xx, yy, i + 2);
        } else {
          role[i] = ask(xx, yy, i);
          role[i + 1] = 1 - role[i];
          role[i + 2] = 0;
        }
      }
    }
    VI res;
    for (int i = 1; i <= n; i++) {
      assert(role[i] != -1);
      if (role[i] == 0) {
        res.EB(i);
      }
    }
    assert(n / 3 < SZ(res));
    assert((n / 3) * 2 > SZ(res));
    cout << "! " << SZ(res);
    for (auto &u : res) {
      cout << ' ' << u;
    }
    cout << endl;
  }
  return 0;
}

// GOOD LUCK!!!
