/**
 * Author: C0ldSmi1e
 * Created Time: 01/15/2024 06:45:34 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1921/problem/C
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
    int n, f, a, b;
    cin >> n >> f >> a >> b;
    vector<int> m(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> m[i];
    }
    const long long INF = (long long) 8e18;
    vector<long long> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      dp[i] = dp[i - 1] + min(1ll * (m[i] - m[i - 1]) * a, 1ll * b);
    }
    debug(dp);
    cout << (f > dp[n] ? "YES\n" : "NO\n");
  }
  return 0;
}
