/**
 * Author: C0ldSmi1e
 * Created Time: 02/26/2024 10:28:01 AM
**/

// time-limit: 4000
// problem-url: https://codeforces.com/contest/1926/problem/F
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

  int n = 7;
  vector<vector<pair<int, int>>> idx(2);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      idx[(i + j) & 1].emplace_back(i, j);
    }
  }
  int T;
  cin >> T;
  while (T--) {
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < n; j++) {
        g[i][j] = (int) (s[j] == 'B');
      }
    }
    auto Check = [&](int t) -> bool {
      for (auto& [x, y] : idx[t]) {
        if (g[x][y] == 1) {
          int cnt = 0;
          cnt += (int) (x - 1 >= 0 && y - 1 >= 0 && g[x - 1][y - 1] == 1);
          cnt += (int) (x + 1 < n && y - 1 >= 0 && g[x + 1][y - 1] == 1);
          cnt += (int) (x + 1 < n && y + 1 < n && g[x + 1][y + 1] == 1);
          cnt += (int) (x - 1 >= 0 && y + 1 < n && g[x - 1][y + 1] == 1);
          if (cnt == 4) {
            return false;
          }
        }
      }
      return true;
    };
    int ans = 0;
    for (int t = 0; t < 2; t++) {
      int res = n * n;
      auto Dfs = [&](auto& self, int i, int cnt) -> void {
        if (Check(t)) {
          res = min(res, cnt);
        }
        if (i >= (int) idx[t].size() || cnt >= 4) {
          return;
        }
        self(self, i + 1, cnt);
        g[idx[t][i].first][idx[t][i].second] ^= 1;
        self(self, i + 1, cnt + 1);
        g[idx[t][i].first][idx[t][i].second] ^= 1;
      };
      Dfs(Dfs, 0, 0);
      ans += res;
    }
    cout << ans << '\n';
  }
  return 0;
}
