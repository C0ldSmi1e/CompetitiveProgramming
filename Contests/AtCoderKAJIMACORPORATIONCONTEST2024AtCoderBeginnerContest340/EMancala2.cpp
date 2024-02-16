/**
 * Author: C0ldSmi1e
 * Created Time: 02/14/2024 11:45:38 AM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc340/tasks/abc340_e
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

  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  Fenwick<long long> fenw(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    fenw.Add(i, a[i]);
    fenw.Add(i + 1, -a[i]);
  }
  while (m--) {
    int i;
    cin >> i;
    long long x = fenw.Get(i);
    fenw.Add(i, -x);
    fenw.Add(i + 1, x);
    fenw.Add(0, x / n);
    fenw.Add(n, -x / n);
    if (x % n != 0) {
      long long y = x % n;
      fenw.Add(i + 1, 1);
      if (n - i - 1 >= y) {
        fenw.Add(i + y + 1, -1);
      } else {
        fenw.Add(n, -1);
        fenw.Add(0, 1);
        fenw.Add(y - (n - i - 1), -1);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << fenw.Get(i) << " \n"[i == n - 1];
  }
  return 0;
}
