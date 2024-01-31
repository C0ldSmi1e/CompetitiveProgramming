/**
 * Author: C0ldSmi1e
 * Created Time: 01/17/2024 04:53:46 PM
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START117B/problems/AVOIDWALK
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto& u : a) {
      for (auto& v : u) {
        cin >> v;
      }
    }
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        g[i][j] = (int) (s[j] - '0');
      }
    }
    const long long INF = (long long) 1e18;
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(m, vector<long long>(2, INF)));
    // 0: from (i-1,j) to (i,j)
    // 1: from (i,j-1) to (i,j)
    dp[0][0][0] = dp[0][0][1] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i + 1 < n) {
          // to (i+1,j)
          long long ans2 = 1ll * k * ((i + 2 < n ? g[i + 2][j] : 0) + (i + 1 < n && j + 1 < m ? g[i + 1][j + 1] : 0));
          long long ans1 = ans2 + k * (i + 1 < n && j - 1 >= 0 ? g[i + 1][j - 1] : 0);
          dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][0] + a[i + 1][j] + ans1);
          dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][1] + a[i + 1][j] + ans2);
        }
        if (j + 1 < m) {
          // to (i,j+1)
          long long ans1 = 1ll * k * ((j + 2 < m ? g[i][j + 2] : 0) + (i + 1 < n && j + 1 < m ? g[i + 1][j + 1] : 0));
          long long ans2 = ans1 + k * (i - 1 >= 0 && j + 1 < m ? g[i - 1][j + 1] : 0);
          dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][0] + a[i][j + 1] + ans1);
          dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][1] + a[i][j + 1] + ans2);
        }
      }
    }
    cout << min(dp[n - 1][m - 1][0], dp[n - 1][m - 1][1]) << '\n';
  }
  return 0;
}
