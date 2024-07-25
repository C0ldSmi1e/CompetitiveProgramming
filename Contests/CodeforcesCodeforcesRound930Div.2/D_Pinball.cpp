/**
 * Author: C0ldSmi1e
 * Created Time: 02/29/2024 10:27:55 PM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1937/problem/D
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
    string s;
    cin >> s;
    auto Get = [&](string& s) -> vector<long long> {
      debug(s);
      vector<int> l, r;
      for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '<') {
          l.emplace_back(i);
        }
      }
      int ln = (int) l.size();
      Fenwick<long long> ls(ln);
      Fenwick<long long> ld(ln);
      for (int i = 0; i < ln; i++) {
        ls.Add(i, 2 * (l[i] + 1));
        ld.Add(i, 2 * (n - l[i]));
      }
      int rn = 0;
      Fenwick<long long> rs(n);
      Fenwick<long long> rd(n);
      vector<long long> ans(n, -1);
      for (int i = 0; i < n; i++) {
        if (s[i] == '<') {
          l.pop_back();
          ln -= 1;
          continue;
        }
        r.emplace_back(i);
        rn += 1;
        rs.Add(rn - 1, 2 * (n - r[rn - 1]));
        rd.Add(rn - 1, r[rn - 1] + 1);
        if (rn - 2 >= 0) {
          rd.Add(rn - 1, r[rn - 2] + 1);
        }
        if (rn <= ln) {
          // left from the left
          ans[i] = ls.Get(ln - rn, ln - 1) - rd.Get(0, rn - 1);
        } else {
          // left from the right
          if (ln == 0) {
            ans[i] = n - r.back();
          } else {
            ans[i] = rs.Get(rn - ln - 1, rn - 1) - ld.Get(0, ln - 1) - (n - r.back());
          }
        }
      }
      return ans;
    };
    auto ans = Get(s);
    reverse(s.begin(), s.end());
    for (auto& c : s) {
      if (c == '<') {
        c = '>';
      } else {
        c = '<';
      }
    }
    auto t = Get(s);
    for (int i = 0; i < n; i++) {
      if (t[i] != -1) {
        ans[n - i - 1] = t[i];
      }
    }
    for (auto& u : ans) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}
