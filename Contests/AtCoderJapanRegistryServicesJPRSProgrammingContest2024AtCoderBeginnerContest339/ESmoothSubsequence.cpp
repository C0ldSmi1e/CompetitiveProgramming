/**
 * Author: C0ldSmi1e
 * Created Time: 02/05/2024 10:52:25 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc339/tasks/abc339_e
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

#ifndef lowbit
#define lowbit(x) (x & (-x))
#endif

// usage:
//   auto Fun = [&](int i, int j) { return min(i, j); };
//   Fenwick<int, decltype(Fun)> fenw(a, Fun);
// or:
//   Fenwick<int> fenw(a, [&](int i, int j) { return min(i, j); });
template <typename T, class F = function<T(const T&, const T&)>>
class Fenwick {
 public:
  int n;
  vector<T> val, fenw;
  F Func;
  Fenwick (const vector<T>& a, const F& f) : Func(f) {
    n = static_cast<int>(a.size());
    Init(a);
  }
  Fenwick(const int _n, const F& f) : Func(f) {
    n = _n;
    vector<T> a(_n);
    Init(a);
  }
  void Init(const vector<T>& a) {
    val.resize(n);
    fenw.resize(n);
    for (int i = 1; i <= n; i++) {
      val[i - 1] = fenw[i - 1] = a[i - 1];
      int len = lowbit(i);
      for (int j = 1; j < len; j <<= 1) {
        fenw[i - 1] = Func(fenw[i - 1], fenw[i - j - 1]);
      }
    }
  }
  // change value at k to v
  // k is [0, n)
  inline void Modify(int k, T v) {
    assert(k >= 0 && k < n);
    val[k] = v;
    for (int i = k + 1; i <= n; i += lowbit(i)) {
      fenw[i - 1] = val[i - 1];
      int len = lowbit(i);
      for (int j = 1; j < len; j <<= 1) {
        fenw[i - 1] = Func(fenw[i - 1], fenw[i - j - 1]);
      }
    }
  }
  // l and r are [0, n)
  // ask for [l, r]
  inline T Query(int l, int r) {
    assert(l >= 0 && l < n);
    assert(r >= 0 && r < n);
    ++l, ++r;
    T res = val[r - 1];
    while (true) {
      res = Func(res, val[r - 1]);
      if (l == r) break;
      for (--r; r - lowbit(r) >= l; r -= lowbit(r)) {
        res = Func(res, fenw[r - 1]);
      }
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (auto& u : a) {
    cin >> u;
  }
  auto all = a;
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  int m = (int) all.size();
  Fenwick<int> fenw(m, [&](int i, int j) { return max(i, j); });
  vector<int> dp(n);
  for (int i = 0; i < n; i++) {
    int l = (int) (lower_bound(all.begin(), all.end(), a[i] - d) - all.begin());
    int r = min(m - 1, (int) (upper_bound(all.begin(), all.end(), a[i] + d) - all.begin()) - 1);
    dp[i] = fenw.Query(l, r) + 1;
    fenw.Modify((int) (lower_bound(all.begin(), all.end(), a[i]) - all.begin()), dp[i]);
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';
  return 0;
}
