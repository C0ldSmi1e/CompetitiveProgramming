/**
 * Author: C0ldSmi1e
 * Created Time: 01/14/2024 11:27:04 PM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1917/problem/E
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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n, vector<int>(n));
    auto Print = [&]() -> void {
      for (auto& u : g) {
        for (auto& v : u) {
          cout << v << ' ';
        }
        cout << '\n';
      }
    };
    if (k & 1) {
      cout << "No\n";
      continue;
    }
    if (n == 2) {
      cout << "Yes\n";
      if (k == 0) {
        cout << "0 0\n0 0\n";
      }
      if (k == 2) {
        cout << "1 0\n0 1\n";
      }
      if (k == 4) {
        cout << "1 1\n1 1\n";
      }
      continue;
    }
    if (k % 4 == 0) {
      cout << "Yes\n";
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (k > 0 && g[i][j] == 0) {
            g[i][j] = g[i][j + 1] = g[i + 1][j] = g[i + 1][j + 1] = 1;
            k -= 4;
          }
        }
      }
      Print();
      continue;
    }
    if (k == 2 || k == n * n - 2) {
      cout << "No\n";
      continue;
    }
    if (k % 4 == 2) {
      if (k == n * n - 6) {
        g[0][0] = g[0][1] = g[1][0] = g[1][2] = g[2][1] = g[2][2] = 1;
        g[0][2] = g[0][3] = g[3][2] = g[3][3] = 1;
        k -= 10;
      } else {
        g[0][0] = g[0][1] = g[1][0] = g[1][2] = g[2][1] = g[2][2] = 1;
        k -= 6;
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (k > 0 && i + 1 < n && j + 1 < n && g[i][j] + g[i + 1][j] + g[i][j + 1] + g[i + 1][j + 1] == 0) {
            g[i][j] = g[i + 1][j] = g[i][j + 1] = g[i + 1][j + 1] = 1;
            k -= 4;
          }
        }
      }
      cout << "Yes\n";
      Print();
      continue;
    }
    cout << "No\n";
  }
  return 0;
}
