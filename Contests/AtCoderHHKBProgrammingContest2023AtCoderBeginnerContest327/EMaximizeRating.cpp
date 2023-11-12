/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-04 05:42:49
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc327/tasks/abc327_e
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
  cout << fixed << setprecision(15);

  int n;
  cin >> n;
  vector<int> p(n);
  for (auto& u : p) {
    cin >> u;
  }
  vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1e18));
  vector<vector<double>> a(n + 1, vector<double>(n + 1));
  vector<vector<double>> b(n + 1, vector<double>(n + 1));
  for (int i = 1; i <= n; i++) {
    dp[i][1] = p[i - 1] - 1200.0;
    a[i][1] = p[i - 1];
    b[i][1] = 1;
    if (i > 1 && dp[i][1] < dp[i - 1][1]) {
      dp[i][1] = dp[i - 1][1];
      a[i][1] = a[i - 1][1];
      b[i][1] = b[i - 1][1];
    }
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= i; j++) {
      // not choose
      dp[i][j] = dp[i - 1][j];
      a[i][j] = a[i - 1][j];
      b[i][j] = b[i - 1][j];
      // choose
      double ta = a[i - 1][j - 1] * 0.9 + p[i - 1];
      double tb = b[i - 1][j - 1] * 0.9 + 1;
      double ans = ta / tb - 1200.0 / sqrt(j);
      if (ans > dp[i][j]) {
        debug(i, j);
        dp[i][j] = ans;
        a[i][j] = ta;
        b[i][j] = tb;
      }
    }
  }
  double res = -1e18;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      res = max(res, dp[i][j]);
    }
  }
  cout << res << '\n';
  return 0;
}
