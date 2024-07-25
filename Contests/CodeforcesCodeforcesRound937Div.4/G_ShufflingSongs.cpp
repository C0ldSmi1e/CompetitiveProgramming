/**
 * Author: C0ldSmi1e
 * Created Time: 03/28/2024 08:29:10 AM
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1950/problem/G
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
    map<string, int> mp;
    int m = 0;
    vector<pair<int, int>> a(n);
    for (auto& [x, y] : a) {
      string s;
      cin >> s;
      if (!mp.count(s)) {
        mp[s] = m++;
      }
      x = mp[s];
      cin >> s;
      if (!mp.count(s)) {
        mp[s] = m++;
      }
      y = mp[s];
    }
    vector<vector<bool>> dp(1 << n, vector<bool>(n));
    for (int bit = 0; bit < n; bit++) {
      dp[1 << bit][bit] = true;
    }
    auto Check = [&](int i, int j) -> bool {
      if (a[i].first != a[j].first && a[i].second != a[j].second) {
        return false;
      }
      return true;
    };
    for (int mask = 0; mask < 1 << n; mask++) {
      for (int lst = 0; lst < n; lst++) {
        if (dp[mask][lst] && ((mask >> lst) & 1)) {
          for (int nxt = 0; nxt < n; nxt++) {
            if (((mask >> nxt) & 1) == 0 && Check(lst, nxt)) {
              dp[mask | (1 << nxt)][nxt] = true;
            }
          }
        }
      }
    }
    int ans = n;
    for (int mask = 0; mask < 1 << n; mask++) {
      for (int bit = 0; bit < n; bit++) {
        if (dp[mask][bit]) {
          debug(mask, bit);
          ans = min(ans, n - __builtin_popcount(mask));
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
