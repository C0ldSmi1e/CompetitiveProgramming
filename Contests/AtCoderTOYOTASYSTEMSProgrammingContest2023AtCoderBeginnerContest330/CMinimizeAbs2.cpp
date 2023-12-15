/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-26 10:45:46
**/

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc330/tasks/abc330_c
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

  long long d;
  cin >> d;
  long long t = sqrt(d) + 1;
  long long res = (long long) 1e18;
  while (t > 0) {
    long long r = d - t * t;
    r = max(0ll, r);
    long long tt = sqrt(r);
    res = min(res, abs(d - t * t - tt * tt));
    tt += 1;
    res = min(res, abs(d - t * t - tt * tt));
    t -= 1;
  }
  cout << res << '\n';
  return 0;
}
