/**
 * Author: C0ldSmi1e
 * Created Time: 02/02/2024 08:14:20 PM
**/

// time-limit: 4000
// problem-url: https://codeforces.com/contest/1918/problem/D
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
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + a[i];
    }
    const long long INF = (long long) 1e18;
    long long l = *max_element(a.begin(), a.end());
    long long r = INF;
    auto Check = [&](long long x) -> bool {
      vector<vector<long long>> dp(n + 1, vector<long long>(2, INF));
      dp[0][1] = 0;
      int hh = 0, tt = 0;
      vector<int> q(n + 1);
      for (int i = 1; i <= n; i++) {
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + a[i - 1];
        while (hh <= tt && pref[i] - pref[q[hh]] > x) {
          hh += 1;
        }
        dp[i][0] = dp[q[hh]][1];
        while (hh <= tt && dp[i][1] <= dp[q[tt]][1]) {
          tt -= 1;
        }
        q[++tt] = i;
      }
      return min(dp[n][0], dp[n][1]) <= x;
    };
    while (l < r) {
      long long mid = (l + r) >> 1;
      if (Check(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    cout << r << '\n';
  }
  return 0;
}
