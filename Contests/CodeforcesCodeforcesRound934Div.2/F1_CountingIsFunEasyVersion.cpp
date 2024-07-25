/**
 * Author: C0ldSmi1e
 * Created Time: 03/16/2024 09:33:52 AM
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1944/problem/F1
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
    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int j = 0; j <= m; j++) {
      dp[1][j] = 1;
      dp[2][j] = 1;
    }
    for (int i = 3; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        for (int k = j; k <= m; k++) {
          dp[i][j] = (dp[i][j] + dp[i - 1][k]) % p;
        }
        int tot = 0;
        for (int k = 0; k <= m; k++) {
          tot = (tot + dp[i - 2][k]) % p;
        }
        dp[i][j] = (dp[i][j] + tot + 1) % p;
      }
    }
    int ans = 0;
    for (int j = 0; j <= m; j++) {
      ans = (ans + dp[n][j]) % p;
    }
    cout << ans << '\n';
  }
  return 0;
}
