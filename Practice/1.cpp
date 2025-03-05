/**
 * Author: C0ldSmi1e
 * Created Time: 03/04/2025 09:42:08 AM
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
    vector<string> g(n);
    for (auto& s : g) {
      cin >> s;
    }
    vector<vector<bool>> st(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
      if (g[i][0] == 'L') {
        st[i][0] = true;
      }
      if (g[i][m - 1] == 'R') {
        st[i][m - 1] = true;
      }
    }
    for (int j = 0; j < m; j++) {
      if (g[0][j] == 'U') {
        st[0][j] = true;
      }
      if (g[n - 1][j] == 'D') {
        st[n - 1][j] = true;
      }
    }
    vector<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (st[i][j]) {
          q.emplace_back(make_pair(i, j));
        }
      }
    }
    map<char, pair<int, int>> mp;
    mp['L'] = make_pair(0, -1);
    mp['R'] = make_pair(0, 1);
    mp['U'] = make_pair(-1, 0);
    mp['D'] = make_pair(1, 0);
    const int dx[4] = {0, 0, -1, 1};
    const int dy[4] = {1, -1, 0, 0};
    for (int qq = 0; qq < (int) q.size(); qq++) {
      auto [x, y] = q[qq];
      debug(x, y);
      for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx < 0 || ty < 0 || tx >= n || ty >= m) {
          continue;
        }
        if (st[tx][ty] || g[tx][ty] == '?') {
          continue;
        }
        auto [zx, zy] = mp[g[tx][ty]];
        if (x == zx + tx && y == zy + ty) {
          st[tx][ty] = true;
          q.emplace_back(make_pair(tx, ty));
        }
      }
    }
    /*
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << st[i][j] << " \n"[j == m - 1];
      }
    }
    */
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (g[i][j] == '?') {
          bool ok = false;
          for (int k = 0; k < 4; k++) {
            int ti = i + dx[k];
            int tj = j + dy[k];
            if (ti < 0 || tj < 0 || ti >= n || tj >= m) {
              continue;
            }
            ok |= (!st[ti][tj]);
          }
          if (!ok) {
            st[i][j] = true;
          }
        }
      }
    }
    int ans = n * m;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (st[i][j]) {
          ans -= 1;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
