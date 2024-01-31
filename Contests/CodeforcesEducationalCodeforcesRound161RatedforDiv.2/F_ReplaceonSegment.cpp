/**
 * Author: C0ldSmi1e
 * Created Time: 01/18/2024 08:01:27 AM
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1922/problem/F
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
      --u;
    }
    const int INF = (int) 1e9;
    vector<vector<vector<int>>> dp1(n, vector<vector<int>>(n, vector<int>(m, INF)));
    vector<vector<vector<int>>> dp2(n, vector<vector<int>>(n, vector<int>(m, INF)));
    for (int len = 1; len <= n; len++) {
      for (int l = 0; l + len - 1 < n; l++) {
        int r = l + len - 1;
        for (int k = 0; k < m; k++) {
          if (len == 1) {
            dp1[l][r][k] = (int) (a[r] != k);
            dp2[l][r][k] = (int) (a[r] == k);
            continue;
          }
          for (int i = l; i < r; i++) {
            dp1[l][r][k] = min(dp1[l][r][k], dp1[l][i][k] + dp1[i + 1][r][k]);
            dp2[l][r][k] = min(dp2[l][r][k], dp2[l][i][k] + dp2[i + 1][r][k]);
          }
          if (a[l] == k) {
            dp1[l][r][k] = min(dp1[l][r][k], dp1[l + 1][r][k]);
            for (int kk = 0; kk < m; kk++) {
              if (k != kk) {
                dp2[l][r][kk] = min(dp2[l][r][kk], dp1[l][r][k]);
              }
            }
          } else {
            dp2[l][r][k] = min(dp2[l][r][k], dp2[l + 1][r][k]);
            dp1[l][r][k] = min(dp1[l][r][k], dp2[l][r][k] + 1);
          }
        }
      }
    }
    int res = INF;
    for (int k = 0; k < m; k++) {
      res = min(res, dp1[0][n - 1][k]);
    }
    cout << res << '\n';
  }
  return 0;
}
