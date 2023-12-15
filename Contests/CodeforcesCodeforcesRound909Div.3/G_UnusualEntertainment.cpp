/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-17 09:06:26
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1899/problem/G
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
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].emplace_back(b);
      g[b].emplace_back(a);
    }
    vector<int> p(n);
    vector<set<int>> S(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      --p[i];
      S[p[i]].insert(i);
    }
    vector<vector<array<int, 3>>> query(n);
    for (int i = 0; i < q; i++) {
      int l, r, x;
      cin >> l >> r >> x;
      --l;
      --r;
      --x;
      query[x].push_back({l, r, i});
    }
    vector<bool> res(q);
    auto Dfs = [&](auto& self, int u, int fa) -> void {
      for (auto& v : g[u]) {
        if (v != fa) {
          self(self, v, u);
          if ((int) S[u].size() < (int) S[v].size()) {
            swap(S[u], S[v]);
          }
          S[u].insert(S[v].begin(), S[v].end());
        }
      }
      for (auto& [l, r, i] : query[u]) {
        auto it = S[u].lower_bound(l);
        res[i] = (it != S[u].end() && *it <= r);
      }
    };
    Dfs(Dfs, 0, -1);
    for (int i = 0; i < q; i++) {
      cout << (res[i] ? "YES\n" : "NO\n");
    }
    cout << '\n';
  }
  return 0;
}
