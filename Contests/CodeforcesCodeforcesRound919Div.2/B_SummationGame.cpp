/**
 * Author: C0ldSmi1e
 * Created Time: 01/13/2024 06:47:32 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1920/problem/B
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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    sort(a.begin(), a.end());
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + a[i];
    }
    int res = -(int) 2e9;
    for (int i = 0; i <= x; i++) {
      int alice = pref[max(0, n - i - y)];
      int bob = pref[n - i] - pref[max(0, n - i - y)];
      res = max(res, alice - bob);
    }
    cout << res << '\n';
  }
  return 0;
}
