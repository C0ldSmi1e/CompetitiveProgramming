/**
 * Author: C0ldSmi1e
 * Created Time: 03/01/2024 06:42:35 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1934/problem/B
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

  vector<int> dp(51, 100);
  dp[0] = 0;
  vector<int> b{1, 3, 6, 10, 15};
  for (int i = 0; i < 5; i++) {
    auto ndp = dp;
    for (int j = 1; j <= 50; j++) {
      for (int k = 0; k * b[i] <= j; k++) {
        ndp[j] = min(ndp[j], dp[j - k * b[i]] + k);
      }
    }
    swap(dp, ndp);
  }
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int ans = n;
    for (int i = 0; i <= 2; i++) {
      int m = n - i * 15;
      if (m < 0) {
        continue;
      }
      ans = min(ans, m / 15 + dp[m % 15 + i * 15]);
    }
    cout << ans << '\n';
  }
  return 0;
}
