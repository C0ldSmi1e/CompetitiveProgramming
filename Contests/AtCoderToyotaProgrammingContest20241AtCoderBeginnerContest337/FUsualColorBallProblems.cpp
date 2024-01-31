/**
 * Author: C0ldSmi1e
 * Created Time: 01/21/2024 11:34:05 AM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc337/tasks/abc337_f
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

  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (auto& u : a) {
    cin >> u;;
    --u;
  }
  a.insert(a.end(), a.begin(), a.end());
  vector<set<int>> S(n), T(n);
  set<pair<int, int>> mn;
  int cur = 0;
  auto Add = [&]() -> bool {
    auto [idx, val] = *mn.begin();
    if ((int) S[val].size() % k != 0) {
      T[val].erase(idx);
      mn.erase(mn.begin());
      S[val].insert(idx);
      return true;
    }
    if (cur + 1 < m) {
      cur += 1;
      T[val].erase(idx);
      mn.erase(mn.begin());
      S[val].insert(idx);
      return true;
    }
    return false;
  };
  auto Del = [&](int x) -> void {

  };
  for (int i = 0; i < n; i++) {
    mn.insert(make_pair(i, a[i]));
    T[a[i]].insert(i);
    Add();
  }
  vector<int> res(n);
  for (int i = n; i < 2 * n; i++) {
    mn.insert(make_pair(a[i], i));
    T[a[i]].insert(i);
    Del(a[i - n]);
    while (Add());
    res[i - n] = n - (int) mn.size();
  }
  for (auto& u : res) {
    cout << u << '\n';
  }
  return 0;
}
