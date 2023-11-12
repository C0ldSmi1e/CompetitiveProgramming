/**
 * Author: C0ldSmi1e
 * Created Time: 2023-10-22 21:32:14
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc325/tasks/abc325_g
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

  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = (int) s.size();
  vector<vector<int>> dp(n, vector<int>(n));
  for (int len = 1; len <= n; len++) {
    for (int l = 0; l + len - 1 < n; l++) {
      int r = l + len - 1;
      dp[l][r] = len;
      if (s[l] == 'o') {
        for (int i = l + 1; i <= r; i++) {
          if (s[i] == 'f' && (l + 1 == i || dp[l + 1][i - 1] == 0)) {
            dp[l][r] = min(dp[l][r], max(0, (i + 1 <= r ? dp[i + 1][r] : 0) - k));
          }
        }
      }
      for (int i = l + 1; i <= r; i++) {
        if (s[i] == 'o') {
          dp[l][r] = min(dp[l][r], dp[l][i - 1] + dp[i][r]);
        }
      }
    }
  }
  cout << dp[0][n - 1] << '\n';
  return 0;
}
