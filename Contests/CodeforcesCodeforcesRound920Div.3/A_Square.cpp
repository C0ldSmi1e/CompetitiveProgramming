/**
 * Author: C0ldSmi1e
 * Created Time: 01/15/2024 06:37:00 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1921/problem/A
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
    int x1 = 1001, x2 = 1001, y1 = 1001, y2 = 1001;
    for (int i = 0; i < 4; i++) {
      int x, y;
      cin >> x >> y;
      if (x1 == 1001 || x1 == x) {
        x1 = x;
      } else {
        x2 = x;
      }
      if (y1 == 1001 || y1 == y) {
        y1 = y;
      } else {
        y2 = y;
      }
    }
    debug(x1, x2, y1, y2);
    cout << abs(x1 - x2) * abs(y1 - y2) << '\n';
  }
  return 0;
}
