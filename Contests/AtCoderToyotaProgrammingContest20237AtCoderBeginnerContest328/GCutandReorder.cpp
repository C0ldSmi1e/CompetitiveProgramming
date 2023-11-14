/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-12 15:53:52
**/

// time-limit: 2800
// problem-url: https://atcoder.jp/contests/abc328/tasks/abc328_g
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);

  int n;
  long long c;
  cin >> n >> c;
  vector<long long> a(n);
  for (auto& u : a) {
    cin >> u;
  }
  vector<long long> b(n);
  for (auto& u : b) {
    cin >> u;
  }
  const long long INF = (long long) 1e18;
  vector<long long> dp(1 << n, INF);
  dp[0] = 0;
  for (int cur = 0; cur < 1 << n; cur++) {
    for (int l = 0; l < n; l++) {
      if (((cur >> l) & 1) == 0) {
        int r = l;
        int i = (int) __builtin_popcount(cur);
        int nxt = cur;
        long long cost = 0;
        while (r < n) {
          if ((cur >> r) & 1) {
            break;
          }
          nxt |= (1 << r);
          cost += abs(a[r] - b[i]);
          dp[nxt] = min(dp[nxt], dp[cur] + cost + c);
          i += 1;
          r += 1;
        }
      }
    }
  }
  cout << dp.back() - c << '\n';
  return 0;
}
