/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-01 16:42:14
**/

// time-limit: 4000
// problem-url: https://codeforces.com/contest/1896/problem/E
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

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
      --u;
    }
    vector<pair<int, int>> seg;
    for (int i = 0; i < n; i++) {
      int l = i;
      int r = a[i];
      if (l > r) {
        r += n;
      }
      seg.emplace_back(make_pair(l, r));
      if (r < n) {
        seg.emplace_back(make_pair(l + n, r + n));
      }
    }
    sort(seg.begin(), seg.end());
    debug(seg);
    Fenwick<int> fenw(2 * n + 1);
    vector<int> res(n);
    for (int i = (int) seg.size() - 1; i >= 0; i--) {
      auto [l, r] = seg[i];
      if (l < n) {
        res[r % n] = r - l - fenw.Get(l, r);
      }
      fenw.Add(r, 1);
    }
    for (auto& u : res) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}
