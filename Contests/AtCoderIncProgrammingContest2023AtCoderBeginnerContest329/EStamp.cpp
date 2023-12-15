/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-18 23:00:36
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc329/tasks/abc329_e
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

  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i] == t[j]) {
        dp[i + 1][j + 1] = (dp[i][j] | dp[i][m]);
      }
    }
    if (s[i] == t[0]) {
      for (int j = 0; j <= m; j++) {
        dp[i + 1][1] |= dp[i][j];
      }
    }
  }
  cout << (dp[n][m] ? "Yes\n" : "No\n");
  return 0;
}
