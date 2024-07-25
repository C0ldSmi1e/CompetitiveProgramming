/**
 * Author: C0ldSmi1e
 * Created Time: 03/28/2024 07:48:49 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1950/problem/B
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
    vector<string> g(2 * n, string(2 * n, '#'));
    for (int i = 0; i < 2 * n; i += 2) {
      for (int j = 0; j < 2 * n; j += 2) {
        int t = ((i / 2 + j / 2) & 1);
        g[i][j] = g[i + 1][j] = g[i][j + 1] = g[i + 1][j + 1] = (t ? '.' : '#');
      }
    }
    for (auto& s : g) {
      cout << s << '\n';
    }
  }
  return 0;
}
