/**
 * Author: C0ldSmi1e
 * Created Time: 03/06/2024 10:07:15 PM
**/

// time-limit: 3000
// problem-url: https://atcoder.jp/contests/abc341/tasks/abc341_c
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

  int n, m, sz;
  cin >> n >> m >> sz;
  string s;
  cin >> s;
  vector<string> g(n);
  for (auto& s : g) {
    cin >> s;
  }
  int ans = 0;
  auto Dfs = [&](auto& self, int x, int y, int k) -> bool {
    if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#') {
      return false;
    }
    debug(x, y, k);
    if (k >= sz) {
      return true;
    }
    if (s[k] == 'U') {
      if (self(self, x - 1, y, k + 1)) {
        return true;
      }
    }
    if (s[k] == 'D') {
      if (self(self, x + 1, y, k + 1)) {
        return true;
      }
    }
    if (s[k] == 'L') {
      if (self(self, x, y - 1, k + 1)) {
        return true;
      }
    }
    if (s[k] == 'R') {
      if (self(self, x, y + 1, k + 1)) {
        return true;
      }
    }
    return false;
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (Dfs(Dfs, i, j, 0)) {
        ans += 1;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
