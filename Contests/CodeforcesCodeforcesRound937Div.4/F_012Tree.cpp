/**
 * Author: C0ldSmi1e
 * Created Time: 03/28/2024 08:23:31 AM
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1950/problem/F
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
    int a, b, c;
    cin >> a >> b >> c;
    if (a + 1 != c) {
      cout << "-1\n";
      continue;
    }
    if (a == 0) {
      cout << b << '\n';
      continue;
    }
    int depth = 32 - __builtin_clz(a);
    int tot = 1 << depth;
    int t = tot - a - 1;
    debug(a, depth, tot, t);
    b = max(0, b - t);
    depth += b / c + (int) (b % c > 0);
    cout << depth << '\n';
  }
  return 0;
}
