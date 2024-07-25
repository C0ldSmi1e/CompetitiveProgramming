/**
 * Author: C0ldSmi1e
 * Created Time: 02/27/2024 08:05:01 AM
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1933/problem/F
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
    vector<vector<int>> g(n, vector<int>(m));
    vector<set<int>> S(m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> g[i][j];
      }
    }
    vector<pair<int, int>> q{{0, 0}};
    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[0][0] = 0;
    for (int qq = 0; qq < (int) q.size(); qq++) {
      auto [x, y] = q[qq];
      {
        int tx = (x + 1) % n;
        int ty = y + 1;
        if (ty < m && g[tx][ty] == 0 && dist[tx][ty] == -1) {
          dist[tx][ty] = dist[x][y] + 1;
          q.emplace_back(tx, ty);
        }
      }
      {
        if (g[(x + 1) % n][y] == 0 && g[(x + 2) % n][y] == 0 && dist[(x + 2) % n][y] == -1) {
          dist[(x + 2) % n][y] = dist[x][y] + 1;
          q.emplace_back((x + 2) % n, y);
        }
      }
    }
    //for (int i = 0; i < n; i++) {
    //  for (int j = 0; j < m; j++) {
    //    cout << dist[i][j] << " \n"[j == m - 1];
    //  }
    //}
    int ans = -1;
    for (int i = 0; i < n; i++) {
      int res = dist[i][m - 1];
      if (res != -1) {
        int d = res % n;
        int cur = (i - d + n) % n;
        res += (cur + 1) % n;
        if (ans == -1 || ans > res) {
          ans = res;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
