/**
 * Author: C0ldSmi1e
 * Created Time: 03/19/2024 09:16:47 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1945/problem/D
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
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    vector<int> b(n);
    for (auto& u : b) {
      cin >> u;
    }
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + b[i];
    }
    const long long INF = (long long) 1e18;
    vector<long long> dp(n + 1, INF);
    dp[n] = 0;
    long long mn = dp[n] + pref[n];
    for (int i = n - 1; i >= 0; i--) {
      dp[i] = mn + a[i] - pref[i + 1];
      mn = min(mn, dp[i] + pref[i]);
    }
    long long ans = INF;
    for (int i = 0; i < m; i++) {
      ans = min(ans, dp[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}
