/**
 * Author: C0ldSmi1e
 * Created Time: 01/12/2024 11:03:58 PM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START116B/problems/EXACTSAVINGS
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
    int n, x, z;
    cin >> n >> x >> z;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    const long long INF = (long long) 2e18;
    vector<long long> dp(x, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      auto ndp = dp;
      for (int j = 0; j < x; j++) {
        ndp[(j + a[i]) % x] = min(ndp[(j + a[i]) % x], dp[j] + a[i]);
      }
      swap(ndp, dp);
    }
    if (dp[(x - z % x) % x] == INF) {
      cout << "-1\n";
      continue;
    }
    cout << (dp[(x - z % x) % x] + z) / x << '\n';
  }
  return 0;
}
