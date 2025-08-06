/**
 * Author: C0ldSmi1e
 * Created Time: 08/05/2025 11:08:50 PM
**/

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

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& u : a) {
    cin >> u;
  }
  vector<int> b(n);
  Fenwick<int> fenw(n);
  for (auto& u : b) {
    cin >> u;
    fenw.Add(u, 1);
  }
  auto Find = [&](int l, int r) -> int {
    while (l < r) {
      int mid = (l + r) >> 1;
      if (fenw.Get(l, mid) > 0) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return r;
  };
  for (int i = 0; i < n; i++) {
    int y = (n - a[i] + n) % n;
    int x = -1;
    if (fenw.Get(y, n - 1) == 0) {
      x = Find(0, y);
    } else {
      x = Find(y, n - 1);
    }
    fenw.Add(x, -1);
    cout << (x + a[i]) % n << ' ';
  }
  cout << '\n';
  return 0;
}
