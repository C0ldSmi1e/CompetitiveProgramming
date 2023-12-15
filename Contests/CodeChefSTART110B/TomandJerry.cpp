/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-30 13:15:18
**/

// time-limit: 1000
// problem-url: https://www.codechef.com/START110B/problems/SPCP7
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
    int n, x, y, k;
    cin >> n >> x >> y >> k;
    if (k == n) {
      cout << 1.0 * x / (x + y) * (x + y + n - 1) << '\n';
    } else {
      cout << 1.0 * x / (x + y) * (x + y - 1) << '\n';
    }
  }
  return 0;
}

/*
 * x - x / (x + y), y - y / (x + y)
 * (x(x + y) - x) / (x + y)
 * (x^2 + xy - x) / (y^2 + xy - y)
 * x(x + y - 1) / y(y + x - 1) = x / y
 * x, y, take 2
 * 1. take 0x and 2y
 *    C(x, 0) * C(y, 2) / C(x + y, 2)
 *    (y * (y - 1) / 2) / ((x + y) * (x + y - 1) / 2)
 * 2. take 1x and 1y
 *    C(x, 1) * C(y, 1) / C(x + y, 2)
 *    x * y / ((x + y) * (x + y - 1) / 2)
 * 3. take 2x and 0y
 *    C(x, 2) * C(y, 0) / C(x + y, 2)
 *    (x * (x - 1) / 2) / ((x + y) * (x + y - 1) / 2)
 *  take:
 *    x:
 *      (x * y + (x * (x - 1))) / ((x + y) * (x + y - 1))
 *    y:
 *      (y * x + (y * (y - 1))) / ((x + y) * (x + y - 1))
 *    x : y
 *        xy + x^2 - x : xy + y^2 - y
 *        x(y+x-1)     : y(x+y-1)
*/
