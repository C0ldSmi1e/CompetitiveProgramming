/**
 * Author: C0ldSmi1e
 * Created Time: 02/29/2024 06:41:40 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1937/problem/B
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
    int n = 2, m;
    cin >> m;
    vector<string> g(n);
    for (auto& s : g) {
      cin >> s;
    }
    string mn;
    int j = -1;
    for (int i = 0; i < m; i++) {
      mn += g[0][i];
      if (i + 1 >= m || g[0][i + 1] > g[1][i]) {
        mn += g[1].substr(i);
        j = i;
        break;
      }
    }
    cout << mn << '\n';
    int ans = 1;
    for (int i = j; i > 0; i--) {
      if (g[0][i] == g[1][i - 1]) {
        ans += 1;
      } else {
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
