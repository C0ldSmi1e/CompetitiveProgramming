/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-07 22:49:26
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1906/problem/E
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
  vector<int> p(2 * n);
  for (auto& u : p) {
    cin >> u;
  }
  int last = 0;
  vector<bool> st(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    if (p[i] > last) {
      last = p[i];
      st[i] = true;
    }
  }
  vector<vector<vector<bool>>> dp(2 * n + 1, vector<vector<bool>>(n + 1, vector<bool>(2)));
  vector<vector<vector<tuple<int, int, int>>>> pre(2 * n + 1, vector<vector<tuple<int, int, int>>>(n + 1, vector<tuple<int, int, int>>(2)));
  dp[0][0][0] = true;
  for (int i = 0; i < 2 * n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k < 2; k++) {
        if (dp[i][j][k]) {
          if (k == 0) {
            if (j + 1 <= n) {
              pre[i + 1][j + 1][k] = {i, j, k};
              dp[i + 1][j + 1][k] = true;
            }
            if (i > 0 && st[i]) {
              pre[i + 1][j][1] = {i, j, k};
              dp[i + 1][j][1] = true;
            }
          }
          if (k == 1) {
            pre[i + 1][j][k] = {i, j, k};
            dp[i + 1][j][k] = true;
            if (i > 0 && st[i] && j + 1 <= n) {
              pre[i + 1][j + 1][0] = {i, j, k};
              dp[i + 1][j + 1][0] = true;
            }
          }
        }
      }
    }
  }
  if (!dp[2 * n][n][0] && !dp[2 * n][n][1]) {
    cout << "-1\n";
    return 0;
  }
  int i = 2 * n, j = n, k = 0;
  if (!dp[i][j][k]) {
    k = 1;
  }
  vector<vector<int>> a(2);
  auto Dfs = [&](auto& self, int i, int j, int k) -> void {
    a[k].emplace_back(p[i - 1]);
    auto [ii, jj, kk] = pre[i][j][k];
    if (ii == 0) {
      return;
    }
    self(self, ii, jj, kk);
  };
  Dfs(Dfs, i, j, k);
  reverse(a[0].begin(), a[0].end());
  reverse(a[1].begin(), a[1].end());
  for (auto& u : a[0]) {
    cout << u << ' ';
  }
  cout << '\n';
  for (auto& u : a[1]) {
    cout << u << ' ';
  }
  cout << '\n';
  return 0;
}
