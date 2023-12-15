// time-limit: 4000
// problem-url: https://codeforces.com/contest/1904/problem/D2
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

// usage:
//   auto Fun = [&](int i, int j) { return min(i, j); };
//   Fenwick<int, decltype(Fun)> fen(a, Fun);
// or:
//   Fenwick<int> fen(a, [&](int i, int j) { return min(i, j); });
#define lowbit(x) (x&(-x))
template <typename T, class F = function<T(const T&, const T&)>>
class Fenwick {
 public:
  int n;
  vector<T> val, fenw;
  F Func;
  Fenwick (const vector<T>& a, const F& f) : Func(f) {
    n = static_cast<int>(a.size());
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

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> idx_a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
      idx_a[a[i]].emplace_back(i);
    }
    vector<int> b(n);
    vector<vector<int>> idx_b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      --b[i];
      idx_b[b[i]].emplace_back(i);
    }
    Fenwick<int> fenw_a(a, [&](int i, int j) { return max(i, j); });
    Fenwick<int> fenw_b(b, [&](int i, int j) { return min(i, j); });
    bool flag = true;
    for (int x = 0; x < n; x++) {
      for (auto& i : idx_b[x]) {
        bool ok = false;
        auto it = lower_bound(idx_a[x].begin(), idx_a[x].end(), i);
        //debug(x);
        if (it != idx_a[x].end()) {
          //debug(i, *it);
          ok |= ((fenw_a.Query(i, *it) == x) && (fenw_b.Query(i, *it) == x));
        }
        if (it != idx_a[x].begin()) {
          --it;
          //debug(*it, i);
          ok |= ((fenw_a.Query(*it, i) == x) && (fenw_b.Query(*it, i) == x));
        }
        flag &= ok;
      }
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
