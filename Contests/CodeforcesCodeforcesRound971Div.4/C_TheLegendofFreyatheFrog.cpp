/**
 * Author: C0ldSmi1e
 * Created Time: 10/04/2024 10:38:51 PM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/2009/problem/C
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
    int x, y, k;
    cin >> x >> y >> k;
    long long ans = 0;
    if (y >= x) {
      int t = (x + k - 1) / k;
      ans = t + t - 1;
      y -= 1ll * (t - 1) * k;
      ans += (y + k - 1) / k * 2 - 1;
    } else {
      int t = (y + k - 1) / k;
      ans = t + t;
      x -= t * k;
      x = max(0, x);
      ans += x > 0 ? (x + k - 1) / k * 2 - 1 : 0;
    }
    cout << ans << '\n';
  }
  return 0;
}
