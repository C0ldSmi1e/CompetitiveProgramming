/**
 * Author: C0ldSmi1e
 * Created Time: 02/07/2024 04:48:14 PM
**/

// time-limit: 4000
// problem-url: https://codeforces.com/contest/1927/problem/G
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
    const int INF = (int) 1e9;
    vector<vector<int>> dp(n, vector<int>(n, INF));
    for (int len = 1; len <= n; len++) {
      for (int l = 0; l + len - 1 < n; l++) {
        int r = l + len - 1;
        if (len == 1) {
          dp[l][r] = 1;
          continue;
        }
        for (int i = l; i <= r; i++) {
          if (i - 1 >= l) {
            dp[l][r] = min(dp[l][r], dp[l][i - 1] + dp[i][r]);
          }
          if (i + 1 <= r) {
            dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r]);
          }
          if (i - a[i] + 1 <= l) {
            dp[l][r] = min(dp[l][r], 1 + (i + 1 <= r ? dp[i + 1][r] : 0));
          }
          if (i + a[i] - 1 >= r) {
            dp[l][r] = min(dp[l][r], (i - 1 >= l ? dp[l][i - 1] : 0) + 1);
          }
        }
      }
    }
    cout << dp[0][n - 1] << '\n';
  }
  return 0;
}
