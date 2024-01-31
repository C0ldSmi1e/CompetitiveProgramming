/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-17 11:21:53
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START112B/problems/ARRAYGAME
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
  int t;
  cin >> T >> t;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    sort(a.begin(), a.end());
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + a[i];
    }
    int m = (n + 1) / 2;
    vector<long long> dp(m + 1);
    for (int i = 1; i <= m; i++) {
      // from [n-(2*i-1)+1, n]
      // choose [n-(2*i-1)+1, n-(2*i-1)+i]
      dp[i] = pref[n - (2 * i - 1) + i] - pref[n - (2 * i - 1)];
    }
    if (t == 1) {
      cout << *max_element(dp.begin(), dp.end()) << '\n';
    } else {
      cout << dp[m] << '\n';
    }
  }
  return 0;
}
