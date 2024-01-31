/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-19 06:48:52
**/

// time-limit: 2500
// problem-url: https://codeforces.com/contest/1914/problem/C
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& u : a) {
      cin >> u;
    }
    vector<int> b(n);
    for (auto& u : b) {
      cin >> u;
    }
    vector<long long> dp(n);
    for (int i = 0; i < n; i++) {
      if (k >= i + 1) {
        dp[i] = a[i];
        if (i > 0) {
          dp[i] += dp[i - 1];
        }
      }
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
      mx = max(mx, b[i]);
      dp[i] += 1ll * max(0, k - i - 1) * mx;
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
  }
  return 0;
}
