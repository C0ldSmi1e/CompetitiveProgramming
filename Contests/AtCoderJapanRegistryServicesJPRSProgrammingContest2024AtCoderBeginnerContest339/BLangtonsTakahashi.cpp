/**
 * Author: C0ldSmi1e
 * Created Time: 02/05/2024 03:06:25 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc339/tasks/abc339_b
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

  int n, m, k;
  cin >> n >> m >> k;
  vector<string> g(n, string(m, '.'));
  int x = 0, y = 0;
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};
  int dir = 0;
  while (k--) {
    assert(x >= 0 && x < n);
    assert(y >= 0 && y < m);
    if (g[x][y] == '.') {
      g[x][y] = '#';
      dir = (dir + 1) % 4;
    } else {
      g[x][y] = '.';
      dir = (dir - 1 + 4) % 4;
    }
    x = (x + dx[dir] + n) % n;
    y = (y + dy[dir] + m) % m;
  }
  for (auto& s : g) {
    cout << s << '\n';
  }
  return 0;
}
