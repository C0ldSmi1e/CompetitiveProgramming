/**
 * Author: C0ldSmi1e
 * Created Time: 06/23/2024 07:55:47 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1986/problem/B
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
    for (auto& u : g) {
      for (auto& v : u) {
        cin >> v;
      }
    }
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        bool flag = true;
        int mx = 0;
        for (int k = 0; k < 4; k++) {
          int tx = i + dx[k];
          int ty = j + dy[k];
          if (tx < 0 || ty < 0 || tx >= n || ty >= m) {
            continue;
          }
          flag &= g[i][j] > g[tx][ty];
          mx = max(mx, g[tx][ty]);
        }
        if (flag) {
          g[i][j] = mx;
        }
      }
    }
    for (auto& u : g) {
      for (auto& v : u) {
        cout << v << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}
