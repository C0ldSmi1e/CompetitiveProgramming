/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-14 14:15:26
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc332/tasks/abc332_e
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

  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (auto& u : a) {
    cin >> u;
  }
  vector<int> b(1 << n);
  for (int mask = 0; mask < 1 << n; mask++) {
    for (int bit = 0; bit < n; bit++) {
      if ((mask >> bit) & 1) {
        b[mask] += a[bit];
      }
    }
  }
  vector<double> dp(1 << n, 1e30);
  dp[0] = 0;
  double D = 1.0 * accumulate(a.begin(), a.end(), 0) / d;
  for (int i = 0; i < d; i++) {
    vector<double> ndp(1 << n, 1e30);
    for (int nxt = 0; nxt < 1 << n; nxt++) {
      ndp[nxt] = dp[0] + (b[nxt] - D) * (b[nxt] - D);
      for (int cur = nxt; cur; cur = (cur - 1) & nxt) {
        int add = (nxt ^ cur);
        ndp[nxt] = min(ndp[nxt], dp[cur] + (b[add] - D) * (b[add] - D));
      }
    }
    swap(dp, ndp);
  }
  cout << dp.back() / d << '\n';
  return 0;
}


