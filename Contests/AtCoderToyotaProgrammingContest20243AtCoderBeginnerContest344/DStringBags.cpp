/**
 * Author: C0ldSmi1e
 * Created Time: 03/14/2024 03:58:44 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc344/tasks/abc344_d
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

  string t;
  cin >> t;
  int m = (int) t.size();
  int n;
  cin >> n;
  const int INF = (int) 1e9;
  vector<int> dp(m + 1, INF);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    vector<int> ndp(m + 1, INF);
    while (k--) {
      string s;
      cin >> s;
      int nn = (int) s.size();
      for (int j = 0; j <= m; j++) {
        ndp[j] = min(ndp[j], dp[j]);
        if (dp[j] == INF) {
          continue;
        }
        if (j + nn - 1 < m && t.substr(j, nn) == s) {
          ndp[j + nn] = min(ndp[j + nn], dp[j] + 1);
        }
      }
    }
    swap(dp, ndp);
  }
  if (dp[m] == INF) {
    cout << "-1\n";
  } else {
    cout << dp[m] << '\n';
  }
  return 0;
}
