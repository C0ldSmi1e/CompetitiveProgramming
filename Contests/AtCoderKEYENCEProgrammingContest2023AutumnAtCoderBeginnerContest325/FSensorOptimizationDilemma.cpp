// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc325/tasks/abc325_f
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
  cout << fixed << setprecision(10);

  int n;
  cin >> n;
  vector<int> d(n);
  for (auto& u : d) {
    cin >> u;
  }
  vector<int> l(2);
  vector<int> c(2);
  vector<int> k(2);
  for (int i = 0; i < 2; i++) {
    cin >> l[i] >> c[i] >> k[i];
  }
  const long long INF = (long long) 1e18;
  vector<vector<long long>> dp(n + 1, vector<long long>(k[0] + 1, INF));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k[0]; j++) {
      for (int x = j; x <= k[0]; x++) {
        int left = max(0, d[i] - (x - j) * l[0]);
        dp[i + 1][x] = min(dp[i + 1][x], dp[i][j] + (left + l[1] - 1) / l[1]);
      }
    }
  }
  long long res = INF;
  for (int j = 0; j <= k[0]; j++) {
    if (dp[n][j] <= k[1]) {
      res = min(res, dp[n][j] * c[1] + 1LL * j * c[0]);
    }
  }
  if (res == INF) {
    res = -1;
  }
  cout << res << '\n';
  return 0;
}
