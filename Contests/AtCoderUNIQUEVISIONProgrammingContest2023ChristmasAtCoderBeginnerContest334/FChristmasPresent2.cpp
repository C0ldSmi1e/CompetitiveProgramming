/**
 * Author: C0ldSmi1e
 * Created Time: 2023-12-26 21:29:39
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc334/tasks/abc334_f
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(15);

  int n, k;
  cin >> n >> k;
  int sx, sy;
  cin >> sx >> sy;
  vector<int> x(n);
  vector<int> y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  vector<double> b(n);
  auto Get = [&](int x1, int y1, int x2, int y2) -> double {
    double dx = 1.0 * x1 - x2;
    double dy = 1.0 * y1 - y2;
    return sqrt(dx * dx + dy * dy);
  };
  for (int i = 0; i < n; i++) {
    b[i] = Get(sx, sy, x[i], y[i]);
  }
  vector<double> pref(n + 1);
  for (int i = 1; i < n; i++) {
    pref[i + 1] = pref[i] + Get(x[i], y[i], x[i - 1], y[i - 1]);
  }
  vector<double> dp(n + 1, 8e18);
  dp[0] = 0;
  int tt = -1, hh = 0;
  vector<int> q(n + 10);
  q[++tt] = 0;
  for (int i = 1; i <= n; i++) {
    while (hh <= tt && i - q[hh] > k) {
      ++hh;
    }
    dp[i] = dp[q[hh]] + b[q[hh]] - pref[q[hh] + 1] + b[i - 1] + pref[i];
    while (hh <= tt && dp[i] + (i < n ? b[i] : 0) - (i + 1 <= n ? pref[i + 1] : 0) <= dp[q[tt]] + b[q[tt]] - pref[q[tt] + 1]) {
      --tt;
    }
    q[++tt] = i;
    //for (int k = hh; k <= tt; k++) {
    //  cout << q[k] << " \n"[k == tt];
    //}
  }
  cout << dp[n] << '\n';
  return 0;
}
