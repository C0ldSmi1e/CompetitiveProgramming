/**
 * Author: C0ldSmi1e
 * Created Time: 01/21/2024 10:28:00 AM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc337/tasks/abc337_d
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

  int n, m, x;
  cin >> n >> m >> x;
  vector<string> g(n);
  for (auto& s : g) {
    cin >> s;
  }
  int res = n * m + 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int k = j;
      while (k < m && g[i][k] != 'x') {
        k += 1;
      }
      int cnt = 0;
      for (int l = 0; l < k - j; l++) {
        cnt += (int) (g[i][j + l] == '.');
        assert(g[i][j + l] != 'x');
        if (l >= x - 1) {
          res = min(res, cnt);
          cnt -= (int) (g[i][j + l - x + 1] == '.');
        }
      }
      j = k;
    }
  }
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      int k = i;
      while (k < n && g[k][j] != 'x') {
        k += 1;
      }
      int cnt = 0;
      for (int l = 0; l < k - i; l++) {
        cnt += (int) (g[i + l][j] == '.');
        assert(g[i + l][j] != 'x');
        if (l >= x - 1) {
          res = min(res, cnt);
          cnt -= (int) (g[i + l - x + 1][j] == '.');
        }
      }
      i = k;
    }
  }
  if (res == n * m + 1) {
    res = -1;
  }
  cout << res << '\n';
  return 0;
}
