/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-26 10:55:05
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc330/tasks/abc330_d
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
  vector<vector<int>> pref_row(n, vector<int>(n));
  vector<vector<int>> pref_col(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      pref_row[i][j] = (int) (g[i][j] == 'o');
      pref_col[i][j] = (int) (g[i][j] == 'o');
      if (j > 0) {
        pref_row[i][j] += pref_row[i][j - 1];
      }
      if (i > 0) {
        pref_col[i][j] += pref_col[i - 1][j];
      }
    }
  }
  long long res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (g[i][j] == 'o') {
        if (i - 1 >= 0 && j - 1 >= 0) {
          res += pref_row[i][j - 1] * pref_col[i - 1][j];
        }
        if (i - 1 >= 0 && j + 1 < n) {
          res += (pref_row[i][n - 1] - pref_row[i][j]) * pref_col[i - 1][j];
        }
        if (i + 1 < n && j - 1 >= 0) {
          res += pref_row[i][j - 1] * (pref_col[n - 1][j] - pref_col[i][j]);
        }
        if (i + 1 < n && j + 1 < n) {
          res += (pref_row[i][n - 1] - pref_row[i][j]) * (pref_col[n - 1][j] - pref_col[i][j]);
        }
      }
    }
  }
  cout << res << '\n';
  return 0;
}
