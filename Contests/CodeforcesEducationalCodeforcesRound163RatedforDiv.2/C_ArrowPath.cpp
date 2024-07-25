/**
 * Author: C0ldSmi1e
 * Created Time: 03/15/2024 07:58:24 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1948/problem/C
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
    int n = 2, m;
    cin >> m;
    vector<string> g(n);
    for (auto& s : g) {
      cin >> s;
    }
    const int INF = (int) 1e9;
    vector<vector<int>> dist(n, vector<int>(m, INF));
    vector<pair<int, int>> q{{0, 0}};
    dist[0][0] = 0;
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
    for (int qq = 0; qq < (int) q.size(); qq++) {
      auto [x, y] = q[qq];
      for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx < 0 || ty < 0 || tx >= n || ty >= m) {
          continue;
        }
        int txx = tx, tyy = ty;
        if (g[tx][ty] == '>') {
          tyy += 1;
        } else {
          tyy -= 1;
        }
        if (dist[txx][tyy] > dist[x][y] + 2) {
          dist[txx][tyy] = dist[x][y] + 2;
          q.emplace_back(txx, tyy);
        }
      }
    }
    cout << (dist[n - 1][m - 1] == INF ? "NO\n" : "YES\n");
  }
  return 0;
}
