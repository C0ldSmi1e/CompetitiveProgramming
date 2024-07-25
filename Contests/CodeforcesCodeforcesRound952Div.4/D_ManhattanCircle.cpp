/**
 * Author: C0ldSmi1e
 * Created Time: 06/11/2024 08:27:16 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1985/problem/D
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
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto& s : g) {
      cin >> s;
    }
    int x1 = n;
    int y1 = m;
    int x2 = -1;
    int y2 = -1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (g[i][j] == '#') {
          x1 = min(x1, i);
          y1 = min(y1, j);
          x2 = max(x2, i);
          y2 = max(y2, j);
        }
      }
    }
    cout << (x1 + x2) / 2 + 1 << ' ' << (y1 + y2) / 2 + 1 << '\n';
  }
  return 0;
}
