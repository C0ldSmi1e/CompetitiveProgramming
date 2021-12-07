#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<vector<long long>>> f(n, vector<vector<long long>>(m, vector<long long>(2)));
  long long res = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      f[i][j][0] = f[i][j][1] = 1;
      if (i + 1 < n) {
        f[i][j][0] += f[i + 1][j][1];
      }
      if (j + 1 < m) {
        f[i][j][1] += f[i][j + 1][0];
      }
      res += f[i][j][0] + f[i][j][1] - 1;
    }
  }
  vector<vector<int>> st(n, vector<int>(m, 1));
  auto go = [&](int x, int y, int dx, int dy) -> long long {
    int cnt = 0;
    while (true) {
      x += dx;
      y += dy;
      if (x < 0 || y < 0 || x >= n || y >= m || st[x][y] == -1) {
        break;
      }
      ++cnt;
      swap(dx, dy);
    }
    return cnt;
  };
  while (q--) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    long long t = 0;
    {
      long long c1 = go(x, y, -1, 0);
      long long c2 = go(x, y, 0, 1);
      t += (c1 + 1) * (c2 + 1) - 1;
    }
    {
      long long c1 = go(x, y, 0, -1);
      long long c2 = go(x, y, 1, 0);
      t += (c1 + 1) * (c2 + 1) - 1;
    }
    res -= st[x][y] * t;
    res -= st[x][y];
    st[x][y] *= -1;
    cout << res << '\n';
  }
  return 0;
}
