/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-27 06:45:11
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START114A/problems/EVEMATRIX
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
    if (n == 1) {
      cout << "1\n";
      continue;
    }
    if (n == 2) {
      cout << "-1\n";
      continue;
    }
    if (n == 3) {
      cout << "1 2 4\n";
      cout << "6 8 3\n";
      cout << "5 7 9\n";
      continue;
    }
    vector<vector<int>> g(n, vector<int>(n));
    int tot = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i >= j) {
          g[i][j] = 1;
          tot += 1;
        }
      }
    }
    tot -= n * n / 2 + (n & 1);
    if (tot & 1) {
      for (int j = 2; j < n; j++) {
        for (int i = 2; i < n; i++) {
          if (tot > 3 && j + 1 <= i && g[i][j] && g[i][j + 1]) {
            g[i][j] = g[i][j + 1] = 0;
            tot -= 2;
          }
        }
      }
      debug(tot);
      assert(tot == 3);
      for (int j = n - 2; j > 1; j--) {
        if (g[n - 2][j] && g[n - 1][j] && g[n - 2][0]) {
          tot -= 3;
          g[n - 2][j] = g[n - 1][j] = g[n - 2][0] = 0;
          break;
        }
      }
    } else {
      for (int j = 2; j < n; j++) {
        for (int i = 2; i < n; i++) {
          if (tot > 0 && j + 1 <= i && g[i][j] && g[i][j + 1]) {
            g[i][j] = g[i][j + 1] = 0;
            tot -= 2;
          }
        }
      }
    }
    int o = 1;
    int e = 2;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (g[i][j] & 1) {
          g[i][j] = o;
          o += 2;
        } else {
          g[i][j] = e;
          e += 2;
        }
        cout << g[i][j] << " \n"[j == n - 1];
      }
    }
  }
  return 0;
}

