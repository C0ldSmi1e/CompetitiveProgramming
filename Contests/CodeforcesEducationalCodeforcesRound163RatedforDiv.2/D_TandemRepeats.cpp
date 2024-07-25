/**
 * Author: C0ldSmi1e
 * Created Time: 03/15/2024 08:06:04 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1948/problem/D
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
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<vector<bool>> g(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (s[i] == s[j] || s[i] == '?' || s[j] == '?') {
          g[i][j - i] = true;
        }
      }
    }
    int ans = 0;
    for (int x = 0; x < n; x++) {
      vector<int> b(n, -1);
      for (int i = 0; i < n; i++) {
        if (g[i][x]) {
          b[i] = x;
        }
      }
      for (int i = 0; i < n; i++) {
        if (b[i] == -1) {
          continue;
        }
        int j = i;
        while (j < n && b[j] == x) {
          j += 1;
        }
        if (j - i >= x) {
          ans = max(ans, 2 * x);
        }
        i = j;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
