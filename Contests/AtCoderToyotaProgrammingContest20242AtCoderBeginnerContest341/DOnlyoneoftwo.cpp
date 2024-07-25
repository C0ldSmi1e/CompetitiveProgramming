/**
 * Author: C0ldSmi1e
 * Created Time: 03/06/2024 10:33:26 PM
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc341/tasks/abc341_d
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

  long long a, b, k;
  cin >> a >> b >> k;
  long long c = lcm(a, b);
  long long l = 1, r = (long long) 8e18;
  while (l < r) {
    long long mid = (l + r) >> 1;
    if (mid / a + mid / b - 2 * (mid / c) >= k) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  debug(r / a + r / b - r / c);
  cout << r << '\n';
  return 0;
}
