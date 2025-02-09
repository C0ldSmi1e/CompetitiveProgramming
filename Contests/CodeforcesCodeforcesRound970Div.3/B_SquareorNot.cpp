/**
 * Author: C0ldSmi1e
 * Created Time: 09/01/2024 07:51:46 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/2008/problem/B
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m = 1;
    while (m * m < n) {
      m += 1;
    }
    if (m * m != n) {
      cout << "NO\n";
      continue;
    }
    vector<vector<int>> g(m, vector<int>(m));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        g[i][j] = (int) (s[i * m + j] - '0');
      }
    }
    bool flag = true;
    debug(g);
    for (int i = 0; i < m; i++) {
      flag &= (g[i][0] == 1);
      flag &= (g[i][m - 1] == 1);
    }
    for (int j = 0; j < m; j++) {
      flag &= (g[0][j] == 1);
      flag &= (g[m - 1][j] == 1);
    }
    for (int i = 1; i < m - 1; i++) {
      for (int j = 1; j < m - 1; j++) {
        flag &= (g[i][j] == 0);
      }
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
