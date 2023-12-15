/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-30 09:04:29
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1903/problem/C
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
    vector<long long> suff(n + 1);
    for (int i = n - 1; i >= 0; i--) {
      suff[i] = suff[i + 1] + a[i];
    }
    const long long INF = (long long) 2e18;
    vector<vector<long long>> dp(n, vector<long long>(2, -INF));
    dp[0][1] = suff[0];
    for (int i = 1; i < n; i++) {
      dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + suff[i];
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';
  }
  return 0;
}
