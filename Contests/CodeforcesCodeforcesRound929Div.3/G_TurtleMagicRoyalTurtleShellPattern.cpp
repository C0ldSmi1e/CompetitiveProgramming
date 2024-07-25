/**
 * Author: C0ldSmi1e
 * Created Time: 02/27/2024 03:34:45 PM
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1933/problem/G
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

  int n = 5, m = 5;
  vector<vector<vector<int>>> d;
  vector<vector<int>> g(n, vector<int>(m, -1));
  auto Dfs = [&](auto& self, int i, int j) -> void {
    if (i == n) {
      d.emplace_back(g);
      //for (int i = 0; i < n; i++) {
      //  for (int j = 0; j < m; j++) {
      //    cout << g[i][j] << " \n"[j == m - 1];
      //  }
      //}
      //cout << '\n';
      return;
    }
    if (j == m) {
      self(self, i + 1, 0);
      return;
    }
    for (int x = 0; x <= 1; x++) {
      bool flag = true;
      if (j - 2 >= 0 && g[i][j - 1] == x && g[i][j - 2] == x) {
        flag = false;
      }
      if (i - 2 >= 0 && g[i - 1][j] == x && g[i - 2][j] == x) {
        flag = false;
      }
      if (i - 2 >= 0 && j - 2 >= 0 && g[i - 1][j - 1] == x && g[i - 2][j - 2] == x) {
        flag = false;
      }
      if (i - 2 >= 0 && j + 2 < m && g[i - 1][j + 1] == x && g[i - 2][j + 2] == x) {
        flag = false;
      }
      if (flag) {
        g[i][j] = x;
        self(self, i, j + 1);
        g[i][j] = -1;
      }
    }
  };
  Dfs(Dfs, 0, 0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> f(4, vector<int>(4, -1));
    vector<bool> ans(8, true);
    cout << count(ans.begin(), ans.end(), true) << '\n';
    while (q--) {
      int x, y;
      cin >> x >> y;
      string s;
      cin >> s;
      for (int i = 0; i < 8; i++) {
        ans[i] = (ans[i] && ((s == "circle") == (d[i][x % 4][y % 4])));
      }
      cout << count(ans.begin(), ans.end(), true) << '\n';
    }
  }
  return 0;
}
