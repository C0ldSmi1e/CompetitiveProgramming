/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-02 11:46:20
**/

// time-limit: 3000
// problem-url: https://atcoder.jp/contests/abc331/tasks/abc331_f
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

  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  string rs = s;
  reverse(rs.begin(), rs.end());
  const int P = 13331;
  vector<unsigned long long> p(n);
  p[0] = 1;
  for (int i = 1; i < n; i++) {
    p[i] = p[i - 1] * P;
  }
  vector<unsigned long long> h(n);
  vector<unsigned long long> rh(n);
  for (int i = 0; i < n; i++) {
    h[i] = p[i] * (int) (s[i] - 'a');
    rh[i] = p[i] * (int) (rs[i] - 'a');
  }
  Fenwick<unsigned long long> fenw(n);
  Fenwick<unsigned long long> rfenw(n);
  for (int i = 0; i < n; i++) {
    fenw.Add(i, h[i]);
    rfenw.Add(i, rh[i]);
  }
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int i;
      char c;
      cin >> i >> c;
      --i;
      fenw.Add(i, -h[i]);
      rfenw.Add(n - i - 1, -rh[n - i - 1]);
      s[i] = rs[n - i - 1] = c;
      h[i] = p[i] * (int) (c - 'a');
      rh[n - i - 1] = p[n - i - 1] * (int) (c - 'a');
      fenw.Add(i, h[i]);
      rfenw.Add(n - i - 1, rh[n - i - 1]);
    } else {
      int l, r;
      cin >> l >> r;
      --l;
      --r;
      unsigned long long L = fenw.Get(l, r);
      unsigned long long R = rfenw.Get(n - r - 1, n - l - 1);
      if (r < n - l - 1) {
        L *= p[n - l - 1 - r];
      } else {
        R *= p[r + l + 1 - n];
      }
      cout << (L == R ? "Yes\n" : "No\n");
    }
  }
  return 0;
}
