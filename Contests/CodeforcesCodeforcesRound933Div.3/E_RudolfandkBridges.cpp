/**
 * Author: C0ldSmi1e
 * Created Time: 03/12/2024 10:28:26 PM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1941/problem/E
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
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<long long> cost(n);
    for (int i = 0; i < n; i++) {
      vector<int> a(m);
      for (auto& u : a) {
        cin >> u;
      }
      vector<long long> dp(m);
      dp[0] = 1;
      deque<int> q;
      q.push_back(0);
      for (int j = 1; j < m; j++) {
        while ((int) q.size() > 0 && j - q.front() - 1 > d) {
          q.pop_front();
        }
        dp[j] = dp[q.front()] + a[j] + 1;
        while ((int) q.size() > 0 && dp[j] <= dp[q.back()]) {
          q.pop_back();
        }
        q.push_back(j);
      }
      cost[i] = dp.back();
    }
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + cost[i];
    }
    const long long INF = (long long) 1e18;
    long long ans = INF;
    for (int i = k; i <= n; i++) {
      ans = min(ans, pref[i] - pref[i - k]);
    }
    cout << ans << '\n';
  }
  return 0;
}
