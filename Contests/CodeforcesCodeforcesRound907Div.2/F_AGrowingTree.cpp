/**
 * Author: C0ldSmi1e
 * Created Time: 2023-10-30 10:09:49
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1891/problem/F
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
  inline void add(int x, T v) {
    assert(x >= 0 && x < n);
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
  inline T get(int x) {
    T res{};
    while (x >= 0) {
      res += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return res;
  }
  inline T get(int l, int r) {
    assert(l >= 0 && l < n && r >= 0 && r < n);
    T res = get(r);
    if (l - 1 >= 0) {
      res -= get(l - 1);
    }
    return res;
  }
  inline int kthMin(int k) {
    // kthMax = n - kthMin + 1
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
//   inline void operator += (Node &other) {
//     ...
//   }
// };

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);

  int T;
  cin >> T;
  while (T--) {
    int q;
    cin >> q;
    int n = 1;
    vector<vector<int>> g(n);
    vector<pair<int, int>> a(q);
    for (int i = 0; i < q; i++) {
      int t;
      cin >> t;
      if (t == 1) {
        int u;
        cin >> u;
        --u;
        a[i] = make_pair(-1, n);
        g[u].emplace_back(n);
        g.emplace_back(vector<int>());
        ++n;
      } else {
        int u, x;
        cin >> u >> x;
        --u;
        a[i] = make_pair(u, x);
      }
    }
    int time_stamp = 0;
    vector<int> in(n);
    vector<int> out(n);
    auto Dfs = [&](auto& self, int u) -> void {
      in[u] = time_stamp++;
      for (auto& v : g[u]) {
        self(self, v);
      }
      out[u] = time_stamp;
    };
    Dfs(Dfs, 0);
    assert(n == time_stamp);
    Fenwick<long long> fenw(n + 5);
    for (int i = 0; i < q; i++) {
      if (a[i].first == -1) {
        long long x = fenw.get(in[a[i].second]);
        fenw.add(in[a[i].second], -x);
        fenw.add(in[a[i].second] + 1, x);
      } else {
        auto [x, y] = a[i];
        fenw.add(in[x], y);
        fenw.add(out[x], -y);
      }
    }
    for (int i = 0; i < n; i++) {
      cout << fenw.get(in[i]) << " \n"[i == n - 1];
    }
  }
  return 0;
}
