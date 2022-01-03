#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int m, k;
  cin >> m >> k;
  int n = 2 * k;
  vector<vector<vector<int>>> pre(2, vector<vector<int>>(n + 1, vector<int>(n + 1)));
  for (int i = 0; i < m; i++) {
    int x, y;
    char c;
    cin >> x >> y >> c;
    x %= n;
    y %= n;
    pre[(c == 'W' ? 0 : 1)][x + 1][y + 1] += 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      pre[0][i][j] += pre[0][i - 1][j] + pre[0][i][j - 1] - pre[0][i - 1][j - 1];
      pre[1][i][j] += pre[1][i - 1][j] + pre[1][i][j - 1] - pre[1][i - 1][j - 1];
    }
  }
  auto Get = [&](int c, int x1, int y1, int x2, int y2) -> int {
    if (x1 >= 1 && x1 <= x2 && x2 <= n && y1 >= 1 && y1 <= y2 && y2 <= n) {
      return pre[c][x2][y2] - pre[c][x1 - 1][y2] - pre[c][x2][y1 - 1] + pre[c][x1 - 1][y1 - 1];
    }
    return 0;
  };
  int res = 0;
  for (int x2 = k; x2 <= n; x2++) {
    for (int y2 = k; y2 <= n; y2++) {
      int ans = 0;
      int x1 = x2 - k + 1;
      int y1 = y2 - k + 1;
      ans += Get(0, x1, y1, x2, y2);
      ans += Get(0, 1, 1, x1 - 1, y1 - 1);
      ans += Get(0, 1, y2 + 1, x1 - 1, n);
      ans += Get(0, x2 + 1, y2 + 1, n, n);
      ans += Get(0, x2 + 1, 1, n, y1 - 1);
      ans += Get(1, x1, 1, x2, y1 - 1);
      ans += Get(1, 1, y1, x1 - 1, y2);
      ans += Get(1, x1, y2 + 1, x2, n);
      ans += Get(1, x2 + 1, y1, n, y2);
      res = max(res, ans);
      res = max(res, m - ans);
    }
  }
  cout << res << '\n';
  return 0;
}
