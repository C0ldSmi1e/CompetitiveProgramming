/**
 * Author: C0ldSmi1e
 * Created Time: 02/16/2025 09:21:35 PM
**/

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
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i][0];
    }
    int x;
    cin >> x;
    for (int i = 0; i < n; i++) {
      a[i][1] = x - a[i][0];
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(2));
    dp[0][0] = true;
    dp[0][1] = true;
    for (int i = 0; i < n - 1; i++) {
      if (dp[i][0]) {
        if (a[i + 1][0] >= a[i][0]) {
          dp[i + 1][0] = true;
        }
        if (a[i + 1][1] >= a[i][0]) {
          dp[i + 1][1] = true;
        }
      }
      if (dp[i][1]) {
        if (a[i + 1][0] >= a[i][1]) {
          dp[i + 1][0] = true;
        }
        if (a[i + 1][1] >= a[i][1]) {
          dp[i + 1][1] = true;
        }
      }
    }
    cout << ((dp[n - 1][0] || dp[n - 1][1]) ? "YES\n" : "NO\n");
  }
  return 0;
}
