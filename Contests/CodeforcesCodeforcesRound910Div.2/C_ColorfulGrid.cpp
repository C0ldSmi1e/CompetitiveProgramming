/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-20 20:35:47
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1898/problem/C
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
    int n, m, k;
    cin >> n >> m >> k;
    int tot = n - 1 + m - 1;
    if (k < tot || k % 2 != tot % 2) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    vector<vector<int>> x(n, vector<int>(m - 1));
    vector<vector<int>> y(n - 1, vector<int>(m));
    x[1][1] = 1;
    x[2][1] = 1;
    y[1][1] = 0;
    x[0][1] = 1;
    int last = 1;
    for (int i = 0; i < n - 1; i++) {
      y[i][2] = (last ^ 1);
      last ^= 1;
    }
    for (int j = 2; j < m - 1; j++) {
      x[n - 1][j] = (last ^ 1);
      last ^= 1;
    }
    for (auto& u : x) {
      for (auto& v : u) {
        cout << (v == 0 ? 'R' : 'B') << ' ';
      }
      cout << '\n';
    }
    for (auto& u : y) {
      for (auto& v : u) {
        cout << (v == 0 ? 'R' : 'B') << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}
