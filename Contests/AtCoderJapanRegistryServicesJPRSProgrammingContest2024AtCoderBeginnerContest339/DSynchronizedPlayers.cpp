/**
 * Author: C0ldSmi1e
 * Created Time: 02/05/2024 10:16:57 PM
**/

// time-limit: 4000
// problem-url: https://atcoder.jp/contests/abc339/tasks/abc339_d
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
  vector<string> g(n);
  for (auto& s : g) {
    cin >> s;
  }
  int x1 = -1;
  int y1 = -1;
  int x2 = -1;
  int y2 = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (g[i][j] == 'P') {
        if (x1 == -1) {
          x1 = i;
          y1 = j;
        } else {
          x2 = i;
          y2 = j;
        }
      }
    }
  }
  vector<vector<vector<vector<int>>>> dist(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1))));
  dist[x1][y1][x2][y2] = 0;
  dist[x2][y2][x1][y1] = 0;
  vector<array<int, 4>> q{{x1, y1, x2, y2}, {x2, y2, x1, y1}};
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, 1, -1};
  bool flag = false;
  for (int qq = 0; qq < (int) q.size() && !flag; qq++) {
    auto [x1, y1, x2, y2] = q[qq];
    if (x1 == x2 && y1 == y2) {
      cout << dist[x1][y1][x2][y2] << '\n';
      flag = true;
      break;
    }
    for (int i = 0; i < 4; i++) {
      int tx1 = x1 + dx[i];
      int ty1 = y1 + dy[i];
      int tx2 = x2 + dx[i];
      int ty2 = y2 + dy[i];
      if (tx1 < 0 || ty1 < 0 || tx1 >= n || ty1 >= n || g[tx1][ty1] == '#') {
        tx1 -= dx[i];
        ty1 -= dy[i];
      }
      if (tx2 < 0 || ty2 < 0 || tx2 >= n || ty2 >= n || g[tx2][ty2] == '#') {
        tx2 -= dx[i];
        ty2 -= dy[i];
      }
      array<int, 4> t = {tx1, ty1, tx2, ty2};
      if (dist[tx1][ty1][tx2][ty2] == -1) {
        dist[tx1][ty1][tx2][ty2] = dist[x1][y1][x2][y2] + 1;
        q.emplace_back(t);
      }
      swap(t[0], t[2]);
      swap(t[1], t[3]);
      if (dist[tx1][ty1][tx2][ty2] == -1) {
        dist[tx1][ty1][tx2][ty2] = dist[x1][y1][x2][y2] + 1;
        q.emplace_back(t);
      }
    }
  }
  if (!flag) {
    cout << "-1\n";
  }
  return 0;
}
