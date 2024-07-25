/**
 * Author: C0ldSmi1e
 * Created Time: 03/12/2024 10:19:14 PM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1941/problem/D
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
    int n, m, x;
    cin >> n >> m >> x;
    --x;
    vector<bool> dp(n, false);
    dp[x] = true;
    for (int i = 0; i < m; i++) {
      int d;
      cin >> d;
      char dir;
      cin >> dir;
      vector<bool> ndp(n);
      for (int i = 0; i < n; i++) {
        if (!dp[i]) {
          continue;
        }
        if (dir == '0') {
          ndp[(i + d) % n] = true;
        }
        if (dir == '1') {
          ndp[(i - d + n) % n] = true;
        }
        if (dir == '?') {
          ndp[(i + d) % n] = true;
          ndp[(i - d + n) % n] = true;
        }
      }
      swap(dp, ndp);
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (dp[i]) {
        ans.emplace_back(i + 1);
      }
    }
    cout << (int) ans.size() << '\n';
    for (auto& u : ans) {
      cout << u << ' ';
    }
    cout << '\n';
  }
  return 0;
}
