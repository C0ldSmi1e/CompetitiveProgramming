/**
 * Author: C0ldSmi1e
 * Created Time: 2023-11-03 07:39:30
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1895/problem/A
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
    int x, y, k;
    cin >> x >> y >> k;
    if (y <= x) {
      cout << x << '\n';
      continue;
    }
    int d = y - x;
    int res = 0;
    x += min(k, d);
    res += y;
    res += y - x;
    cout << res << '\n';
  }
  return 0;
}
