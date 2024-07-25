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
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, INF)));
    for (int i = 0; i < n; i++) {
      int l = max(0, i - a[i] + 1);
      int r = min(n - 1, i + a[i] - 1);
      dp[i][i][r] = dp[i][l][i] = 1;
    }
    for (int i = 0; i < n - 1; i++) {
      for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
          dp[i + 1][l][r] = min(dp[i + 1][l][r], dp[i][l][r]);
          int R = min(n - 1, i + 1 + a[i + 1] - 1);
          if (R >= r) {
            if (r >= i) {
              dp[i + 1][l][R] = min(dp[i + 1][l][R], dp[i][l][r] + 1);
            } else {
              for (int j = i + 2; j <= R; j++) {
                int L = max(0, j - a[j] + 1);
                if (L <= l) {
                  dp[j][L][R] = min(dp[j][L][R], dp[i][l][r] + 2);
                }
                if (L <= r + 1) {
                  dp[j][l][R] = min(dp[j][l][R], dp[i][l][r] + 2);
                }
              }
            }
          }
          int L = max(0, i + 1 - a[i + 1] + 1);
          if (L <= l) {
            dp[i + 1][L][max(r, i + 1)] = min(dp[i + 1][L][max(r, i + 1)], dp[i][l][r] + 1);
            continue;
          }
          if (L <= r + 1) {
            dp[i + 1][l][max(r, i + 1)] = min(dp[i + 1][l][max(r, i + 1)], dp[i][l][r] + 1);
          }
        }
      }
    }
    cout << dp[n - 1][0][n - 1] << '\n';
  }
  return 0;
}
