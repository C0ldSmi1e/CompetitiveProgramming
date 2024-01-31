/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-28 06:59:56
**/

// time-limit: 5000
// problem-url: https://codeforces.com/contest/1915/problem/F
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
    vector<pair<int, int>> a(n);
    vector<int> all;
    for (auto& [x, y] : a) {
      cin >> x >> y;
      all.emplace_back(x);
      all.emplace_back(y);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (auto& [x, y] : a) {
      x = (int) (lower_bound(all.begin(), all.end(), x) - all.begin());
      y = (int) (lower_bound(all.begin(), all.end(), y) - all.begin());
    }
    sort(a.begin(), a.end());
    int m = (int) all.size();
    Fenwick<int> fenw(m);
    for (auto& [x, y] : a) {
      fenw.Add(y, 1);
    }
    long long res = 0;
    for (auto& [x, y] : a) {
      if (y - 1 >= 0) {
        res += fenw.Get(y - 1);
      }
      fenw.Add(y, -1);
    }
    cout << res << '\n';
  }
  return 0;
}
