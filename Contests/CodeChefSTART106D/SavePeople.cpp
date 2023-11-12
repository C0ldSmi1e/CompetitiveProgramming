/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-01 08:36:51
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START106D/problems/FIZZBUZZ2306
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

  int T;
  cin >> T;
  while (T--) {
    long long n, m;
    cin >> n >> m;
    long long x, y;
    cin >> x >> y;
    long long res = 0;
    // -0
    res = max(res, (x - 1) * m);
    // +0
    res = max(res, (n - x) * m);
    // 0-
    res = max(res, n * (y - 1));
    // 0+
    res = max(res, n * (m - y));
    cout << res << '\n';
  }
  return 0;
}
