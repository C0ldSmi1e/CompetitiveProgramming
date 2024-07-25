/**
 * Author: C0ldSmi1e
 * Created Time: 06/16/2024 10:47:13 PM
**/

// time-limit: 2000
// problem-url: 
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
    vector<string> g(n);
    for (auto& s : g) {
      cin >> s;
    }
    vector<vector<bool>> st(n, vector<bool>(m));
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
    vector<vector<int>> pref(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!st[i][j] && g[i][j] == '#') {
          int sz = 0;
          int u = n;
          int l = m;
          int r = -1;
          int d = -1;
          auto Dfs = [&](auto& self, int x, int y) -> void {
            st[x][y] = true;
            u = min(u, x);
            d = max(d, x);
            l = min(l, y);
            r = max(r, y);
            sz += 1;
            for (int i = 0; i < 4; i++) {
              int tx = x + dx[i];
              int ty = y + dy[i];
              if (tx < 0 || ty < 0 || tx >= n || ty >= m) {
                continue;
              }
              if (g[tx][ty] != '#' || st[tx][ty]) {
                continue;
              }
              self(self, tx, ty);
            }
          };
          Dfs(Dfs, i, j);
          u = max(0, u - 1);
          l = max(0, l - 1);
          d = min(n - 1, d + 1);
          r = min(m - 1, r + 1);
          pref[0][l] += sz;
          pref[0][r + 1] -= sz;
          pref[n][l] -= sz;
          pref[n][r + 1] += sz;
          pref[u][0] += sz;
          pref[u][m] -= sz;
          pref[d + 1][0] -= sz;
          pref[d + 1][m] += sz;
          pref[u][l] += -sz;
          pref[u][r + 1] -= -sz;
          pref[d + 1][l] -= -sz;
          pref[d + 1][r + 1] += -sz;
          debug(i, j, u, d, l, r, sz);
        }
      }
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        if (i - 1 >= 0) {
          pref[i][j] += pref[i - 1][j];
        }
        if (j - 1 >= 0) {
          pref[i][j] += pref[i][j - 1];
        }
        if (i - 1 >= 0 && j - 1 >= 0) {
          pref[i][j] -= pref[i - 1][j - 1];
        }
      }
    }
    vector<int> sx(n);
    vector<int> sy(m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (g[i][j] == '.') {
          sx[i] += 1;
          sy[j] += 1;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans = max(ans, pref[i][j] + sx[i] + sy[j] - (int) (g[i][j] == '.'));
        debug(i, j, pref[i][j], sx[i], sy[j]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
