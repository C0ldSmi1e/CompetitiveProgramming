/**
 * Author: C0ldSmi1e
 * Created Time: 05/02/2024 08:29:40 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1968/problem/E
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
    vector<vector<int>> g(n, vector<int>(n));
    for (int j = 0; j < 2; j++) {
      g[0][j] = 1;
    }
    for (int i = 0, j = n - 1; i < n - 2; i++, j--) {
      g[j][j] = 1;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (g[i][j] != 0) {
          cout << i + 1 << ' ' << j + 1 << '\n';
        }
      }
    }
    cout << '\n';
  }
  return 0;
}
