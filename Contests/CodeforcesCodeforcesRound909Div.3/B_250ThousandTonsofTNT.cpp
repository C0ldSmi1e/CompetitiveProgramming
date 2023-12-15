/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-17 06:45:48
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1899/problem/B
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
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
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + a[i];
    }
    long long res = 0;
    for (int x = 1; x <= n / x; x++) {
      if (n % x == 0) {
        for (auto& y : {x, n / x}) {
          long long mx = 0;
          long long mn = (long long) 1e18;
          for (int i = 0; i < n; i += y) {
            mx = max(mx, pref[i + y] - pref[i]);
            mn = min(mn, pref[i + y] - pref[i]);
          }
          res = max(res, mx - mn);
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}
