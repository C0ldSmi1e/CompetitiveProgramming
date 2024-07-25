/**
 * Author: C0ldSmi1e
 * Created Time: 03/14/2024 04:24:28 PM
**/

// time-limit: 4000
// problem-url: https://atcoder.jp/contests/abc344/tasks/abc344_f
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

  int n;
  cin >> n;
  vector<vector<long long>> a(n, vector<long long>(n));
  for (auto& u : a) {
    for (auto& v : u) {
      cin >> v;
    }
  }
  vector<vector<long long>> b(n, vector<long long>(n - 1));
  for (auto& u : b) {
    for (auto& v : u) {
      cin >> v;
    }
  }
  vector<vector<long long>> c(n - 1, vector<long long>(n));
  for (auto& u : c) {
    for (auto& v : u) {
      cin >> v;
    }
  }
  const long long INF = (long long) 8e18;
  vector<vector<vector<vector<long long>>>> cost(n, vector<vector<vector<long long>>>(n, vector<vector<long long>>(n, vector<long long>(n, INF))));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cost[i][j][i][j] = 0;
      for (int x = i; x < n; x++) {
        for (int y = j; y < n; y++) {
          if (x + 1 < n) {
            cost[i][j][x + 1][y] = min(cost[i][j][x + 1][y], cost[i][j][x][y] + c[x][y]);
          }
          if (y + 1 < n) {
            cost[i][j][x][y + 1] = min(cost[i][j][x][y + 1], cost[i][j][x][y] + b[x][y]);
          }
        }
      }
    }
  }
  vector<vector<pair<long long, long long>>> dp(n, vector<pair<long long, long long>>(n, make_pair(INF, -INF)));
  dp[0][0] = make_pair(0, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int x = i; x < n; x++) {
        for (int y = j; y < n; y++) {
          if (x == i && y == j) {
            continue;
          }
          long long d = x - i + y - j;
          long long need = max(0ll, cost[i][j][x][y] - dp[i][j].second);
          long long stay = (need + a[i][j] - 1) / a[i][j];
          if (dp[x][y].first > dp[i][j].first + stay + d || (dp[x][y].first == dp[i][j].first + stay + d && dp[i][j].second + stay * a[i][j] - cost[i][j][x][y] > dp[x][y].second)) {
            dp[x][y] = make_pair(dp[i][j].first + stay + d, dp[i][j].second + stay * a[i][j] - cost[i][j][x][y]);
          }
        }
      }
    }
  }
  cout << dp[n - 1][n - 1].first << '\n';
  return 0;
}
