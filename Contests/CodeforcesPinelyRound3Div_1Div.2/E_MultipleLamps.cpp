/**
 * Author: C0ldSmi1e
 * Created Time: 01/03/2024 04:04:10 PM
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1909/problem/E
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);

  vector<vector<int>> g(20);
  for (int n = 1; n <= 19; n++) {
    for (int mask = 1; mask < 1 << n; mask++) {
      int cur = 0;
      for (int i = 1; i <= n; i++) {
        if ((mask >> (i - 1)) & 1) {
          for (int j = i; j <= n; j += i) {
            cur ^= 1 << (j - 1);
          }
        }
      }
      if (__builtin_popcount(cur) <= n / 5) {
        g[n].emplace_back(mask);
      }
    }
  }
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> t(n);
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      t[a] |= (1 << b);
    }
    if (n >= 20) {
      cout << n << '\n';
      for (int i = 1; i <= n; i++) {
        cout << i << " \n"[i == n];
      }
      continue;
    }
    auto Get = [&](int n) -> int {
      for (auto& mask : g[n]) {
        bool flag = true;
        for (int bit = 0; bit < n; bit++) {
          if ((mask >> bit) & 1) {
            flag &= ((mask & t[bit]) == t[bit]);
          }
        }
        if (flag) {
          return mask;
        }
      }
      return -1;
    };
    int res = Get(n);
    if (res == -1) {
      cout << "-1\n";
      continue;
    }
    cout << __builtin_popcount(res) << '\n';
    for (int bit = 0; bit < n; bit++) {
      if ((res >> bit) & 1) {
        cout << bit + 1 << ' ';
      }
    }
    cout << '\n';
  }
  return 0;
}
