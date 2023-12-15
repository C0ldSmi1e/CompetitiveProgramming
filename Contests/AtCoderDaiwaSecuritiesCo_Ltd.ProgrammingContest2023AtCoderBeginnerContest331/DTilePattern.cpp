/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-02 14:05:28
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc331/tasks/abc331_d
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

  int n, q;
  cin >> n >> q;
  vector<string> g(n);
  for (auto& s : g) {
    cin >> s;
  }
  vector<vector<int>> pref(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      pref[i][j] = (int) (g[i - 1][j - 1] == 'B');
      pref[i][j] += pref[i - 1][j];
      pref[i][j] += pref[i][j - 1];
      pref[i][j] -= pref[i - 1][j - 1];
      //cout << pref[i][j] << " \n"[j == n];
    }
  }
  auto Get = [&](int x1, int y1, int x2, int y2) -> int {
    x1 += 1;
    y1 += 1;
    x2 += 1;
    y2 += 1;
    if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= n && x2 >= 1 && x2 <= n && y2 >= 1 && y2 <= n) {
      return pref[x2][y2] + pref[x1 - 1][y1 - 1] - pref[x1 - 1][y2] - pref[x2][y1 - 1];
    }
    return 0;
  };
  while (q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int xl = (n - y1 % n) % n;
    int xr = (y2 % n + 1) % n;
    int yt = (n - x1 % n) % n;
    int yb = (x2 % n + 1) % n;
    int full_x = (y2 - y1 + 1 - xl - xr) / n;
    int full_y = (x2 - x1 + 1 - yt - yb) / n;
    x1 %= n;
    y1 %= n;
    x2 %= n;
    y2 %= n;
    long long res = 1ll * full_x * full_y * pref[n][n];
    // top-left
    res += Get(x1, y1, x1 + yt - 1, y1 + xl - 1);
    // bottom-left
    res += Get(x2 - yb + 1, y1, x2, y1 + xl - 1);
    // bottom-right
    res += Get(x2 - yb + 1, y2 - xr + 1, x2, y2);
    // top-right
    res += Get(x1, y2 - xr + 1, x1 + yt - 1, y2);
    // top
    if (yt > 0) {
      res += 1ll * Get(x1, 0, n - 1, n - 1) * full_x;
    }
    // bottom
    if (yb > 0) {
      res += 1ll * Get(0, 0, yb - 1, n - 1) * full_x;
    }
    // left
    if (xl > 0) {
      res += 1ll * Get(0, y1, n - 1, n - 1) * full_y;
    }
    // right
    if (xr > 0) {
      res += 1ll * Get(0, 0, n - 1, xr - 1) * full_y;
    }
    cout << res << '\n';
  }
  return 0;
}
