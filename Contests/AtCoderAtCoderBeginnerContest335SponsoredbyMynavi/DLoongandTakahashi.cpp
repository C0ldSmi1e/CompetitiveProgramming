/**
 * Author: C0ldSmi1e
 * Created Time: 01/07/2024 11:44:38 AM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc335/tasks/abc335_d
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
  vector<vector<int>> g(n, vector<int>(n, -1));
  g[n / 2][n / 2] = 0;
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  int i = 0;
  int x = 0, y = 0;
  int t = 1;
  while (g[x][y] != 0) {
    g[x][y] = t++;
    x += dx[i];
    y += dy[i];
    if (x < 0 || y < 0 || x >= n || y >= n || g[x][y] != -1) {
      x -= dx[i];
      y -= dy[i];
      i = (i + 1) % 4;
      x += dx[i];
      y += dy[i];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (g[i][j] == 0) {
        cout << 'T';
      } else {
        cout << g[i][j];
      }
      cout << " \n"[j == n - 1];
    }
  }
  return 0;
}
