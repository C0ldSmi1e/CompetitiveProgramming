/**
 * Author: C0ldSmi1e
 * Created Time: 03/06/2024 08:02:22 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc342/tasks/abc342_f
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

template <typename T>
class Fenwick {
 public:
  vector<T> fenw;
  int n;
  Fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }
  inline void Add(int x, T v) {
    assert(x >= 0 && x < n);
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
  inline T Get(int x) {
    T res{};
    while (x >= 0) {
      res += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return res;
  }
  inline T Get(int l, int r) {
    assert(l >= 0 && l < n && r >= 0 && r < n);
    T res = Get(r);
    if (l - 1 >= 0) {
      res -= Get(l - 1);
    }
    return res;
  }
  inline int KthMin(int k) {
    // KthMax = n - KthMin + 1
    assert(k >= 1 && k <= n);
    int cnt = 0, x = 0;
    for (int i = (int) log2(n); i >= 0; i--) {
      x += (1 << i);
      if (x >= n || cnt + fenw[x - 1] >= k) {
        x -= (1 << i);
      } else {
        cnt += fenw[x - 1];
      }
    }
    return x;
  }
};

// struct Node {
//   int a = ...; // don't forget to set default value
//   inline void operator += (Node& other) {
//     ...
//   }
// };

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n, l, d;
  cin >> n >> l >> d;
  vector<double> py(2 * n + 10);
  py[0] = 1.0;
  py[1] = -1.0;
  for (int i = 0; i <= 2 * n; i++) {
    if (i < l) {
      py[i + 1] += py[i] / d;
      py[i + d + 1] -= py[i] / d;
    }
    py[i + 1] += py[i];
  }
  Fenwick<double> fenw_y(2 * n + 10);
  for (int i = 0; i <= 2 * n; i++) {
    fenw_y.Add(i, py[i]);
  }
  Fenwick<double> fenw_x(2 * n + 10);
  for (int i = 1; i <= n; i++) {
    double tot = fenw_y.Get(n + 1, 2 * n);
    if (i > l) {
      tot += fenw_y.Get(l, i - 1);
    }
    fenw_x.Add(i, tot);
  }
  Fenwick<double> fenw_dp(2 * n + 10);
  for (int i = n; i >= 0; i--) {
    fenw_dp.Add(i, max(fenw_x.Get(i, i), fenw_dp.Get(i + 1, i + d) / d));
  }
  cout << fenw_dp.Get(0, 0) << '\n';
  return 0;
}
