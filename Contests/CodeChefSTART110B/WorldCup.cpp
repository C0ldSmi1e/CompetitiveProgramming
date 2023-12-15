/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-01 11:27:23
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START110B/problems/SPCP8
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    sort(a.rbegin(), a.rend());
    vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(n + 1, vector<bool>(m + 1)));
    dp[0][0][0] = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        for (int k = 0; k <= m; k++) {
          if (dp[i][j][k]) {
            // not choose i-th
            dp[i + 1][j][k] = true;
            // choose i-th
            if (k + a[i] <= m) {
              dp[i + 1][j + 1][k + a[i]] = true;
            }
          }
        }
      }
    }
    int res = n;
    for (int i = n - 1, cur = 0; i >= 0; i--) {
      // choose (i, n - 1], a[i] is the smallest one that's not chosen
      for (int j = 0; j <= n; j++) {
        for (int k = 0; k <= m; k++) {
          if (dp[i][j][k] && cur + k <= m && (n - i - 1 + j + 1) * a[i] > m - cur - k) {
            res = min(res, n - i - 1 + j);
          }
        }
      }
      cur += a[i];
    }
    cout << res << '\n';
  }
  return 0;
}
