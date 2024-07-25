/**
 * Author: C0ldSmi1e
 * Created Time: 04/08/2024 08:56:09 AM
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1955/problem/G
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

const int M = 101;

bool dp[M][M];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);

  const int N = 1000010;
  vector<vector<int>> factors(N);
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      factors[j].emplace_back(i);
    }
  }
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (auto& u : g) {
      for (auto& v : u) {
        cin >> v;
      }
    }
    int ans = 0;
    auto Get = [&](int x) -> int {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          dp[i][j] = false;
        }
      }
      dp[0][0] = true;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (!dp[i][j]) {
            continue;
          }
          if (i + 1 < n && g[i + 1][j] % x == 0) {
            dp[i + 1][j] = true;
          }
          if (j + 1 < m && g[i][j + 1] % x == 0) {
            dp[i][j + 1] = true;
          }
        }
      }
      if (dp[n - 1][m - 1]) {
        return x;
      }
      return 0;
    };
    for (auto& fac : factors[g[0][0]]) {
      ans = max(ans, Get(fac));
    }
    cout << ans << '\n';
  }
  return 0;
}
