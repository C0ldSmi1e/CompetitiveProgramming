/**
 * Author: C0ldSmi1e
 * Created Time: 03/15/2024 07:43:57 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1948/problem/B
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

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    bool flag = false;
    for (int i = 0; i <= n; i++) {
      // [0, i) => [0, 9]
      vector<int> b;
      for (int j = 0; j < i; j++) {
        if (a[j] > 9) {
          b.emplace_back(a[j] / 10);
          b.emplace_back(a[j] % 10);
        } else {
          b.emplace_back(a[j]);
        }
      }
      // [i, n) => [10, 99]
      for (int j = i; j < n; j++) {
        b.emplace_back(a[j]);
      }
      bool ok = true;
      for (int i = 1; i < (int) b.size(); i++) {
        ok &= (b[i] >= b[i - 1]);
      }
      flag |= ok;
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
