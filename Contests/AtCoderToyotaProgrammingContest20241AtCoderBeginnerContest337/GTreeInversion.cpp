/**
 * Author: C0ldSmi1e
 * Created Time: 01/21/2024 11:12:41 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc337/tasks/abc337_g
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
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  vector<long long> cnt(n);
  vector<long long> res(n);
  vector<int> order;
  vector<int> in(n, -1);
  vector<int> out(n, -1);
  vector<int> father(n, -1);
  auto Dfs1 = [&](auto& self, int u, int fa) -> void {
    father[u] = fa;
    in[u] = (int) order.size();
    order.emplace_back(u);
    for (auto& v : g[u]) {
      if (v != fa) {
        self(self, v, u);
      }
    }
    out[u] = (int) order.size();
  };
  Dfs1(Dfs1, 0, -1);
  Fenwick<int> fenw(n);
  for (int u = 0; u < n; u++) {
    for (auto& v : g[u]) {
      if (father[u] != -1 && v != father[u]) {
        res[v] += u - fenw.Get(in[v], out[v] - 1);
      }
    }
    cnt[u] = fenw.Get(in[u], out[u] - 1);
    res[u] -= cnt[u];
    fenw.Add(in[u], 1);
  }
  res[0] = accumulate(cnt.begin(), cnt.end(), 0ll) - cnt[0];
  auto Dfs2 = [&](auto& self, int u, int fa) -> void {
    for (auto& v : g[u]) {
      if (v != fa) {
        res[v] += res[u];
        self(self, v, u);
      }
    }
  };
  Dfs2(Dfs2, 0, -1);
  for (int i = 0; i < n; i++) {
    res[i] += i;
    cout << res[i] << " \n"[i == n - 1];
  }
  return 0;
}

